
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,INPUT);
}

void loop() {
 digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
int a=digitalRead(10);
Serial.println(a);
  if(a==0)
  {
   digitalWrite(4,LOW);
   delay(5000);
   digitalWrite(4,HIGH);
   digitalWrite(5,LOW);
   delay(1200);
   digitalWrite(5,HIGH);
   digitalWrite(6,LOW);
   delay(700);
   digitalWrite(6,HIGH);
   digitalWrite(9,LOW);
   delay(3000);
   digitalWrite(9,HIGH);
   digitalWrite(7,LOW);
   delay(25000);
   digitalWrite(7,HIGH);
   digitalWrite(4,LOW);
   delay(3000);
   digitalWrite(4,HIGH);
   digitalWrite(9,LOW);
   delay(3000);
   digitalWrite(9,HIGH);
   digitalWrite(8,LOW);
   delay(15000);
   digitalWrite(8,HIGH);
  }
}

