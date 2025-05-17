#include <Arduino.h>

#pragma once
#ifndef GLOBAL_FLAGS_H
#define GLOBAL_FLAGS_H

extern volatile bool isSpeedTypeRunning;
extern volatile unsigned long speedTypeStart;
extern volatile bool enableSpeedType;

extern volatile size_t speedTypeIndex;
extern String speedTypeStr;
extern int speedTypeFail;

extern volatile bool enableMorseFromSerial;
extern volatile bool isMorseFromSerialRunning;
#endif