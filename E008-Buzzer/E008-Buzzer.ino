/*
        Title: 321Maker Experiment #008 - Buzzer
        Description: This program will turn on the buzzer when the SW1 button is pressed. 
        Tutorial:  http://321maker.com/e/buzzer
        Revision Date: January 15, 2016
        Licence: http://321maker.mit-license.org/
        Requirements:  Arduino with 321Maker Shield
*/

int buzzerPin  = 5 ;  //The buzzerPin is connected to pin 5 of the Arduino.
int button1Pin = 2;   //The SW1 button is connect to pin 2 of the Arduino.

void setup() { //The Setup function runs once.
  pinMode(buzzerPin, OUTPUT);  //Setup red LED pin as an output pin.
  pinMode(button1Pin, INPUT);  //Setup button1 pin as an input pin.
}

void loop() { //The loop function runs forever.
  if (digitalRead(button1Pin) == LOW) { //Check to see if button1 is pressed.
    tone(buzzerPin, 2000,50);           //Play a tone of 2000Hz for 50 milliseconds.
     } 
}
