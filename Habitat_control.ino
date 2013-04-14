/*
Code to automate an enviroment including lighting, heating and cooling
Adjust the settings below to suit your needs

Need to:
Add accurate clock or timing system for lighting
Add definable moonrise, sunrise, sunset, moonset
Set for scrolling LCD between the two setups (will require say two setup(true))
*/

#include "constants.h"                // Define constants
#include <LiquidCrystal.h>            // LCD display library

//=============================================================================================================
//======================================== User Adjustable ====================================================
//=============================================================================================================

int fahrenheit(true);                // Set to false for Celsius
int hotend(85);                      // Adjust for hotend temperature
int coolend(80);                     // Adjust for coolend temperature
int LCD(true);                       // Set to false if no LCD display to allow serial communication

//=============================================================================================================
//=============================================================================================================
//=============================================================================================================

int samples[numsamples];             // Amount of temperature samples to take

LiquidCrystal lcd(0, 1, 2, 4, 7, 13); // LCD interface pins

// Create characters (can have up to 8)
byte degree[8] = {
  B01100,
  B10010,
  B10010,
  B01100,
  B00000,
  B00000,
  B00000,
};

byte poweroff[8] = {
  B01110,
  B10001,
  B11011,
  B10101,
  B11011,
  B10001,
  B11111,
};

byte power25[8] = {
  B01110,
  B10001,
  B10001,
  B10001,
  B10011,
  B11111,
  B11111,
};

byte power50[8] = {
  B01110,
  B10001,
  B10001,
  B10111,
  B11111,
  B11111,
  B11111,
};

byte power100[8] = {
  B01110,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

byte sun[8] = {
  B10101,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B10101,
};

byte moon[8] = {
  B00111,
  B01010,
  B10100,
  B10100,
  B10100,
  B01010,
  B00111,
};

void setup()  {
  digitalWrite(relay_1, relay_OFF);  // Initialize Pins so relays are inactive at reset
  
  pinMode(relay_1, OUTPUT);          // Then set pins as OUTPUT
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  
  analogReference(EXTERNAL);         // To improve temperature accuracy
  
  delay(1000);                       // Delay to allow LCD to initilize
  
// Create custom characters
  lcd.createChar(0, degree);         // Degree symbol for temperature
  lcd.createChar(1, poweroff);       // Power OFF symbol
  lcd.createChar(2, power25);        // Power at 25% symbol
  lcd.createChar(3, power50);        // Power at 50% symbol
  lcd.createChar(4, power100);       // Power at 100% symbol
  lcd.createChar(5, sun);            // Sun symbol for daytime
  lcd.createChar(6, moon);           // Moon symbol for nighttime

// Output of data setup
  if(LCD==true)  {  
  lcd.begin(20, 4);                  // Setup LCD columns and rows
  }
  else  {
  Serial.begin(9600);                // Setup serial link for debugging
  Serial.println("Working");         // Prove communication
  }
}

void loop()  {  
  heat1();                           // Check hotend temperature and adjust heating  
  cool1();                           // Check coolend temperature and adjust heating
  light1();                          // Check time and adjust lighting 
  
  delay(4000);
  
  //heat2();
  //cool2();
  //light2();
  
  //delay(4000);
  
  lcd.clear();
  lcd.print("Habitat Control");
  lcd.setCursor(0, 1);
  lcd.print("Software V0.2");

  delay(2000);
  
  lcd.clear();
  lcd.print("      by        ");
  lcd.setCursor(0, 1);
  lcd.print("SPATTE88 @ RFUK");
  
  delay(2000);
}
