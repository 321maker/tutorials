  /*      
   *      Title: 321Maker Experiment #002 - Alternate Blink
   *      Description: This program will alternatly blink the blue and red LEDs on the 321Maker shield.
   *      Tutorial:  http://321maker.com/e/alternate-blink   
   *      Revision Date: January 15, 2016
   *      Licence: http://321maker.mit-license.org/
   *      Requirements:  Arduino with 321Maker Shield
   */

int redLedPin  = 12 ;  //The red LED is connected pin 12 of the Arduino.
int blueLedPin  = 13 ; //The blue LED is connected pin 13 of the Arduino.
int delayTime = 500;   //This is the number of milliseconds the LED will be on for. 

void setup() { //The Setup function runs once.
  pinMode(redLedPin, OUTPUT);  //Setup red LED pin as an output pin.
  pinMode(blueLedPin, OUTPUT);  //Setup blue LED pin as an output pin.   
}

void loop() { //The loop function runs forever.
  digitalWrite(redLedPin, HIGH); //Turn on the red LED.
  delay(delayTime);              //Wait delayTime.
  digitalWrite(redLedPin, LOW);  //Turn off the red LED.
  delay(delayTime);              //Wait delayTime.
  digitalWrite(blueLedPin, HIGH);//Turn on the blue LED.
  delay(delayTime);              //Wait delayTime. 
  digitalWrite(blueLedPin, LOW); //Turn off the blue LED.
  delay(delayTime);              //Wait delayTime.
}
