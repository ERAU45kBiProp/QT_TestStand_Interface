
char incomingChar;
int incomingInt;
#include <SoftwareSerial.h>
const byte purgeOutput = 5;
const byte loxPressOutput = 6;
const byte loxVentOutput = 7;
const byte injectorChillOutput = 8;
const byte loxMainOutput = 9;
const byte fuelPressOutput = 10;
const byte fuelPreStageOutput = 11;
const byte fuelMainOutput = 12;

const int PT1 = A0;
const int PT2 = A1;
const int PT3 = A2;
const int PT4 = A3;
const int timeDelay = 7;

const int TX_ENABLE = 4;

boolean propFlowInhibit = true;
boolean preStageFlag = false;
boolean mainStageFlag = false;
boolean shutdownFlag = false;
boolean purgeFlag = false;
boolean operatingFlag = false;


long timer1 = 0;
long timer2 = 0;
long timer3 = 0;
float timerValue = 0;

int pressValue1 = 0;
int pressValue2 = 0;
int pressValue3 = 0;
int pressValue4 = 0;

int tempValue1 = 0;
int tempValue2 = 0;

SoftwareSerial mySerial(2,3);
void setup() {
  mySerial.begin(115200);
  Serial.begin(9600);
  Serial.println("Starting...");

  pinMode(TX_ENABLE, OUTPUT);
  pinMode(purgeOutput, OUTPUT);
  pinMode(loxPressOutput, OUTPUT);
  pinMode(loxVentOutput, OUTPUT);
  pinMode(injectorChillOutput, OUTPUT);
  pinMode(loxMainOutput, OUTPUT);
  pinMode(fuelPressOutput, OUTPUT);
  pinMode(fuelPreStageOutput, OUTPUT);
  pinMode(fuelMainOutput, OUTPUT);

  digitalWrite(TX_ENABLE, LOW);
  digitalWrite(purgeOutput, HIGH);
  digitalWrite(loxPressOutput, HIGH);
  digitalWrite(loxVentOutput, HIGH);
  digitalWrite(injectorChillOutput, HIGH);
  digitalWrite(loxMainOutput, HIGH);
  digitalWrite(fuelPressOutput, HIGH);
  digitalWrite(fuelPreStageOutput, HIGH);
  digitalWrite(fuelMainOutput, HIGH);
  while(!mySerial);
  }


