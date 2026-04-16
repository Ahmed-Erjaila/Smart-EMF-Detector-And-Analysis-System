#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <IRremote.h> 

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Hardware mapping
const int coilPin = A0;
const int ledPin = 13;
const int speakerPin = 8;
const int buttonPin = 7;
const int irPin = 10;

int baseline = 0;
bool systemActive = false;
bool calibrated = false;
bool lastBtnState = HIGH;

// Signal processing for speaker output
void playSpeaker(int frequency, int duration) {
  long period = 1000000L / frequency;
  long startTime = millis();
  while (millis() - startTime < duration) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(period / 2);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(period / 2);
  }
}
