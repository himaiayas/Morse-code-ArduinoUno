#include <stdint.h>
#include "output-system.h"
#include "enum.h"
#pragma once



#ifndef MORSE_BUTTON_H
#define MORSE_BUTTON_H

class MorseButton{
public:
    int morsePin;
    unsigned long latestClick;
    unsigned long morseThreshold;
    unsigned long debounceThreshold;
    bool isPressing;
    OutputSystem outputSys;

    MorseButton(int morsePin, OutputSystem outputSys);

    MorseLetterEnum detectClick();

    void reset();

    
};

#endif