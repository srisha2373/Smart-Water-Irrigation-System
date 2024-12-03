#define sol1 7
#define sol2 13
#define pump 8
void setup() {
pinMode(A1,INPUT);
pinMode(A0,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
pinMode(sol1,OUTPUT);
pinMode(sol2,OUTPUT);
pinMode(pump,OUTPUT);

Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
float A=analogRead(A1);
float B=analogRead(A0);
float C=analogRead(A2);
float D=analogRead(A3);
float H=(A/1023)*100;
float I=(B/1023)*100;
float J=(C/700)*100;
float K=(D/700)*100;
Serial.println("Soil moisture 1:");
Serial.println(H);
Serial.println("Soil moisture 2:");
Serial.println(I);
Serial.println("Water level:");
Serial.println(J);
delay(1000);
if(H>=80)
{
  digitalWrite(sol1,LOW);
}
else
{
  digitalWrite(sol1,HIGH);
}
if(I>=80)
{
  digitalWrite(sol2,LOW);
}
else
{
  digitalWrite(sol2,HIGH);
}
if(J<=60)
{
  digitalWrite(pump,LOW);
}
else
{
  digitalWrite(pump,HIGH);
}
if(K<=60)
{
  Serial.println("Water level is low:");
  Serial.println(K);
  delay(2000);
}
else
{
 Serial.println("Water level is High:");
 Serial.println(K);
 delay(2000);
}

  // put your main code here, to run repeatedly:

}