---
title: "Appendix C: GM Tube Signal Detection Code"
nav_order: 6
permalink: /gmtube-code/
last_modified_date: 16-11-2024
---

# GM Tube Signal Detection Code

``` cpp
//Counting falling edges
volatile int count = 0;       
//Counter for 1 minute
uint32_t start = millis(); 

void setup() {
 //Setup serial communication for debugging
  Serial.begin(9600);     
  Serial.print("Start");
  
  //Input pin for signal line
  pinMode(2, INPUT);

  // Attach interrupt on pin 2 for signal detection
  attachInterrupt(digitalPinToInterrupt(2), handleInterrupt, FALLING);
}

void loop() {
  //Check if 1 second has passed
  if (millis() - start >= 60000) {
    Serial.print("Counts per minute: ");
    Serial.println(count);     

    //Reset count and start time for the next minute
    count = 0;                   
    start = millis();              
  }
}

//Interrupt Service Routine 
void handleInterrupt() {
   //Increment number of signals detected
  count++; 
}
```