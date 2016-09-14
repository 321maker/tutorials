/*
        Title: 321Maker Experiment #002 - RGB Blink
        Description: This program will cycle different colors using the RGB LED on the 321Maker shield.
        Tutorial:  http://321maker.com/tutorial/e002-rgb-blink
        Revision Date: January 15, 2016
        Licence: http://321maker.mit-license.org/
        Requirements:  Arduino with 321Maker Shield
        Instructions: The RGB LED is connected to a Pulse Width Modulation(PWM) pin. 
        You can use analogWrite to control brightness.
*/
int RGBRedPin = 9;    //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 10; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 11;  //The blue RGB LED is connected pin 11 of the Arduino.
int waitTime = 2000; //Sets the amount of time to wait between color changes.

void setup() { //The Setup function runs once.
  pinMode(RGBRedPin, OUTPUT);    //Setup red RGB LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT);  //Setup green RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT);   //Setup blue RGB LED pin as an output pin.
}

void loop() { //The loop function runs forever.
  
//Display Red
digitalWrite(RGBRedPin, HIGH); //Turn on RED
delay(waitTime);               //Wait for 2 seconds
digitalWrite(RGBRedPin, LOW);  //Turn off Red

//Display Green
digitalWrite(RGBGreenPin, HIGH); //Turn on RED
delay(waitTime);               //Wait for 2 seconds
digitalWrite(RGBGreenPin, LOW);  //Turn off Red

//Display Blue
digitalWrite(RGBBluePin, HIGH); //Turn on RED
delay(waitTime);               //Wait for 2 seconds
digitalWrite(RGBBluePin, LOW);  //Turn off Red

//Display  Magenta  (Red + Blue)
digitalWrite(RGBRedPin, HIGH); //Turn on RED
digitalWrite(RGBBluePin, HIGH); //Turn on RED
delay(waitTime);               //Wait for 2 seconds
digitalWrite(RGBRedPin, LOW);  //Turn off Red
digitalWrite(RGBBluePin, LOW); //Turn on RED

//Display  Yellow  (Red + Green)
digitalWrite(RGBRedPin, HIGH); //Turn on RED
digitalWrite(RGBGreenPin, HIGH); //Turn on RED
delay(waitTime);               //Wait for 2 seconds
digitalWrite(RGBRedPin, LOW);  //Turn off Red
digitalWrite(RGBGreenPin, LOW); //Turn of RED

//Display  Cyan  (Blue + Green) 
digitalWrite(RGBBluePin, HIGH); //Turn on BLUE
digitalWrite(RGBGreenPin, HIGH); //Turn on GREEN
delay(waitTime);               //Wait for 2 seconds
digitalWrite(RGBBluePin, LOW); //Turn of BLUE
digitalWrite(RGBGreenPin, LOW);  //Turn off GREEN

//Display White  (Red + Blue + Green)
digitalWrite(RGBRedPin, HIGH); //Turn on RED
digitalWrite(RGBBluePin, HIGH); //Turn on BLUE
digitalWrite(RGBGreenPin, HIGH); //Turn on GREEN
delay(waitTime);               //Wait for 2 seconds
digitalWrite(RGBRedPin, LOW);  //Turn off RED
digitalWrite(RGBBluePin, LOW); //Turn off BLUE
digitalWrite(RGBGreenPin, LOW); //Turn off GREEN
}
