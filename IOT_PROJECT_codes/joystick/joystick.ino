int f=0;
int b=0;
int l=0;
int r=0;
void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
f=digitalRead(2);
b=digitalRead(3);
l=digitalRead(4);
r=digitalRead(5);
if(f==1)
{
  Serial.println("forward");
  digitalWrite(10,HIGH);
  delay(3000);
}
else {
 Serial.println("button is not pressed");
 digitalWrite(10,LOW);
}
if(b==1)
{
  Serial.println("backward");
   digitalWrite(11,HIGH);
   delay(3000);
}
else {
 Serial.println("button is not pressed");
 digitalWrite(11,LOW);
}
if(l==1)
{
  Serial.println("left");
   digitalWrite(12,HIGH);
   delay(3000);
}
else {
 Serial.println("button is not pressed");
 digitalWrite(12,LOW);
}
if(r==1)
{
Serial.println("right");
 digitalWrite(13,HIGH);
 delay(3000);
}
else{
  Serial.println("button is not pressed");
 digitalWrite(13,LOW);
}
}
