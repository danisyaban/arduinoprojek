int sensorPin = A0; 
int ledPin1 = 11;
int ledPin2 = 9;
int sensorValue = 0;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for(int fadeValue=0;fadeValue<=255;fadeValue+= 5){
    analogWrite(ledPin1, fadeValue);
    analogWrite(ledPin2, (255-fadeValue));
    delay(10);
  }

    for(int fadeValue=255;fadeValue>=0;fadeValue-= 5){
    analogWrite(ledPin1, fadeValue);
    analogWrite(ledPin2, (255-fadeValue));
    delay(10);
  }
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  delay(sensorValue);

}