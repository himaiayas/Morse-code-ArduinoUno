#include "output-system.h"

OutputSystem::OutputSystem(int buzzerPin, int ledPin, LiquidCrystal lcdDisplay):
  buzzerPin(buzzerPin),
  ledPin(ledPin),
  lcdDisplay(lcdDisplay)
  {};

void OutputSystem::setBuzzerLED(int value){
    digitalWrite(buzzerPin,value);
    digitalWrite(ledPin,value);
  }
void OutputSystem::setLCD(String message){
    lcdDisplay.clear();
    lcdDisplay.setCursor(0,0);
    lcdDisplay.print(message);
  }

void OutputSystem::addMorseLCD(String morse){

}
void OutputSystem::setMessageLCD(String message){

}
void OutputSystem::resetMorseLCD(){

}