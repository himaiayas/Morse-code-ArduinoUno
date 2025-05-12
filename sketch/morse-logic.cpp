#include "morse-logic.h"




static const MorseEntry MorseLogic::morseEncoder[26]={
  {'A',"._"},//TODO: insert all {letter,morseCode} for each letter;
  {'B',"_..."},{"C","_._."},{"D","_.."},{'E',"."},{'F,".._.'},{"G","__."},{"H","...."},
  {'I,"..'},{"J",".___"},{"K","_._"}{'L,"._..'},{"M","__"},{"N","_."},
  {'O',"___"},{"P",".__."},{"Q","__._"},{'R',"._."},{"S","..."}, {'T',"_"},{"U",".._"},
  {'V',"..._"},{"W",".__"},{"X","_.._"}{'Y,"_.__'},{"Z","__.."}
};

static String MorseLogic::encode(char letter){
  char input=toupper(letter);
  if(letter>='A'&&letter<='Z'){
    return morseEncoder[letter-'A'].code
  }
  return "";
  //make sure letter is uppercase
  //find matching letter in morseEncoder array and return morse code
  //Note* example if(morseEncoder[0].letter == 'E') return morseEncoder[0].code;
}