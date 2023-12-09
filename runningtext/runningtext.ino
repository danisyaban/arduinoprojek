#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
int potPin = A0;

void setup() {
  lcd.begin(16,2);
}

void loop() {
  int scrollSpeed = analogRead (potPin);
  scrollSpeed = map(scrollSpeed, 0, 1023, 100, 1000);
  
  lcd.setCursor(4,0);
  lcd.print ("AKU HITAM");
  lcd.setCursor(5,1);
  lcd.print ("BANGET");
  
  for(int i = 0; i<16; i++){
    lcd.scrollDisplayLeft();
    delay(scrollSpeed);
  }
}
