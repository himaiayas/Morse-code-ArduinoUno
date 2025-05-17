#include "utils.h"

char morseLetterEnumToChar(MorseLetterEnum code){
  switch (code){
    case MorseLetterEnum::DOT:
      return '.';
    case MorseLetterEnum::DASH:
      return '_';
    default:
      return ' ';
  }
}

MorseLetterEnum charToMorseLetterEnum(char ch){
  switch (ch){
    case '.':
      return MorseLetterEnum::DOT;
    case '_':
      return MorseLetterEnum::DASH;
    default:
      return MorseLetterEnum::NONE;
  }
}

String fillEndingSpaces(String& str){
  int lcdLength = 16;
  while (str.length()<lcdLength){
    str+=" ";
  }
  return str;
}

size_t countLetter(String& str){
  size_t count=0;
  for (size_t i=0; i<str.length(); i++){
    if(isAlpha(str[i])) count++;
  }
  return count;
}