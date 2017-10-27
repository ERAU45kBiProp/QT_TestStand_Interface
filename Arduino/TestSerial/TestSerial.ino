#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3);
int incomingInt = 0;
long timer = 0;
int timeDelay = 20;
void setup() {
  mySerial.begin(19200);
  Serial.begin(9600);
  Serial.println("Starting...");

}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (mySerial.available()) {
    incomingInt = mySerial.read();
    Serial.println(incomingInt);
  }
  if ((millis() - timer) > timeDelay){
  timer = millis();
  if (!mySerial.available()){
  mySerial.write(0x13);
  mySerial.write(0x44);
  mySerial.write(0x11);
  //mySerial.write(0x13);
  //mySerial.write(0x0A);
  //digitalWrite(RS485_DIR_PIN,LOW);
  }
  }
}
