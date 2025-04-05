//master

#include <Wire.h>

#define SLAVE1_ADDRESS 1
#define SLAVE2_ADDRESS 2

#define DATA_SIZE 2048 //CHANGED
#define ARRAY_SIZE 204 //CHANGED  
#define CHUNK_SIZE 32

#define HANDSHAKE_REQUEST 0x01
#define HANDSHAKE_ACK 0x06
#define READ_COMPLETE_ACK 0x09
#define TIMEOUT_MS 4000 //CHANGED, *only read_sram() is changed apart from the constants

#define SCL_PIN SCL
#define SDA_PIN SDA

#define PCYCLE_PIN1 6 //to switch on devices, set to low, to switch off set to high
#define PCYCLE_PIN2 7
#define TRIGGER_PIN 8 //active low
#define LOW_PIN 9

#define DEBUG 1

//read result outcomes
#define READ_COMPLETE 1
#define TIMEOUT 2

int clear_bus_counter;
int handshake1;
int handshake2;
int error_count1;
int error_count2;
int read_result1;
int read_result2;
volatile uint8_t slave1_SRAM[ARRAY_SIZE];
volatile uint8_t slave2_SRAM[ARRAY_SIZE];
bool atmega1_on = 1;
bool atmega2_on = 1;


void clear_bus() { 
  pinMode(SCL_PIN, INPUT_PULLUP);
  pinMode(SDA_PIN, INPUT_PULLUP);

  if (digitalRead(SDA_PIN) == LOW) { // Check if SDA is held low
    #ifdef DEBUG
      Serial.println("Bus lockup detected. Clearing...");
    #endif

    for (int i = 0; i < 9; i++) { // Toggle SCL to clear lockup
      pinMode(SCL_PIN, OUTPUT);
      digitalWrite(SCL_PIN, HIGH);
      delayMicroseconds(5);
      digitalWrite(SCL_PIN, LOW);
      delayMicroseconds(5);
    }

    // Release SCL and SDA lines after toggling
    pinMode(SCL_PIN, INPUT_PULLUP);
    pinMode(SDA_PIN, INPUT_PULLUP);

    Wire.begin();

    // Delay before resuming to allow the bus to stabilize
    delay(1000);
  }
  #ifdef DEBUG
    Serial.println("Bus clearing was attempted");
  #endif
}

void power_cycle(){
  #ifdef DEBUG
    Serial.println("Power Cycling Now");
  #endif
  digitalWrite(PCYCLE_PIN1, HIGH);
  digitalWrite(PCYCLE_PIN2, HIGH);
  delay(1000);
  if (atmega1_on){
    digitalWrite(PCYCLE_PIN1, LOW);
  }
  if (atmega2_on){
    digitalWrite(PCYCLE_PIN2, LOW);
  }
  delay(1000);
  #ifdef DEBUG
    Serial.println("Power Cycling Complete");
  #endif
}

bool perform_handshake(int slave_address) {
  unsigned long startTime = millis();

  Wire.beginTransmission(slave_address);
  Wire.write(HANDSHAKE_REQUEST); // Send handshake request
  Wire.endTransmission();
  Wire.requestFrom(slave_address, 1); // Request 1 byte for handshake acknowledgment
  delay(100);

  // Wait for acknowledgment within timeout
  while (millis() - startTime < TIMEOUT_MS) {
    if(Wire.available()){
     
      int ack = Wire.read();
   
      if (ack == HANDSHAKE_ACK) {
        return true; // Handshake successful
      }
    }
    delay(10); // Small delay before retrying
  }
  #ifdef DEBUG
    Serial.println("Handshake failed");
  #endif
  return false; // Handshake failed
}

void pretty_print(uint8_t c, int bytes_received){
  if (bytes_received%64==0){Serial.println();}
  if (c<16){Serial.print(0);}
  Serial.print(c, HEX); // Print each received byte to Serial Monitor
  Serial.print(" ");
  
}

int byte_error_counter(uint8_t c, int bytes_received){
  int err_count = 0;
  uint8_t reference_array[] = {0x55, 0x56, 0x57, 0x58};
  uint8_t reference_byte = reference_array[bytes_received%4];
  uint8_t mask = 0x01;
  //do a bitwise xor of reference with c. -> the matching bit locations will be zero, the unmatched locations = 1, count the number of 1's in the byte
  uint8_t xored_byte = reference_byte ^ c; //8'b 0100 1000
  for (int i = 0; i<8; i++){
    if ((xored_byte & mask) == 1) {err_count++;} 
    xored_byte = xored_byte >> 1;
  }
  return err_count;
}

void printer_read_sram(long int time_taken, int total_error_count){
  Serial.println();
  Serial.print("Time taken for 1 SRAM dump, to compare and store ");
  Serial.print(time_taken);
  Serial.println(" ms");
  Serial.println("\nData reception complete.");
  Serial.print("Error Count: ");
  Serial.println(total_error_count);
  Serial.print("Now printing stores 10% array");
  for (int i=0; i<ARRAY_SIZE; i++){
    if (i%64 == 0){Serial.println();}
    Serial.print(slave1_SRAM[i], HEX);
    Serial.print(" ");
  }
  Serial.println();

}

