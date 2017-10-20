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

const int PT1 = A0;
const int PT2 = A1;
const int PT3 = A2;
const int PT4 = A3;


boolean propFlowInhibit = true;
boolean preStageFlag = false;
boolean mainStageFlag = false;
boolean shutdownFlag = false;
boolean purgeFlag = false;
boolean operatingFlag = false;
long timer1 = 0;

int pressValue1 = 0;
int pressValue2 = 0;
int pressValue3 = 0;
int pressValue4 = 0;

int tempValue1 = 0;
int tempValue2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  
  pinMode(purgeOutput, OUTPUT);
  pinMode(loxPressOutput, OUTPUT);
  pinMode(loxVentOutput, OUTPUT);
  pinMode(injectorChillOutput, OUTPUT);
  pinMode(loxMainOutput, OUTPUT);
  pinMode(fuelPressOutput, OUTPUT);
  pinMode(fuelPreStageOutput, OUTPUT);
  pinMode(fuelMainOutput, OUTPUT);

  digitalWrite(purgeOutput, HIGH);
  digitalWrite(loxPressOutput, HIGH);
  digitalWrite(loxVentOutput, HIGH);
  digitalWrite(injectorChillOutput, HIGH);
  digitalWrite(loxMainOutput, HIGH);
  digitalWrite(fuelPressOutput, HIGH);
  digitalWrite(fuelPreStageOutput, HIGH);
  digitalWrite(fuelMainOutput, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (Serial.available() > 0) {
    incomingInt = Serial.read();
    //incomingInt = incomingChar - '0';
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
        default:
          break;
      }
    }
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

  pressValue1 = analogRead(PT1);
  pressValue2 = analogRead(PT2);
  pressValue3 = analogRead(PT3);
  pressValue4 = analogRead(PT4);

  
  Serial.print(millis());
  Serial.print(",");
  Serial.print(pressValue1);
  Serial.print(",");
  Serial.print(pressValue2);
  Serial.print(",");
  Serial.print(pressValue3);
  Serial.print(",");
  Serial.print(pressValue4);
  Serial.print(",");
  Serial.print(tempValue1);
  Serial.print(",");
  Serial.println(tempValue2);
  Serial.flush();
  delay(100);
}


