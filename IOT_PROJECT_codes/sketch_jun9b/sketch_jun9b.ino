void setup() {
  // put your setup code here, to run once:
pinMode(2,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2,LOW);
  delay(2000);
  digitalWrite(2,HIGH);
  delay(2000);
  digitalWrite(10,LOW);
  delay(2000);
  digitalWrite(10,HIGH);
  delay(2000);
  digitalWrite(11,LOW);
  delay(2000);
  digitalWrite(11,HIGH);
  delay(2000);
  digitalWrite(12,LOW);
  delay(2000);
  digitalWrite(12,HIGH);
  delay(2000);
}
