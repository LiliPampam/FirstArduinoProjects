#include <Arduino.h>
#include <DHT.h>
#include <HCSR04.h>
#include <PIR.h>
#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5


// put function declarations here:
int myFunction(int, int);

void MeasureTemperatureAndHumidity();

void PIRSensorDetecting();

void MeasureDistance();

void LEDControl();

unsigned char Pins[4] = {LED1, LED2, LED3, LED4};

// Global variables

//For real hardware should be used DHT11, for simulation - DHT22.
//DHT dht11(10, DHT11);
DHT dht11(10, DHT22);

int a = 10, b = 70;

PIR MovementSensorDetector;

UltraSonicDistanceSensor DistanceSensorHCSR04(7, 6);

void setup()
{
  // put your setup code here, to run once:
  int i;
  int result = myFunction(2, 3);
  Serial.begin(9600);
  Serial.print("The result is: ");
  Serial.println(result);
  dht11.begin();
  MovementSensorDetector.add(9);
  Serial.println("Begin: ");
  for(i = 0; i < 4; i++)
  {
    digitalWrite (Pins[i], HIGH);
    pinMode (Pins[i], OUTPUT);
  }
}

void loop()
{
  delay(1000);
  MeasureTemperatureAndHumidity();
  MeasureDistance();
  PIRSensorDetecting();
  LEDControl();

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
int led_counter= 0;
void LEDControl()
{
  //led_counter=random(4);
  digitalWrite (Pins[led_counter], !digitalRead(Pins[led_counter]));
 //Serial.println(led_counter);
  led_counter++;
  if (led_counter > 3)
  {
    led_counter = 0;
  }
}