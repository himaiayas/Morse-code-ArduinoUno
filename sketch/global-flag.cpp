#include "global-flag.h"

volatile bool isSpeedTypeRunning = false;
volatile unsigned long speedTypeStart = millis();
volatile bool enableSpeedType = true;

volatile size_t speedTypeIndex = 0;

String speedTypeStr="morse code speed type";

int speedTypeFail=0;

volatile bool enableMorseFromSerial = true;
volatile bool isMorseFromSerialRunning = false;