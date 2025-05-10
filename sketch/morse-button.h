#include <stdint.h>
#pragma once
#include "output-system.h"

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

    uint8_t detectClick();

    
};

#endif