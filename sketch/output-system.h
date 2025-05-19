#pragma once
#include <stdint.h>
#include <LiquidCrystal.h>
#include <Arduino.h>
#include "enum.h"
#include "global-flag.h"

#ifndef OUTPUT_SYSTEM_H
#define OUTPUT_SYSTEM_H

class OutputSystem{
private:
    uint8_t lcdMorseCursor;
    unsigned long dotDuration;
public:
    int buzzerPin;
    int ledPin;
    LiquidCrystal& lcdDisplay;

    OutputSystem(int buzzerPin, int ledPin, LiquidCrystal& lcdDisplay);

    void setBuzzerLED(int value); //value = LOW or HIGH
    void setMessageLCD(String message);
    void addMorseLCD(MorseLetterEnum code); //single . or _
    void resetMorseLCD();
    void printEndSpeedTyping(double lpm, size_t fail);
    void outSignal(MorseLetterEnum code);
};

#endif