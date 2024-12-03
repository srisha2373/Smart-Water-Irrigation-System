#include <DHT.h>
#include <DHT_U.h>
#include <dht11esp8266.h>


void setup() {
  // put your setup code here, to run once:
pinMode(A1,INPUT);
pinMode(D2,INPUT);
Serial.begin(9600);
pinMode(D3,OUTPUT);
pinMode(D4,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
float A=analogRead(A1);
float B=analogRead(D2);
float X=(A/1023)*100;
float Y=(B/1023)*100;
Serial.println("sm 1");
delay(1000);
Serial.println(X);
delay(1000);
Serial.println("sm 2");
delay(1000);
Serial.println(Y);
delay(1000);
if(X>45.00)
{
digitalWrite(2,HIGH);
}
else {
digitalWrite(2,LOW);
}
if(Y>45.00)
{
  digitalWrite(3,HIGH);
}
else {
digitalWrite(3,LOW);
}
 lcd.setCursor(2,0);
  lcd.print("CANARA");
  lcd.setCursor(2,1);
  lcd.print("AIML DEPARTMENT");
  delay(1000);


}
