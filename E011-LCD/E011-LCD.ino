/*
        Title: 321Maker Experiment #011 - LCD
        Description: This program will display 321Maker on the serial LCD.
        Tutorial:  http://321maker.com/e/011-lcd
        Revision Date: October 12, 2016
        Licence: http://321maker.mit-license.org/
        Requirements:  Arduino with 321Maker Shield, 1602 Serial LCD 
        Serial LCD library: https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads/NewliquidCrystal_1.3.4.zip      
*/
//Load libraries
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

 //Define address for the Serial LCD display.
#define I2C_ADDR  0x3f  //If 0x3f doesn't work change this to 0x27
#define BACKLIGHT_PIN  3

//Initialise the Serial LCD.
LiquidCrystal_I2C lcd(I2C_ADDR, 2,1,0,4,5,6,7); //These pin numbers are hard coded in on the serial backpack board.

void setup()
 {
    lcd.begin (16,2);     //Initalize the LCD.
    lcd.setBacklightPin(3,POSITIVE);//Setup the backlight.
    lcd.setBacklight(HIGH); //Switch on the backlight.
    lcd.clear();
    lcd.setCursor(0,0);   //goto first column  and first line (0,0)
    lcd.print("321");     //Print at cursor Location
    lcd.setCursor(0,1);   //goto first column and second line 
    lcd.print("Maker");   //Print at cursor Location 
    delay(1000);   
    
 }
 
void loop(){

  }
