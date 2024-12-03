#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(2,0);
lcd.print("CANARA");
lcd.setCursor(2,1);
lcd.print("AIML DEPARTMENT");
delay(1000);
}
