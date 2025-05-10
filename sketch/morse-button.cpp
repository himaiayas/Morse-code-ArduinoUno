#include "morse-button.h"
#include "output-system.h"
#include <Arduino.h>

MorseButton::MorseButton(int morsePin, OutputSystem outputSys):
  morsePin(morsePin),
  isPressing(false),
  morseThreshold(100),
  debounceThreshold(50),
  latestClick(millis()),
  outputSys(outputSys)
  {};

uint8_t MorseButton::detectClick(){
  int input = digitalRead(morsePin);

  if (!input && !isPressing){
    isPressing = true;
    latestClick = millis();
  }
  else if (input && isPressing && millis()-latestClick>=50){
    isPressing = false;
    if(millis()-latestClick>=morseThreshold){
      return 2; //_
    }
    else{
      return 1; //.
    }
  }
  return 0;
}
