/*
        Title: 321Maker Experiment #006 - Button
        Description: This program will turn on the blue LED when SW1 is pressed and the red LED when SW2 button is pressed.
        Tutorial:  http://321maker.com/e/button
        Revision Date: January 15, 2016
        Licence: http://321maker.mit-license.org/
        Requirements:  Arduino with 321Maker Shield
*/

int redLedPin  = 12 ;  //The red LED is connected pin 12 of the Arduino.
int blueLedPin = 13 ;  //The blue LED is connected pin 13 of the Arduino.
int button1Pin = 2;    //The SW1 button is connect to pin 2 of the Arduino.
int button2Pin = 3;    //The SW2 button is connect to pin 3 of the Arduino.

void setup() { //The Setup function runs once.
  pinMode(redLedPin, OUTPUT);  //Setup red LED pin as an output pin.
  pinMode(blueLedPin, OUTPUT);  //Setup blue LED pin as an output pin.
  pinMode(button1Pin, INPUT);  //Setup button1 pin as an input pin.
  pinMode(button2Pin, INPUT);  //Setup button2 pin as an input pin.
}

void loop() { //The loop function runs forever.

  if (digitalRead(button1Pin) == LOW) { //Check to see if button1 is pressed.
    digitalWrite(blueLedPin, HIGH);//Turn on the blue LED.
  } else {
    digitalWrite(blueLedPin, LOW); //Turn off the blue LED.
  }

  if (digitalRead(button2Pin) == LOW) { //Check to see if button1 is pressed.
    digitalWrite(redLedPin, HIGH); //Turn on the red LED.
  } else {
    digitalWrite(redLedPin, LOW);  //Turn off the red LED.
  }
}
