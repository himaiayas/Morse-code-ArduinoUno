#include "morse-logic.h"




static const MorseEntry MorseLogic::morseEncoder[26]={
  {'E',"."},
  {'T',"_"},
  {'A',"_"},//TODO: insert all {letter,morseCode} for each letter;
  {'B,"_'},{"C","_"},{"D","_"},{'F,"_'},{"G","_"},{"H","_"},
  {'I,"_'},{"J","_"},{"K","_"}{'L,"_'},{"M","_"},{"N","_"},
  {'O,"_'},{"P","_"},{"Q","_"},{'R,"_'},{"S","_"},{"U","_"},
  {'V,"_'},{"W","_"},{"X","_"}{'Y,"_'},{"Z","_"};
};
const int morseTableSize=sizeof(morseTable)/sizeof(MorseEntry);
static String MorseLogic::encode(char letter){
  input=std::toupper(static_cast<unsigned char>(letter));
  for(int i=0;i<morseTableSize;i++){
    if(morseTable[i].letter==letter){
      return morseTable[i].code;
    }
  }
  //make sure letter is uppercase
  //find matching letter in morseEncoder array and return morse code
  //Note* example if(morseEncoder[0].letter == 'E') return morseEncoder[0].code;
  return "";
}