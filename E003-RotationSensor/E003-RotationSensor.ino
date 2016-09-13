/*    
        Title: 321Maker Experiment #003 - Rotation Sensor
        Description: This program will read the data from the rotation sensor and display the result to the serial monitor.
        Tutorial:  http://321maker.com/e/rotation-sensor
        Revision Date: March 15, 2016
        Licence: http://321maker.mit-license.org/
        Requirements:  Arduino with 321Maker Shield
        Instructions: Click Tools, Serial Montior (Ctrl + Shift + M) to view the output.
*/
int rotationPin = A0; //The rotation sensor is plugged into pin A0 of the Arduino.
int data=0;           //Used to store data from sensor.

void setup() { //The Setup function runs once.
Serial.begin(9600); //This will enable the Arduino to send data to the Serial monitor.
}

void loop() { //The loop function runs forever.
data = analogRead(rotationPin);  //Read the value from the light sensor and store it in the lightData variable.
Serial.print("Rotation value ="); 
Serial.println(data);  //Print the data to the serial port.
delay(1000);           //Wait 1 second (1000mS) before running again. 
}
