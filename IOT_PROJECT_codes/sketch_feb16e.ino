            // add librery
#include <ESP8266WiFi.h>

WiFiClient  client;
unsigned long counterChannelNumber = 2029925;                // Channel ID
const char * myCounterReadAPIKey = "N4583MT2KJX8UKA6";      // Read API Key
const int FieldNumber1 = 1;                                 // The field you wish to read
                                
const int LED1 = 0;


void setup()
{
  pinMode(LED1,OUTPUT);

  Serial.begin(115200);
  Serial.println();

  WiFi.begin("iot", "project123456");                       

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
}

void loop() 
{
 int A = ThingSpeak.readLongField(counterChannelNumber, FieldNumber1, myCounterReadAPIKey);
 Serial.println(A);

