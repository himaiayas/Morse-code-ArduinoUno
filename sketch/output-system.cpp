#include "output_system.h"

OutputSystem::OutputSystem(int buzzerPin, int ledPin, LiquidCrystal lcdDisplay):
  buzzerPin(buzzerPin),
  ledPin(ledPin),
  lcdDisplay(lcdDisplay)
  {};