#include<SoftwareSerial.h>
SoftwareSerial soft = SoftwareSerial(9,8);
String ssid = "iot"; 
String password = "project1234";//yathi1234
String apikey = "J93H6FBE70OBLWDI";
String TCP = "TCP";
String IP = "184.106.153.149";
String port = "80";
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
soft.begin(115200);
pinMode(2, INPUT);
}
void showresponse(int waitTime){
    long t=millis();
    char c;
    while (t+waitTime>millis()){
      if (soft.available()){
        c=soft.read();
        Serial.print(c);
      }
    }                 
}
void wifiinit(void)
{
    //soft.println("AT+RST");
    //showresponse(10000);
    soft.println("AT+CWMODE=3\r\n");
    showresponse(10000);
    soft.println("AT+CWJAP=\""+ssid+"\",\""+password+"\"\r\n");
    showresponse(10000);
}
void thingspeak(unsigned int x)
{
   soft.println("AT+CIPMODE=0\r\n");
   showresponse(10000);
   soft.println("AT+CIPMUX=0\r\n");
   showresponse(10000);
   String cmd = "AT+CIPSTART=\"TCP\",\"";                  // TCP connection
  cmd += "184.106.153.149";                               // api.thingspeak.com
  cmd += "\",80\r\n\r\n";

  soft.println(cmd);
   if(soft.find("Error"))
   {
      Serial.println("AT+CIPSTART error");
   }
   else
   {
      Serial.println("AT+CIPSTART success");
   }
  String getStr = "GET https://api.thingspeak.com/update?api_key=";   // prepare GET string
  getStr += apikey;
  getStr +="&field1=";
  getStr += x;
  
  getStr += "\r\n";

  cmd = "AT+CIPSEND=";
  cmd += String(getStr.length());
  //cmd += "\r\n\r\n";
  soft.println(cmd);
  //showresponse(10000);
  if(soft.find(">")){
    soft.print(getStr);
  }
  else{
    soft.println("AT+CIPCLOSE\r\n");
    Serial.println("AT+CIPCLOSE");
  }
}
void loop() 
{
  int x = 1;
 if(x == 1)
 {
    wifiinit();
    thingspeak(1);
 }
 else
  {
    wifiinit();
    thingspeak(0);
  }
}
