int a=0;
void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT);
pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
a=digitalRead(2);
if(a==1)
{
  Serial.println("button is pressed");
  digitalWrite(13,HIGH);
}
else{
  Serial.println("button is not pressed");
  digitalWrite(13,LOW);
}
}
