#pragma once
#include <Arduino.h>

#ifndef MORSE_TREE_H
#define MORSE_TREE_H


struct MorseEntry {
    char letter;
    const String code;
};

class MorseLogic{
public:
    static constexpr char morseDecoder[10]={
        'A','B','C','D','E','F','G','H','I','J'
    };

    static const MorseEntry morseEncoder[26];

    static String encode(char letter);
};

#endif