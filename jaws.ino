const int trigPin = 8;
const int echoPin = 7;
const int ledPin = 4;
const int led2Pin = 5;
const int buzzPin = 3;

long duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, LOW);
  digitalWrite(led2Pin, LOW);
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
   
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
   
  //Calculate the distance (in cm) based on the speed of sound.
  distance = duration/58.2;
  
  if (distance < 3000) {
    Serial.print(distance);
    Serial.println(" cm");
    digitalWrite(ledPin, HIGH);
    digitalWrite(led2Pin, HIGH);
    tone(buzzPin, 82, 100);
    delay(10 * distance);
    digitalWrite(ledPin, LOW);
    digitalWrite(led2Pin, LOW);
    tone(buzzPin, 87, 100);
    delay(10 * distance);
  } else {
    delay(500); 
  }

}


