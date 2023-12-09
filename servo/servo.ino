#include <Servo.h> 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
Servo servo1, servo2; 

#define coinDetector 12

int buttonState1, buttonState2;
int con = 0;
int buttonPressed;

void setup()

{

  servo1.attach(2);
  servo2.attach(3); 
  pinMode(10, INPUT);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  lcd.begin(16,2);
}

void loop()
{
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Masukan Koin!");
  lcd.setCursor(0, 1);
  lcd.print("Masukan Perlahan!");


	buttonState1 = digitalRead(8);
  buttonState2 = digitalRead(9);

 while (true) {
    if (digitalRead(coinDetector) == LOW) { // If a coin is detected, exit the from the while loop
      if (con == 1) {
        con = 0;
        break;
      }
    }
  }
  delay(10);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Silahkan Pilih");
  lcd.setCursor(0, 1);
  lcd.print(" 1, atau 2?");

while (true) {
    if (buttonState1 == HIGH){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You selected 1!");
      delay(2000);
      break;
    }
    if (buttonState2 == HIGH){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You selected 2!");
      delay(2000);
      break;
    }
  }
  set1:
  lcd.setCursor(0,0);
  lcd.print("Kamu Pilih");
  lcd.setCursor(0,1);
  lcd.print("Item 1");
  if(buttonState1 == LOW){
    servo1.write(0);
    delay(2000);
    servo1.write(180);
    delay(2000);
    goto set1;
  }  
  lcd.clear(); // Clears the display
  lcd.setCursor(0, 0);
  lcd.print("Item delivered!"); // Prints on the LCD
  delay(2000);
}