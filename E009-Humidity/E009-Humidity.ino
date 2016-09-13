/*
        Title: 321Maker Experiment #009 - Humidity
        Description: This program will monitior the humidity and temperature from the DHT11 sensor and display it in the serial monitor.
        Tutorial:  http://321maker.com/e/humidity
        Revision Date: January 15, 2016
        Licence: http://321maker.mit-license.org/
        Requirements:  Arduino with 321Maker Shield
        DHT sensor library: https://github.com/adafruit/DHT-sensor-library/archive/master.zip
*/

#include "DHT.h"
int DHT11Pin = 4;        //The DHT11 sensor  is connected to pin 4 of the Arduino. 
int waitTime = 5000;     //The amount of time to wait between sensor reads.
DHT dht(DHT11Pin, DHT11);//Initialize the sensor. 

void setup(){
  dht.begin();  //Start the sensor.
}

void loop()
{
  delay(waitTime);
  float humidity = dht.readHumidity();  //Read the humidity value from the sensor.
  float celsius = dht.readTemperature(); //Read the temperature (c) value from the sensor. 
  float fahrenheit = dht.readTemperature(true); //Read the temperature (f) value from the sensor.
  float heatIndexF = dht.computeHeatIndex(fahrenheit, humidity); //Calculate the heat index (f).
  float heatIndexC = dht.computeHeatIndex(celsius, humidity, false); //Calculate the heat index (c).

  Serial.print("Humidity   (%): "); 
  Serial.println(humidity );        //Display the humidity precentage.
  Serial.print("Temperature(c): ");
  Serial.println(celsius);          //Display the temperature in celsius.
  Serial.print("Heat index (c): ");
  Serial.println(heatIndexC);       //Display the heat index in celsius.
  Serial.print("Temperature(f): ");
  Serial.println(fahrenheit);       //Display the temperature in fahrenheit.
  Serial.print("Heat index (f): ");
  Serial.println(heatIndexF);       //Display the heat index in fahrenheit.
  }