int read_sram(int slave_address){
  //read from slave and append every 10th byte to array_slave + print on screen
  int bytes_received = 0;
  int slave_array_index = 0;
  int total_error_count = 0;
  int byte_error_count= 0;

  long int start_time = millis(); //CHANGED

  while ((bytes_received < DATA_SIZE) && (millis()-start_time <TIMEOUT_MS)){ //CHANGED , consider changing to DATA_SIZE - CHUNK SIZE + 1
    Wire.requestFrom(slave_address, CHUNK_SIZE); // Request CHUNK_SIZE bytes//keep requesting in chunks of 32 from slave.
  
    while (Wire.available()) { //CHANGED
      uint8_t c = Wire.read(); // Read a byte
      #ifdef DEBUG
        pretty_print(c, bytes_received); //print it
      #endif
      
      //CHANGED
      byte_error_count = byte_error_counter(c, bytes_received); //count number of errors
      total_error_count = total_error_count + byte_error_count; //increment error count

      if ((bytes_received%10 == 0) && (slave_array_index < ARRAY_SIZE)){ //append to array
        if (slave_address == SLAVE1_ADDRESS){slave1_SRAM[slave_array_index] = c;}
        if (slave_address == SLAVE2_ADDRESS){slave2_SRAM[slave_array_index] = c;} 
        slave_array_index++;
      }

      bytes_received++;

      if (bytes_received >= DATA_SIZE) {
        Wire.beginTransmission(slave_address); //CHANGED
        Wire.write(READ_COMPLETE_ACK); // Send handshake request
        Wire.endTransmission();
        if (slave_address == SLAVE1_ADDRESS){error_count1 = total_error_count;} //set total error count
        if (slave_address == SLAVE2_ADDRESS){error_count2 = total_error_count;}
        #ifdef DEBUG
          printer_read_sram(millis()-start_time, total_error_count);
        #endif
        return READ_COMPLETE; //return
      }
    }
  }
  //else if timeout
  #ifdef DEBUG
    Serial.println();
    Serial.println("Timeout: Possible bus lockup detected.");
  #endif
  return TIMEOUT;
}


void setup() {
  Serial.begin(9600);
  Wire.begin(); // Start I2C as master
  pinMode(SCL_PIN, INPUT_PULLUP); //for open drain
  pinMode(SDA_PIN, INPUT_PULLUP); //for open drain

  pinMode(PCYCLE_PIN1, OUTPUT);
  digitalWrite(PCYCLE_PIN1, LOW); //set low to switch on the atmegas

  pinMode(PCYCLE_PIN2, OUTPUT);
  digitalWrite(PCYCLE_PIN2, LOW); //set low to switch on the atmegas

  pinMode(LOW_PIN, OUTPUT);
  digitalWrite(LOW_PIN, LOW); //set pin forever low 

  pinMode(TRIGGER_PIN, INPUT_PULLUP); //set pin high unless external drives it low.

  handshake1 = 0;
  handshake2 = 0;
  error_count1 = 0;
  error_count2 = 0;
  read_result1 = 0;
  read_result2 = 0;
  clear_bus_counter = 0;

} //setup end

void loop() {
  
  handshake1 = 0;
  handshake2 = 0;
  error_count1 = 0;
  error_count2 = 0;
  read_result1 = 0;
  read_result2 = 0;

  if (digitalRead(TRIGGER_PIN)){//no trigger do nothing
    #ifdef DEBUG
      Serial.println("Read Not Triggered");
    #endif
    clear_bus_counter = 0;
    delay(2000); //poll ever 100ms
  }

  else{ //triggered, time to get SRAM data
    unsigned long start_loop_time = millis();
    #ifdef DEBUG
      Serial.println("Reading the 2 SRAMs");
    #endif  

    #ifdef DEBUG
      Serial.println("Requesting Handshake from Slave 1");
    #endif
 
    handshake1 = perform_handshake(SLAVE1_ADDRESS); //handshake with slave 1

    if (handshake1){ //if handshake 1 is successful
      #ifdef DEBUG
        Serial.println("Handshake with Slave1 Successful");
        Serial.println("Reading SRAM of Slave 1");
      #endif
      read_result1 = read_sram(SLAVE1_ADDRESS); //read sram data
    }

    if ((!handshake1) || (read_result1 != READ_COMPLETE)){ //if no handshake or no read
      #ifdef DEBUG
        Serial.println("Need to clear the bus due to slave 1");
      #endif

      if (clear_bus_counter >= 1) { //1 clear bus failed
        clear_bus_counter = 0;
        power_cycle();
      }
      else{
        clear_bus();
        clear_bus_counter++;
      }
      //then just let the loop() just run again
    }

    else { //if read1 was done
      #ifdef DEBUG
        Serial.println("Requesting Handshake from Slave 2");
      #endif
 
      handshake2 = perform_handshake(SLAVE2_ADDRESS);//try handshake2  
      if (handshake2){ //read SRAM2 
        #ifdef DEBUG
          Serial.println("Handshake with Slave 2 Successful");
          Serial.println("Reading SRAM of Slave 2");
        #endif
        read_result2 = read_sram(SLAVE2_ADDRESS); //read sram data
      }

      if ((!handshake2) || (read_result2 != READ_COMPLETE)){ //if either handshake or read wasn't successful.
        #ifdef DEBUG
          Serial.print("Need to clear the bus due to slave 2");
        #endif

        if (clear_bus_counter >= 1) { //1 clear bus failed
          clear_bus_counter = 0;
          power_cycle();
        }
        else{
          clear_bus();
          clear_bus_counter++;
        }
      }

      else { //if read2 was successful
        #ifdef DEBUG
          Serial.print("Error count for SRAM1: ");
          Serial.println(error_count1);
          Serial.print("Error count for SRAM2: ");
          Serial.println(error_count2);
          Serial.println("Reading of 2 SRAMs successfully completed");
        #endif
      }
    }
    Serial.print("Time since read trigger is ");
    Serial.println(millis()-start_loop_time);
    delay(1000); // Wait before attempting SRAM read again
  }//trigger_else
} //loop end




