#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int potPin = A0;

void setup() {
  lcd.init();
  lcd.setBacklight(HIGH);
  lcd.clear();
}

void loop(){
  int scrollSpeed = analogRead (potPin);
  scrollSpeed = map(scrollSpeed, 0, 1023, 100, 1000);
  
  lcd.setCursor(0,0);
  lcd.print ("SIMANOSOR");
  lcd.setCursor(0,1);
  lcd.print ("HEBAT");
  
  for(int i = 0; i<16; i++){
    lcd.scrollDisplayLeft();
    delay(scrollSpeed);
  }
}