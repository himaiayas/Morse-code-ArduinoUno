#include "global-flag.h"
#include "output-system.h"
#include "morse-button.h"
#include "morse-logic.h"

#include <Arduino.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int buzzerPin = 5;
const int ledPin = 6;

const int morsePin = 7;

OutputSystem outputSys(buzzerPin, ledPin, lcd);
MorseButton morseSys(morsePin,outputSys);

void setup() {
  Serial.begin(9600);
  Serial.print("start");
  Serial.println(morseSys.morsePin);
  Serial.println(MorseLogic::morseEncoder[0].code);

}

void loop() {
  //uint8_t signal = morseSys.detectClick();
}
