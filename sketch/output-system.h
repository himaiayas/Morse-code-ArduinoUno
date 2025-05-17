#include <stdint.h>
#pragma once
#include <LiquidCrystal.h>
#include <Arduino.h>
#include "enum.h"
#include "global-flag.h"
// const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
// LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#ifndef OUTPUT_SYSTEM_H
#define OUTPUT_SYSTEM_H

class OutputSystem{
public:
    uint8_t lcdMorseCursor;
    int buzzerPin;
    int ledPin;
    LiquidCrystal& lcdDisplay;
    unsigned long dotDuration;

    OutputSystem(int buzzerPin, int ledPin, LiquidCrystal& lcdDisplay);

    void setBuzzerLED(int value); //value = LOW or HIGH


    void setMessageLCD(String message);
    void addMorseLCD(MorseLetterEnum code); //single . or _
    void resetMorseLCD();

    void printEndSpeedTyping(double lpm, size_t fail);

    void outSignal(MorseLetterEnum code);

    
};

#endif