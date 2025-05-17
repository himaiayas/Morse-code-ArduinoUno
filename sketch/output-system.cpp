#include "output-system.h"
#include "utils.h"

OutputSystem::OutputSystem(int buzzerPin, int ledPin, LiquidCrystal& lcdDisplay):
  buzzerPin(buzzerPin),
  ledPin(ledPin),
  lcdDisplay(lcdDisplay),
  lcdMorseCursor(0),
  dotDuration(60)
  {
    pinMode(buzzerPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
    digitalWrite(buzzerPin,HIGH);
    digitalWrite(ledPin,LOW);
  };



void OutputSystem::setBuzzerLED(int value){
    digitalWrite(buzzerPin,!value);
    digitalWrite(ledPin,value);
  }


void OutputSystem::addMorseLCD(MorseLetterEnum code){
  lcdDisplay.setCursor(lcdMorseCursor,1);
  lcdDisplay.print(morseLetterEnumToChar(code));
  lcdMorseCursor++;
}
void OutputSystem::setMessageLCD(String message){
  lcdDisplay.setCursor(0,0);
  lcdDisplay.print(fillEndingSpaces(message));
}
void OutputSystem::resetMorseLCD(){
  lcdMorseCursor = 0;
  lcdDisplay.setCursor(0, 1);
  lcdDisplay.print("                ");
}

void OutputSystem::printEndSpeedTyping(double lpm, size_t fail){
  lcdDisplay.clear();
  lcdDisplay.setCursor(0, 0);
  lcdDisplay.print("LPM = " + String(lpm));
  lcdDisplay.setCursor(0, 1);
  lcdDisplay.print("Fails = " + String(fail));
}

void OutputSystem::outSignal(MorseLetterEnum code){
  switch (code){
    case MorseLetterEnum::DOT:
      setBuzzerLED(HIGH);
      delay(dotDuration);
      break;
    case MorseLetterEnum::DASH:
      setBuzzerLED(HIGH);
      delay(3*dotDuration);
      break;
    case MorseLetterEnum::CH_SPACE:
      setBuzzerLED(LOW);
      delay(dotDuration);
      break;
    case MorseLetterEnum::LETTER_SPACE:
      setBuzzerLED(LOW);
      delay(3*dotDuration);
      break;
    case MorseLetterEnum::WORD_SPACE:
      setBuzzerLED(LOW);
      delay(7*dotDuration);
      break;
    default:
      break;
  }
}

