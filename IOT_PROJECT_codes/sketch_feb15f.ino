void setup() {
  // put your setup code here, to run once:
pinMode(A3,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
float a=analogRead(A3);
float t=(a/717)*100;
Serial.println(t);
delay(2000);
}
