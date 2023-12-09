#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const int sensorPin = A1;    // Pin analog untuk sensor KY-038
const int ledPin = 7;      // Pin digital untuk LED
const int threshold = 512;  // Ambang batas untuk menghidupkan/mematikan LED

bool isSoundDetected = false;  // Variabel untuk melacak deteksi suara
unsigned long lastSoundTime = 0;  // Waktu terakhir deteksi suara

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.setBacklight(HIGH);
  lcd.clear();
  delay(2000);
}

void loop() {
  int sensorValue = analogRead(sensorPin);  // Membaca nilai analog dari sensor
  Serial.println(sensorValue);              // Menampilkan nilai sensor di Serial Monitor
  lcd.setCursor(0, 0);
  lcd.println(sensorValue);
  if (sensorValue > threshold) {
    if (!isSoundDetected) {
      isSoundDetected = true;
      lastSoundTime = millis();  // Menyimpan waktu terakhir deteksi suara
      Serial.println("=> lampu hidup");
      lcd.setCursor(0, 1);
    }
    digitalWrite(ledPin, !digitalRead(ledPin));// Menghidupkan/mematikan LED saat suara terdeteksi
  } else {
    if (isSoundDetected && (millis() - lastSoundTime >= 2000)) {
      isSoundDetected = false;
    }  
  }
  delay(200);
}