int sensorPin = A0; 
int ledPin1 = 12;
int sensorValue = 0;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);

  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  delay(sensorValue);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  delay(sensorValue);
}