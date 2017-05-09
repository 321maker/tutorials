/*
        Title: 321Maker Experiment #M006 - Probability 
        Description: This program can be used teach the concepts of  probability with 2 possible outcomes.
        By adjusting the value of probRed you can change the probability that red will be shown versus blue. 
        Tutorial:  http://321maker.com/m/006
        Revision Date: May 8, 2017
        Licence: http://321maker.mit-license.org/
        Requirements:  Arduino with 321Maker Shield
*/
int probRed = 50; //This is the % probablility of red beeing selected.

int redLed  = 12 ;  //The red LED is connected pin 12 of the Arduino.
int blueLed = 13 ;  //The blue LED is connected pin 13 of the Arduino.
int button1 = 2;    //The SW1 button is connect to pin 2 of the Arduino.

void setup() { //The Setup function runs once.
  pinMode(redLed, OUTPUT);  //Setup red LED pin as an output pin.
  pinMode(blueLed, OUTPUT);  //Setup blue LED pin as an output pin.
  pinMode(button1, INPUT);  //Setup button1 pin as an input pin.
  randomSeed(analogRead(0)); //Generate series of random numbers.
}

void loop() { //The loop function runs forever.

  if (digitalRead(button1) == LOW) { //Check to see if button1 is pressed.

    if(random(100) < probRed){  //Get random number and determine if it is red or blue.
      digitalWrite(redLed, HIGH);//Turn on the red LED.
      delay(2000); //Wait 2 seconds before making sure the lights are turned off.
      digitalWrite(redLed, LOW);//Turn off the blue LED.
      } else {
      digitalWrite(blueLed, HIGH);//Turn on the blue LED.
      delay(2000); //Wait 2 seconds before making sure the lights are turned off.
      digitalWrite(blueLed, LOW);//Turn off the red LED.
    }
  }
}
