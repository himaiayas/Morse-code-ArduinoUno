#include "morse-logic.h"
#include <Arduino.h>

static size_t MorseLogic::index = 0;

static const char MorseLogic::morseDecoder[29] = {
        '0',
        'E','T',
        'I','A','N','M',
        'S','U','R','W','D','K','G','O',
        'H','V','F','0','L','0','P','J','B','X','C','Y','Z','Q'
};

static const MorseEntry MorseLogic::morseEncoder[26]={
  {'A',"._"},{'B',"_..."},{'C',"_._."},{'D',"_.."},{'E',"."},{'F',".._."},
  {'G',"__."},{'H',"...."},{'I',".."},{'J',".___"},{'K',"_._"},{'L',"._.."},
  {'M',"__"},{'N',"_."},{'O',"___"},{'P',".__."},{'Q',"__._"},{'R',"._."},{'S',"..."}, 
  {'T',"_"},{'U',".._"},{'V',"..._"},{'W',".__"},{'X',"_.._"},{'Y',"_.__"},{'Z',"__.."}
};

static String MorseLogic::encode(char letter){
  char upperLetter=toupper(letter);
  if (upperLetter>='A' && upperLetter<='Z'){
    return morseEncoder[upperLetter-'A'].code;
  }
  return "";
}

static bool MorseLogic::decode(MorseLetterEnum code){
  uint8_t offset = (code==MorseLetterEnum::DOT)?1:2;
  if (index*2 + offset>=29){
    index=0;
    return false;
  }
  index = index*2 + offset;
  if (morseDecoder[index]=='0'){
    index=0;
    return false;
  }
  return true;
}

static char MorseLogic::getCurDecoded(){
  char ch = morseDecoder[index];
  index=0;
  return ch;
}