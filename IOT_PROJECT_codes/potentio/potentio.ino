int a=0;
float b=0;
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
a= analogRead(A2);
//Serial.println(a);
b=(5/1023)*a;
Serial.println(b);
delay(2000);
}
