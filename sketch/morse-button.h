#ifndef MORSE_BUTTON_H
#define MORSE_BUTTON_H

class MorseButton{
public:
    int morsePin;
    unsigned long latestClick;
    unsigned long morseThreshold;
    unsigned long debounceThreshold;
    bool isPressing;

    MorseButton(int morsePin);

    void detectClick();

    
};

#endif