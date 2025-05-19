#pragma once
#include <Arduino.h>
#include "enum.h"

#ifndef UTILS_H
#define UTILS_H

char morseLetterEnumToChar(MorseLetterEnum code);
MorseLetterEnum charToMorseLetterEnum(char code);
String fillEndingSpaces(String& str);
size_t countLetter(String& str);

#endif