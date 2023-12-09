int redPin = 12;
int yellowPin = 11;
int greenPin = 10;


void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop()
{
  digitalWrite(redPin, HIGH);
  delay(12000);
  digitalWrite(redPin, LOW);
  delay(1000); 
  digitalWrite(yellowPin, HIGH);
  delay(5000); 
  digitalWrite(yellowPin, LOW);
  delay(1000);
  digitalWrite(greenPin, HIGH);
  delay(10000);
  digitalWrite(greenPin, LOW);
  delay(1000);
}