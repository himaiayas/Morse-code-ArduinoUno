#include "output_system.h"

OutputSystem::OutputSystem(int buzzerPin, int ledPin, LiquidCrystal lcdDisplay):
  buzzerPin(buzzerPin),
  ledPin(ledPin),
  lcdDisplay(lcdDisplay),
  void OutputSystem::setBuzzerLED(int value){
    digitalWrite(buzzerPin,value);
    digitalWrite(ledPin,value);
  },
  void OutputSystem::setLCD(String message){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(message);
  }

  {};