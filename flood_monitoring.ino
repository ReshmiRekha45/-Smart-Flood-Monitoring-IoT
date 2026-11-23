#include <WiFi.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const int trigPin = 5;
const int echoPin = 18;
const int redLed = 2;
const int buzzer = 4;

const int drainDepth = 100; 
const int dangerThreshold = 75; 

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi!");
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distanceToWater = duration * 0.034 / 2;
  
  int waterLevel = drainDepth - distanceToWater;
  if (waterLevel < 0) waterLevel = 0;

  Serial.print("Current Water Level: ");
  Serial.print(waterLevel);
  Serial.println(" cm");

  if (waterLevel >= dangerThreshold) {
    digitalWrite(redLed, HIGH);
    tone(buzzer, 1000);
    Serial.println("ALERT: Flood Risk!");
  } else {
    digitalWrite(redLed, LOW);
    noTone(buzzer);
    Serial.println("Status: Normal");
  }

  delay(2000);
}
