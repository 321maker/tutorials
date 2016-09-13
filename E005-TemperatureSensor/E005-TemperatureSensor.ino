/*
        Title: 321Maker Experiment #005 - Temperature Sensor
        Description: This program will read the data from the temperature sensor. Convert the data to a temperature and display the temperature to the serial monitor in both Celsius and Fahrenheight
        Tutorial:  http://321maker.com/e/temperature-sensor
        Revision Date: March 15, 2016
        Licence: http://321maker.mit-license.org/
        Requirements:  Arduino with 321Maker Shield
        Instructions: Click Tools, Serial Montior (Ctrl + Shift + M) to view the output.
*/

int tempPin = A2;     //The temperature sensor is plugged into pin A2 of the Arduino.
int data;             //This will store the data from the sensor.
int waitTime = 3000;  //Wait
void setup(void) {    //The Setup function runs once.
  Serial.begin(9600); //This will enable the Arduino to send data to the Serial monitor.
}

void loop(void) { //The loop function runs forever.
  data = analogRead(tempPin);        //Read from the temperature sensor
  Serial.print("Sensor reading = "); //Serial.print displays to the Serial Monitor.
  Serial.print(data);                //This is the raw analog reading

  // Calculate and display temperature.
  float temperatureC = (5.0 * data * 100.0) / 1024;
  Serial.print(temperatureC); Serial.println(" degrees C");

  // Convert temperature to Fahrenheight and display.
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  Serial.print(temperatureF); Serial.println(" degrees F");

  delay(waitTime); //Wait waitTime before running again.
}
