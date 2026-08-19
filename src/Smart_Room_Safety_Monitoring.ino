#include <DHT.h>

// ---------------- Pins Configuration ----------------
const int gasPin = A0;

// DHT22 Transducer Configuration
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// Ultrasonic Proximity Module Pins
const int trigPin = 9;
const int echoPin = 10;

// Status Sign LEDs Pin Allocation
const int greenLED = 3;
const int yellowLED = 4;
const int redLED = 5;

// Audio Alarm Pin
const int buzzer = 6;

// ----------------------------------------------------

void setup()
{
  Serial.begin(9600);
  dht.begin();

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.println("Smart Safety Monitoring System Initialized.");
}

void loop()
{
  // 1. Capture Gas Level Data
  int gasValue = analogRead(gasPin);

  // 2. Capture Climate Metrics via DHT22
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  bool dhtError = false;

  if (isnan(temperature) || isnan(humidity))
  {
    dhtError = true;
  }

  // 3. Calculate Distance via Proximity Sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.0343 / 2.0;

  // 4. Print Current Readings
  Serial.print("Gas: ");
  Serial.print(gasValue);

  if (dhtError)
  {
    Serial.print(" | Temperature: ERROR | Humidity: ERROR");
  }
  else
  {
    Serial.print(" | Temp: ");
    Serial.print(temperature);
    Serial.print(" C");

    Serial.print(" | Humidity: ");
    Serial.print(humidity);
    Serial.print(" %");
  }

  Serial.print(" | Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // 5. Clear Output Channels
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  noTone(buzzer);

  // 6. Safety Status Check

  // Gas Leakage
  if (gasValue > 450)
  {
    digitalWrite(redLED, HIGH);
    tone(buzzer, 1000);

    Serial.println("STATUS : GAS LEAK DETECTED");
  }

  // High Temperature
  else if (!dhtError && temperature > 35)
  {
    digitalWrite(yellowLED, HIGH);
    tone(buzzer, 800);

    Serial.println("STATUS : HIGH TEMPERATURE");
  }

  // Proximity Detection
  else if (distance < 15)
  {
    digitalWrite(redLED, HIGH);
    tone(buzzer, 1200);

    Serial.println("STATUS : OBJECT DETECTED");
  }

  // Normal Condition
  else
  {
    digitalWrite(greenLED, HIGH);
    noTone(buzzer);

    Serial.println("STATUS : SAFE");
  }

  Serial.println("--------------------------------------");

  delay(1000);
}
