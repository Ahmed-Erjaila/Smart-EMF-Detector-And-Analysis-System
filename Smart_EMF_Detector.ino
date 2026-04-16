#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <IRremote.h> 

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Hardware mapping
const int coilPin = A0;
const int ledPin = 13;
const int buzzerPin = 8;
const int buttonPin = 7;
const int irPin = 10;

int baseline = 0;
bool systemActive = false;
bool calibrated = false;
bool lastBtnState = HIGH;

void setup() {
  Serial.begin(9600); // Added for debugging like a real dev
  lcd.init();
  lcd.noBacklight();
  
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  IrReceiver.begin(irPin);
  
  Serial.println("System initiated..."); 
}
