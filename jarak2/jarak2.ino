#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int buzz = 5;
const int trigPin = 6;
const int echPin = 7;
int ledPin = 8;


void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() {
  pinMode(buzz, OUTPUT);
  pinMode(echPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  long duration, inches, cm;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  pinMode(trigPin, HIGH);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  duration = pulseIn(trigPin, HIGH);
  
  if(cm >= 60){
    analogWrite(buzz, 255);
  }
  else if (cm >= 40){
    analogWrite(buzz, 100);
  }
  else{
    analogWrite(buzz,LOW);
  }
  
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