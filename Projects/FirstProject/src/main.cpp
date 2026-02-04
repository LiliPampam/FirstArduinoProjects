#include <Arduino.h>
#include <DHT.h>
#include <HCSR04.h>
#include <PIR.h>

// put function declarations here:
int myFunction(int, int);

void MeasureTemperatureAndHumidity();

void PIRSensorDetecting();

void MeasureDistance();


// Global variables
DHT dht11(10, DHT11);
int a = 10, b = 70;
PIR MovementSensorDetector;

UltraSonicDistanceSensor DistanceSensorHCSR04(7, 6);

void setup()
{
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  Serial.begin(9600);
  Serial.print("The result is: ");
  Serial.println(result);
  dht11.begin();
  MovementSensorDetector.add(9);
  Serial.println("Begin: ");
}

void loop()
{
  delay(100);
  MeasureTemperatureAndHumidity();
  MeasureDistance();
  PIRSensorDetecting();
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}

void MeasureTemperatureAndHumidity()
{
  float h = dht11.readHumidity();
  float t = dht11.readTemperature();
  Serial.print("Humidity: ");
  Serial.println(h);
  Serial.print("Temperature: ");
  Serial.println(t);
}

void MeasureDistance()
{
  float distanceCm = DistanceSensorHCSR04.measureDistanceCm();
  Serial.print("Distance: ");
  Serial.println(distanceCm);
}

void PIRSensorDetecting()
{
  uint8_t lastValue = MovementSensorDetector.lastValue();
  uint8_t newValue = MovementSensorDetector.read();
  if (newValue != lastValue)          //  change detected?
  {
    Serial.print(millis());
    Serial.print("\t");
    Serial.println(newValue, HEX);
  }
}