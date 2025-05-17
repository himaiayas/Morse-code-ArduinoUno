#include "morse-button.h"
#include "output-system.h"
#include <Arduino.h>
#include "global-flag.h"


MorseButton::MorseButton(int morsePin, OutputSystem outputSys):
  morsePin(morsePin),
  isPressing(false),
  morseThreshold(120),
  debounceThreshold(50),
  latestClick(millis()),
  outputSys(outputSys)
  {};


MorseLetterEnum MorseButton::detectClick(){
  if (!enableSpeedType) return MorseLetterEnum::NONE;
  int input = digitalRead(morsePin);

  if (!input && !isPressing){
    isPressing = true;
    outputSys.setBuzzerLED(HIGH);
    latestClick = millis();
  }
  else if (input && isPressing && millis()-latestClick>=50){
    isPressing = false;
    outputSys.setBuzzerLED(LOW);
    if(millis()-latestClick>=morseThreshold){
      return MorseLetterEnum::DASH; //_
    }
    else{
      return MorseLetterEnum::DOT; //.
    }
  }
  return MorseLetterEnum::NONE;
}

void MorseButton::reset(){
  isPressing = false;
}
