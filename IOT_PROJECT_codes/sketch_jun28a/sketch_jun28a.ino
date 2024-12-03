#include <Adafruit_SSD1306.h>
#include <splash.h>

#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>

#include <Keypad.h>
#define SCREEN_WIDTH 128 // OLED display width,  in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// declare an SSD1306 display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const byte ROWS = 4; 
const byte COLS = 4; 
int i;
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup()
{
  Serial.begin(9600);
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }
delay(500); // wait for initializing
pinMode(13,OUTPUT);
pinMode(A0,INPUT);
oled.clearDisplay();
oled.setCursor(0,0);
}

  
void loop()
{
  char n = customKeypad.getKey();
  oled.setTextSize(3);          // text size
oled.setTextColor(WHITE);     // text color
oled.setCursor(0,10);
if(n)
{        // position to display
oled.println(n);  
}
oled.display();
oled.setTextSize(3);          // text size
oled.setTextColor(WHITE);     // text color
oled.setCursor(0,10);
int b=int(n);
Serial.println(b);
int c=b-48;
for(i=1;i<=c;i++)
{
int a=analogRead(A0);
if(a>20)
{
oled.clearDisplay();
Serial.println("a=");
Serial.println(a);
delay(5000);
Serial.println("i=");
Serial.println(i);
oled.setTextSize(3);          // text size
oled.setTextColor(WHITE);     // text color
oled.setCursor(0,10);
oled.println(i);
oled.display();
if(i==c)
{
  digitalWrite(13,HIGH);
  delay(10000);
  digitalWrite(13,LOW);
  oled.clearDisplay();
}
oled.display();
oled.clearDisplay();
}
else
{
  i=i-1;
}
}
oled.display();
oled.clearDisplay();
}