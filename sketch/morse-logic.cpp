#include "morse-logic.h"




static const MorseEntry MorseLogic::morseEncoder[26]={
  {'E',"."},
  {'T',"_"},
  //TODO: insert all {letter,morseCode} for each letter;
};

static String MorseLogic::encode(char letter){
  //TODO: implement this function.
  //make sure letter is uppercase
  //find matching letter in morseEncoder array and return morse code
  //Note* example if(morseEncoder[0].letter == 'E') return morseEncoder[0].code;
  return "";
}