void setup() {
  // put your setup code here, to run once:
for(int x = 2; x < 10; x++) {
  pinMode(x,OUTPUT);
}
}

void loop() {
  // put your main code here, to run repeatedly:
for(int x = 2; x < 10; x++) {
  digitalWrite(x,HIGH);
  delay(100);
}
for(int x = 2; x < 10; x++) {
  digitalWrite(x,LOW);
  delay(100);
}
}