void loop() {
  // put your main code here, to run repeatedly:
  if (mySerial.available()) {
    incomingInt = mySerial.read();
    //incomingInt = incomingChar - '0';
    Serial.println(incomingInt);
    if (!operatingFlag) {
      switch (incomingInt)
      {
        case 65: //Engine Purge Open
          digitalWrite(purgeOutput, LOW);
          break;
        case 90: //Engine Purge Close
          digitalWrite(purgeOutput, HIGH);
          break;
        case 83: //LOX Press Open
          digitalWrite(loxPressOutput, LOW);
          break;
        case 88: //LOX Press Close
          digitalWrite(loxPressOutput, HIGH);
          break;
        case 68: //LOX Vent Open
          digitalWrite(loxVentOutput, LOW);
          break;
        case 67: //LOX Vent Close
          digitalWrite(loxVentOutput, HIGH);
          break;
        case 70: //Injector Chill Open
          if (!propFlowInhibit) {
            digitalWrite(injectorChillOutput, LOW);
          }
          break;
        case 86: //Injector Chill Close
          digitalWrite(injectorChillOutput, HIGH);
          break;
        case 71: //LOX Main Open
          if (!propFlowInhibit) {
            digitalWrite(loxMainOutput, LOW);
          }
          break;
        case 66: //LOX Main Close
          digitalWrite(loxMainOutput, HIGH);
          break;
        case 72: //Fuel Press Open
          digitalWrite(fuelPressOutput, LOW);
          break;
        case 78: //Fuel Press Close
          digitalWrite(fuelPressOutput, HIGH);
          break;
        case 74: //Fuel Pre-Stage Open
          if (!propFlowInhibit) {
            digitalWrite(fuelPreStageOutput, LOW);
          }
          break;
        case 77: //Fuel Pre-Stage Close
          digitalWrite(fuelPreStageOutput, HIGH);
          break;
        case 75: //Fuel Main Open
          if (!propFlowInhibit) {
            digitalWrite(fuelMainOutput, LOW);
          }
          break;
        case 44: //Fuel Main Close
          digitalWrite(fuelMainOutput, HIGH);
          break;
        case 56: //Prop Flow Inhibit On
          propFlowInhibit = true;
          break;
        case 57: //Prop Flow Inhibit Off
          propFlowInhibit = false;
          break;
        case 45: //Pre-Stage
          preStageFlag = true;
          digitalWrite(injectorChillOutput, LOW);
          timer1 = millis();
          break;
        case 61: //Main Stage
          mainStageFlag = true;
          preStageFlag = false;
          digitalWrite(loxMainOutput, LOW);
          timer1 = millis();
          break;

        case 91: //Shutdown
          shutdownFlag = true;
          digitalWrite(loxMainOutput, HIGH);
          digitalWrite(fuelMainOutput, HIGH);
          digitalWrite(fuelPreStageOutput, HIGH);
          timer1 = millis();
          break;
        case 93: //Purge
          purgeFlag = true;
          digitalWrite(purgeOutput, LOW);
          timer1 = millis();
          break;
        case 82: //Record start
          timer2 = millis();
          break;
        default:
          Serial.print("unrecognized command");
          break;
      }
    }
    mySerial.flush();
  }

  if (preStageFlag) {
    if ((millis() - timer1) > 500) {
      digitalWrite(fuelPreStageOutput, LOW);
      preStageFlag = false;
      operatingFlag = false;
    }
  }

  if (mainStageFlag) {
    if ((millis() - timer1) > 500) {
      digitalWrite(fuelMainOutput, LOW);
      mainStageFlag = false;
      operatingFlag = false;
    }
  }

  if (shutdownFlag) {
    if ((millis() - timer1) > 500 && (millis() - timer1) < 1000) {
      digitalWrite(injectorChillOutput, HIGH);
    }
    if ((millis() - timer1) > 1000 && (millis() - timer1) < 2000) {
      digitalWrite(purgeOutput, LOW);
    }
    if ((millis() - timer1) > 2000) {
      digitalWrite(purgeOutput, HIGH);
      shutdownFlag = false;
      operatingFlag = false;
    }
  }

  if (purgeFlag) {
    if ((millis() - timer1) > 1000) {
      digitalWrite(purgeOutput, HIGH);
      purgeFlag = false;
      operatingFlag = false;
    }
  }

  //pressValue1 = float(analogRead(PT1))*5/1024*124.724 - 58.461;
  pressValue1 = analogRead(PT1);
  //pressValue2 = float(analogRead(PT2))*5/1024;
  pressValue2 = analogRead(PT2);
  //pressValue3 = float(analogRead(PT3))*5/1024*124.724 - 58.461;
  pressValue3 = analogRead(PT3);
  //pressValue4 = float(analogRead(PT4))*5/1024;
  pressValue4 = analogRead(PT4);
  
  if (((millis() - timer3) > timeDelay) && !mySerial.available() ){
    mySerial.flush();
  digitalWrite(TX_ENABLE,HIGH);
  mySerial.write(0x13);
  mySerial.write(0x44);
  timer3 = millis();
  if (timer3 < 10){
    mySerial.print("0");
  }
  if (timer3 < 100){
    mySerial.print("0");
  }
  if (timer3 < 1000){
    mySerial.print("0");
  }
  if (timer3 < 10000){
    mySerial.print("0");
  }
  if (timer3 < 100000){
    mySerial.print("0");
  }
  if (timer3 < 1000000){
    mySerial.print("0");
  }
  if (timer3 < 10000000){
    mySerial.print("0");
  }
  if (timer3 < 100000000){
    mySerial.print("0");
  }
 
  mySerial.print(timer3);
  
  mySerial.print(",");
  //mySerial.write("-");
  if (pressValue1 < 10) {
    mySerial.print("000");
  }
  else if (pressValue1 < 100) {
    mySerial.print("00");
  }
  else if (pressValue1 < 1000){
    mySerial.print("0");
  }
  mySerial.print(pressValue1);
  mySerial.print(",");
  if (pressValue2 < 10) {
    mySerial.print("000");
  }
  else if (pressValue2 < 100) {
    mySerial.print("00");
  }
  else if (pressValue2 < 1000){
    mySerial.print("0");
  }
  mySerial.print(pressValue2);
  
  //mySerial.write("-");
  mySerial.print(",");
  //mySerial.write("-");
  if (pressValue3 < 10) {
    mySerial.print("000");
  }
  else if (pressValue3 < 100) {
    mySerial.print("00");
  }
  else if (pressValue3 < 1000){
    mySerial.print("0");
  }
  mySerial.print(pressValue3);
  mySerial.print(",");
  if (pressValue4 < 10) {
    mySerial.print("000");
  }
  else if (pressValue4 < 100) {
    mySerial.print("00");
  }
  else if (pressValue4 < 1000){
    mySerial.print("0");
  }
  mySerial.print(pressValue4);
  mySerial.flush();
  mySerial.write(0x11);
  digitalWrite(TX_ENABLE,LOW);
  
  }
}


