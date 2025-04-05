//slave

#include <Wire.h>
#define no_of_bytes_stored 2048
#define SLAVE_ADDRESS 2
#define DATA_SIZE 2048 //1984 CHANGED
#define CHUNK_SIZE 32
#define HANDSHAKE_REQUEST 0x01
#define HANDSHAKE_ACK 0x06
#define READ_COMPLETE_ACK 0x09 //CHANGED
//CHANGED


volatile uint8_t byte_at_address;
volatile bool return_ack;
volatile bool handshake_completed;
volatile byte sram_array[no_of_bytes_stored]; // Buffer holding 2048 bytes of data
volatile int index = 0; // Current index to keep track of data to send
volatile uint16_t address;  //CHANGED
uint16_t START_ADDRESS;//CHANGED 

// Handle received data (handshake request)
void receiveEvent(int bytes) {
  if (Wire.available()) {
    int request = Wire.read();
    if (request == HANDSHAKE_REQUEST) {
      return_ack = true;
    }
    if(request == READ_COMPLETE_ACK){ //CHANGED
      index = 0; // Reset index after all data is sent
      address = START_ADDRESS; //Reset address after all data is sent
      handshake_completed = false;
    }
  }
}

// Send requested data to master in chunks
void requestEvent() {
  if (return_ack){
     Wire.write(HANDSHAKE_ACK);
     handshake_completed = true;
     return_ack = false;
     return;
  }


  if (handshake_completed){
    for (int i = 0; i < CHUNK_SIZE; i++) {
      if (address < 0xAFF) { //CHANGED
        byte_at_address = *(byte *)address;
        Wire.write(byte_at_address); // Send the next byte
        address++;
        index++;
      } else {
        Wire.write(0x00); //CHANGED
      }
    }
  }
}

void setup() {
  //Fill data buffer with example data
  for (int i = 0; i < no_of_bytes_stored; i++){
    sram_array[i] = 0x55 + i%4; //0101 * length //TEMP CHANGE
  }
  START_ADDRESS = &sram_array[0]; //CHANGED

  address = START_ADDRESS; //set start address for first run //CHANGED
  index = 0; //start index for first run
  return_ack= false; //no handshake done at first
  handshake_completed = false;

  Wire.begin(SLAVE_ADDRESS); // Start I2C as slave
  Wire.onReceive(receiveEvent); // Register receive event handler
  Wire.onRequest(requestEvent); // Register request event handler

}

void loop() {
  // Nothing needed in the loop; actions are event-driven
}



