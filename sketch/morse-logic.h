#pragma once
#include <Arduino.h>
#include "enum.h"

#ifndef MORSE_TREE_H
#define MORSE_TREE_H



struct MorseEntry {
    char letter;
    const String code;
};

class MorseLogic{
public:
    static size_t index;
    static const char morseDecoder[29];

    static const MorseEntry morseEncoder[26];

    static String encode(char letter);
    static bool decode(MorseLetterEnum code);
    static char getCurDecoded();
};

#endif