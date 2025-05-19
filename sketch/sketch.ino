#include "global-flag.h"
#include "output-system.h"
#include "morse-button.h"
#include "morse-logic.h"
#include "enum.h"
#include "utils.h"


#include <Arduino.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
const int buzzerPin = 6;
const int ledPin = 5;
const int resetPin = 2;
const int morsePin = 4;
const int enterPin = 3;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
OutputSystem outputSys(buzzerPin, ledPin, lcd);
MorseButton morseBtnSys(morsePin,outputSys);

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(morsePin, INPUT);
  pinMode(enterPin, INPUT);
  pinMode(resetPin,INPUT);

  Serial.begin(9600);

  outputSys.setMessageLCD(speedTypeStr.substring(speedTypeIndex, speedTypeIndex+16));
  attachInterrupt(digitalPinToInterrupt(resetPin), resetBtnInterrupt, FALLING); 
}

void loop() {

  if (Serial.available()){
    String inputStr = Serial.readString();
    isMorseFromSerialRunning = true;
    outSerialMorse(inputStr);
    isMorseFromSerialRunning = false;
  }

  MorseLetterEnum signal = morseBtnSys.detectClick();
  uint8_t enter = digitalRead(enterPin);
  if (signal!=MorseLetterEnum::NONE){
    handleOnMorseBtnClick(signal);
  }
  
  else if (enter==LOW && MorseLogic::getDecoderIndex() !=0){
    char ch = MorseLogic::getCurDecoded();
    handleOnEnterChSpeedType(ch);
  }
}


void resetSpeedType(){
  speedTypeIndex = 0;
  speedTypeFail = 0;
  speedTypeStart = millis();
  enableSpeedType =true;
  isSpeedTypeRunning = false;
}


void handleOnMorseBtnClick(MorseLetterEnum signal){
  if (!isSpeedTypeRunning){
      resetSpeedType();
      isSpeedTypeRunning = true;
    }
    Serial.println(morseLetterEnumToChar(signal));

    bool res = MorseLogic::decode(signal);
    if (!res){
      //reset
      Serial.println("reset");
      speedTypeFail++;
      outputSys.resetMorseLCD();
    }
    else{
      outputSys.addMorseLCD(signal);
    }
}

void handleOnEnterChSpeedType(char ch){
if (ch==toupper(speedTypeStr[speedTypeIndex])){
      //count and proceed
      speedTypeIndex++;

      if (speedTypeIndex >= speedTypeStr.length()){ //end of typing
        enableSpeedType = false;
        outputSys.printEndSpeedTyping(
          (double)countLetter(speedTypeStr)/(millis()-speedTypeStart) * 60000,
          speedTypeFail
        );
        resetSpeedType();
        return;
     
      }
      else{
        while (!isAlpha(speedTypeStr[speedTypeIndex])) speedTypeIndex++;
        outputSys.setMessageLCD(speedTypeStr.substring(speedTypeIndex, speedTypeIndex+16));
      }
    }
    else{
      speedTypeFail++;
    }
    //get ch and compare to the test.
    Serial.println(ch);
    outputSys.resetMorseLCD();
  }



  void outSerialMorse(String& str){
    Serial.print(str);
    for (size_t i=0; i<str.length(); i++){
      if(!enableMorseFromSerial){
        enableMorseFromSerial = true;
        return;
      };

      if(str[i] == " "){
        if(i>0 && str[i-1]!=" ") {
          outputSys.outSignal(MorseLetterEnum::WORD_SPACE);
        }
        continue;
      }

      if (!isAlpha(str[i])) continue;

      String charCode = MorseLogic::encode(str[i]);

      for (size_t j=0; j<charCode.length()-1; j++){
        if(!enableMorseFromSerial){
        enableMorseFromSerial = true;
        return;
        };
        outputSys.outSignal(charToMorseLetterEnum(charCode[j]));
        outputSys.outSignal(MorseLetterEnum::CH_SPACE);

      }
      outputSys.outSignal(charToMorseLetterEnum(charCode[charCode.length()-1]));
      outputSys.outSignal(MorseLetterEnum::LETTER_SPACE);
    }
    outputSys.resetMorseLCD();
    outputSys.setMessageLCD(speedTypeStr.substring(speedTypeIndex, speedTypeIndex+16));

    morseBtnSys.reset(); 
  }

  void resetBtnInterrupt(){
    Serial.print("resetInterrpt");

    resetSpeedType();

    //resetlcd
    outputSys.resetMorseLCD();
    outputSys.setMessageLCD(speedTypeStr.substring(speedTypeIndex, speedTypeIndex+16));

    morseBtnSys.reset();    

    if(isMorseFromSerialRunning) enableMorseFromSerial = false;
    else enableMorseFromSerial = true;

    isMorseFromSerialRunning = false;
  }



  

