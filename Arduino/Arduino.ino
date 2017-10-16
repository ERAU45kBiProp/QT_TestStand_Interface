double x = 0;
int incomingByte = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(2,OUTPUT);
digitalWrite(2,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() > 0) {
           // read the incoming byte:
           incomingByte = Serial.read();

           // say what you got:
           digitalWrite(2,LOW);
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


