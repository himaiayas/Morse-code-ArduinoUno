#include "global-flag.h"
#include "output_system.h"
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int buzzerPin = 6;
const int ledPin = 7;

void setup() {
  Serial.begin(9600);
  OutputSystem outputSys(buzzerPin, ledPin, lcd);
  Serial.print(outputSys.buzzerPin);
}

void loop() {
  // put your main code here, to run repeatedly:

}
