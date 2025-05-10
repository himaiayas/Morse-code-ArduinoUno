#include "global-flag.h"
#include "output_system.h"
#include <Arduino.h>
#include <LiquidCrystal.h>
// const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
// LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int morseBtn = 7;
unsigned long startClick = millis();
unsigned long holdingThreshold = 2000;
unsigned long debounceStart = millis();

bool isPressing = false;

void setup() {
  Serial.begin(9600);
  Serial.print("start");
  // OutputSystem outputSys(buzzerPin, ledPin, lcd);
  // Serial.print(outputSys.buzzerPin);

}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(morseBtn);


  if (!buttonState && !isPressing){
    isPressing = true;
    startClick = millis();
    Serial.print("state:");
    Serial.print(buttonState);
    Serial.print("  isPressing:");
    Serial.println(isPressing);
    debounceStart = millis();

  }
  else if (buttonState && isPressing && millis()-debounceStart>=1000){
    isPressing = false;
    Serial.println(millis()-startClick);
    Serial.print("state:");
    Serial.print(buttonState);
    Serial.print("  isPressing:");
    Serial.println(isPressing);

    startClick=millis();
    // if(millis()-startClick>=holdingThreshold){
    //   Serial.print("_");
    // }
    // else{
    //   Serial.print(".");
    // }
  }
}
