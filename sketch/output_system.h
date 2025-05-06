#include <LiquidCrystal.h>
#include <Arduino.h>
// const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
// LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#ifndef OUTPUT_SYSTEM_H
#define OUTPUT_SYSTEM_H

class OutputSystem{
public:
    int buzzerPin;
    int ledPin;
    LiquidCrystal lcdDisplay;

    OutputSystem(int buzzerPin, int ledPin, LiquidCrystal lcdDisplay);

    void setBuzzerLED(int value); //value = LOW or HIGH
    void setLCD(String name);

    
};

#endif