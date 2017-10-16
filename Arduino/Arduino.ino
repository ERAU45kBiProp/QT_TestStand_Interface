double x = 0;
char incomingChar;
int incomingInt;
const byte purgeOutput = 2;
const byte loxPressOutput = 3;
const byte loxVentOutput = 4;
const byte injectorChillOutput = 5;
const byte loxMainOutput = 6;
const byte fuelPressOutput = 7;
const byte fuelPreStageOutput = 8;
const byte fuelMainOutput = 9;


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(purgeOutput,OUTPUT);
pinMode(loxPressOutput,OUTPUT);
pinMode(loxVentOutput,OUTPUT);
pinMode(injectorChillOutput,OUTPUT);
pinMode(loxMainOutput,OUTPUT);
pinMode(fuelPressOutput,OUTPUT);
pinMode(fuelPreStageOutput,OUTPUT);
pinMode(fuelMainOutput,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() > 0) {
  incomingInt = Serial.read();
  //incomingInt = incomingChar - '0';
  switch(incomingInt)
  {
    case 65: //Engine Purge Open
    digitalWrite(purgeOutput,HIGH);
    break;
    case 90: //Engine Purge 
    digitalWrite(purgeOutput,LOW);
    break;
    case 83: //LOX Press Open
    digitalWrite(loxPressOutput,HIGH);
    break;
    case 88: //LOX Press Close
    digitalWrite(loxPressOutput,LOW);
    break;
    case 68: //LOX Vent Open
    digitalWrite(loxVentOutput,HIGH);
    break;
    case 67: //LOX Vent Close
    digitalWrite(loxVentOutput,LOW);
    break;
    case 70: //Injector Chill Open
    digitalWrite(injectorChillOutput,HIGH);
    break;
    case 86: //Injector Chill Close
    digitalWrite(injectorChillOutput,LOW);
    break;
    case 71: //LOX Main Open
    digitalWrite(loxMainOutput,HIGH);
    break;
    case 66: //LOX Main Close
    digitalWrite(loxMainOutput,LOW);
    break;
    case 72: //Fuel Press Open
    digitalWrite(fuelPressOutput,HIGH);
    break;
    case 78: //Fuel Press Close
    digitalWrite(fuelPressOutput,LOW);
    break;
    case 74: //Fuel Pre-Stage Open
    digitalWrite(fuelPreStageOutput,HIGH);
    break;
    case 77: //Fuel Pre-Stage Close
    digitalWrite(fuelPreStageOutput,LOW);
    break;
    case 75: //Fuel Main Open
    digitalWrite(fuelMainOutput,HIGH);
    break;
    case 44: //Fuel Main Close
    digitalWrite(fuelMainOutput,LOW);
    break;
    case 56: //Prop Flow Inhibit On
    case 57: //Prop Flow Inhibit Off
    case 45: //Pre-Stage
    case 61: //Main Stage
    case 91: //Shutdown
    case 93: //Purge
    default:
      break;
  }
}
Serial.print(x);
x++;
if (x == 100) {
  x = 0;
}
Serial.print(",");
Serial.flush();
delay(100);

}


