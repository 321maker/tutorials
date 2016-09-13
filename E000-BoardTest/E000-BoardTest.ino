/*            
        Title: 321Maker Experiment #000 - Board Test
        Description: This program will test each of the various components on the 321Maker Things shield.
        Tutorial:  http://321maker.com/e/tone-mixer
        Revision Date: March 15, 2016
        Licence: http://321maker.mit-license.org/
        Requirements:  Arduino with 321Maker Shield
*/
int button1Pin = 2;
int button2Pin = 3;
int humidPin = 4;
int buzzerPin = 5; 
int irPin =6;
int RGBRedPin=9;
int RGBGreenPin=10;
int RGBBluePin=11;
int redPin=12;
int bluePin=13;
int rotationPin=A0;
int lightPin=A1;
int tempPin=A2;
int outputDevice;
int now=0;
int last=0;
int output=0;
unsigned long int irdata=0;

void readSensors();
void cycleOutputs();

// Download the IR library if needed from here: https://github.com/z3t0/Arduino-IRremote
#include <IRremote.h>
IRrecv irrecv(irPin);
decode_results results;

//Download the DHT11 library if needed from here: https://github.com/adafruit/DHT-sensor-library
#include "DHT.h"
DHT dht(humidPin, DHT11);

void setup(){
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(humidPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(irPin, INPUT);
  pinMode(RGBRedPin, OUTPUT);
  pinMode(RGBGreenPin, OUTPUT);
  pinMode(RGBBluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  irrecv.enableIRIn(); // Start the IR receiver
  dht.begin(); //Enable the Temp/Humid Sensor
  }

void loop(){
  now = millis();
  if (now - last > 1000){ //Run functions every second
  last=now;
  cycleOutput();
  }
  
  if(irrecv.decode(&results)) {
   Serial.print("IR Code:");
   irdata=results.value;
   irrecv.resume(); // Receive the next value
   }
}
void cycleOutput(){
output++;

switch(output){
  case 1: //Turn on RGB red LED
  digitalWrite(redPin,HIGH);  
  break;
  
  case 2: //Turn on Blue LED
  digitalWrite(redPin,LOW);
  digitalWrite(bluePin,HIGH);
  break;


  case 3:  //Play Mary had a little Lamb with Buzzer
    digitalWrite(bluePin,LOW);
   if(analogRead(A0)>500){ // Make sure volume knob is up.
    tone(buzzerPin,220,200); 
    delay(250);
    tone(buzzerPin,196,200);
    delay(250);
    tone(buzzerPin,175,200);  
    delay(250);
    tone(buzzerPin,196,200);
    delay(250);
    tone(buzzerPin,220,200); 
    delay(250);
    tone(buzzerPin,220,200); 
    delay(250);
    tone(buzzerPin,220,200);
    delay(250);
        
    noTone(buzzerPin);  // going low
   }
    break;
        
  case 4: //fade in and out RGB Green LED
   //RGB is connected to PWM use analogWrite to control brightness 
   //PROTIP: You can mix RGB colours.
   
  for(int green=0;green<=255;green++){ //Fade in 
  analogWrite(RGBGreenPin, green);  
  delay(5);
  }
  for(int green=255;green>=0;green--){ // Fade out 
  analogWrite(RGBGreenPin, green);  
  delay(5);
  }
  break;

  case 5: //Fade in and out blue LED
  digitalWrite(RGBGreenPin,LOW);
 
  for(int blue=0;blue<=255;blue++){ //Fade in 
  analogWrite(RGBBluePin, blue);  
  delay(5);
  }
  for(int blue=255;blue>=0;blue--){ // Fade out 
  analogWrite(RGBBluePin, blue);  
  delay(5);
  }
  break;

  case 6: // Fade in and out Red LED
  for(int red=0;red<=255;red++){ //Fade in 
  analogWrite(RGBRedPin, red);  
  delay(5);
  }
  for(int red=255;red>=0;red--){ // Fade out 
  analogWrite(RGBRedPin, red);  
  delay(5);
  }  
  break;
  
  default:
  readSensors();
  output=0;
}
}

// Sensor Readings
void readSensors(){
Serial.println("/******************************/");
Serial.print("Rotation at:");
Serial.println(analogRead(rotationPin));
Serial.print("Light at:");
Serial.println(analogRead(lightPin));
Serial.print("LM35 Temperature:");
Serial.println(5.0 * analogRead(tempPin) * 100.0 / 1024);
Serial.print("DHT11 Temp:");
Serial.print(dht.readTemperature());
Serial.print(" Humidity:");
Serial.println(dht.readHumidity());

  if(digitalRead(button1Pin) == LOW){
  Serial.println("Button 1 Pressed");
  }

  if(digitalRead(button2Pin) == LOW){
  Serial.println("Button 2 Pressed");
  }

if (irdata != 0) {
    Serial.print("IR Code:");
    Serial.println(irdata, HEX);
    irdata =0;
  }
 }

