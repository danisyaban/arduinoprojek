#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
int pingPin = 8;

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() {
  long duration, inches, cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  pinMode(pingPin, HIGH);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  
  pinMode(pingPin, INPUT);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  duration = pulseIn(pingPin, HIGH);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(inches);
  lcd.print("in, ");
  lcd.setCursor(0,1);
  lcd.print(cm);
  lcd.print("cm");
  lcd.println();
  }
long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}