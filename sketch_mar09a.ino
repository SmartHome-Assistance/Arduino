#include <Wire.h>

int LEDpin = 13;

void setup() {
  Wire.begin(0x8);

  pinMode(LEDpin, OUTPUT);
  digitalWrite(LEDpin, LOW);
}

void receiveEvent(int howMany){
  while(Wire.available()) {
       char c = Wire.read();
       digitalWrite(LEDpin, c);
    } 
    
}

void loop() {
  Wire.onReceive(receiveEvent);
  delay(100);
}
