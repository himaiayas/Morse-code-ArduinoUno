#pragma once
#include <stdint.h>
#include "output-system.h"
#include "enum.h"

#ifndef MORSE_BUTTON_H
#define MORSE_BUTTON_H

class MorseButton{
private:
    unsigned long latestClick;
    unsigned long morseThreshold;
    unsigned long debounceThreshold;
    bool isPressing;
public:
    int morsePin;
    OutputSystem outputSys;

    MorseButton(int morsePin, OutputSystem outputSys);

    MorseLetterEnum detectClick();
    void reset();   
};

#endif