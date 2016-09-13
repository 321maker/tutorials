  /*      
   *      Title: 321Maker Experiment #001 - Blue Blink
   *      Description: This program will blink the Blue LED on the 321Maker shield.
   *      Tutorial:  http://321maker.com/e/blue-blink   
   *      Revision Date: January 15, 2016
   *      Licence: http://321maker.mit-license.org/
   *      Requirements:  Arduino with 321Maker Shield
   */

int blueLedPin  = 13; //The blue LED is connected pin 13 of the Arduino.
int onTime = 2000;    //This is the number of milliseconds the LED will be on for. 
int offTime = 500;   //This is the number of milliseconds the LED will be off for. 

void setup() { //The Setup function runs once.
  pinMode(blueLedPin, OUTPUT);  //Setup Blue LED pin as an output pin.  
}

void loop() { //The loop function runs forever.
  digitalWrite(blueLedPin, HIGH);  //Turn on the blue LED.
  delay(onTime);                   //Wait onTime.
  digitalWrite(blueLedPin, LOW);   //Turn off the blue LED.
  delay(offTime);                  //Wait offTime.
}
