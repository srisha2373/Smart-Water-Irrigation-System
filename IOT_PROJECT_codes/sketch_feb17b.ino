#include <dht.h>

dht DHT;

#define DHT11_PIN 7

void setup(){
  Serial.begin(9600);
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(1000);
}{
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
Serial.println("Water level 1:");
Serial.println(J);
Serial.println("Water level 2:");
Serial.println(J);
delay(2000);
if(H>=80)
{
  digitalWrite(sol2,LOW);
}
else
{
  digitalWrite(sol2,HIGH);
}
if(I>=80)
{
  digitalWrite(sol1,LOW);
}
else
{
  digitalWrite(sol1,HIGH);
}
if(J<=55)
{
  digitalWrite(pump,LOW);
}
else
{
  digitalWrite(pump,HIGH);
}


  // put your main code here, to run repeatedly:

}