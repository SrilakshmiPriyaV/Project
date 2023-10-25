#include <Ultrasonic.h>

int trigPin=13;
int echoPin=12;// Trig pin (13), Echo pin (12)
int buzzerPin = 8; // Change this to the actual buzzer pin
int sludgeLevelThreshold = 4; // Threshold distance in centimeters
long duration, distance;
void setup() {
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  delay(100); // Delay to stabilize readings
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration/58.2; //conversion for centimeters
  Serial.println(distance); //in centimeters
  Serial.println(" cm");

  if (distance < sludgeLevelThreshold) {
    Serial.println("Sludge level high!");
    soundBuzzer();
  }
}

void soundBuzzer() {
  // Generate a tone on the buzzer
  tone(buzzerPin, 1000, 1000); // 1000 Hz for 1 second (1000 milliseconds)
  delay(1000); // Pause for 1 second

  // Stop the tone
  noTone(buzzerPin);
}


