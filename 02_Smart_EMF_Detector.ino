/** EMF DETECTOR LOGIC- FINAL TEST
  * AUTHORED BY AHMED M. A. ERJAILA
  */

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
}void setup() {
  Serial.begin(9600); 
  lcd.init();
  lcd.noBacklight();
  
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  IrReceiver.begin(irPin);
  
  Serial.println("System initiated..."); 
}

void loop() {
  // Remote logic
  if (IrReceiver.decode()) {
    unsigned long cmd = IrReceiver.decodedIRData.command;
    if (cmd == 70) {
      if(systemActive) stopSys(); else startSys();
    } else if (cmd == 69 && systemActive) {
      runCalib();
    }
    IrReceiver.resume();
  }

  // Button logic (Manual override)
  bool btnState = digitalRead(buttonPin);
  if (btnState == LOW && lastBtnState == HIGH) {
    if (!systemActive) {
      startSys();
      runCalib();
    } else {
      stopSys();
    }
    delay(250); 
  }
  lastBtnState = btnState;

  if (!systemActive || !calibrated) return;

  // Signal Capture
  int peak = 0;
  for (int i = 0; i < 160; i++) { 
    int val = analogRead(coilPin);
    if (val > peak) peak = val;
  }

  int s = peak - baseline;
  if (s < 0) s = 0;

  // Output Rendering
  lcd.setCursor(0, 0);
  lcd.print("SIGNAL: "); lcd.print(s); lcd.print("    ");
  lcd.setCursor(0, 1);

  if (s < 75) {
    lcd.print("SCANNING...     ");
    digitalWrite(ledPin, LOW);
    digitalWrite(speakerPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
    // Dynamic feedback speed
    int pulse = (s < 200) ? 850 : (s < 500) ? 420 : 160; 
    if(s < 200) lcd.print("LEVEL: WEAK    ");
    else if(s < 500) lcd.print("LEVEL: MEDIUM  ");
    else lcd.print("LEVEL: STRONG  ");
    
    // Fixed: Passing only 2 arguments
    playSpeaker(800 + s, 25);
    delayMicroseconds(pulse);
    
  }
}
// System Functions
void startSys() {
  systemActive = true; calibrated = false;
  lcd.backlight(); lcd.clear();
  lcd.setCursor(2, 0); lcd.print("EMF DETECTOR");
  lcd.setCursor(1, 1); lcd.print("AHMED ERJAILA");
  
  // Fixed: Passing only 2 arguments
  for (int f = 600; f < 1800; f += 200) { playSpeaker(f, 50); }
  
  delay(1000); 
  lcd.clear();
  lcd.print("READY TO SCAN");
}

void runCalib() {
  calibrated = true;
  lcd.clear(); lcd.print("CALIBRATING...");
  long sum = 0;
  for (int i = 0; i < 480; i++) { 
    sum += analogRead(coilPin);
    delay(2);
  }
  baseline = sum / 480;
  
  // Fixed: Passing only 2 arguments
  playSpeaker(1600, 150);
  delay(50);
  playSpeaker(1600, 150);
  
  lcd.clear();
  lcd.print("BASE SET: "); lcd.print(baseline);
  delay(900);
}

void stopSys() {
  systemActive = false; calibrated = false;
  digitalWrite(ledPin, LOW); 
  lcd.clear(); lcd.print("POWERING OFF...");
  
  // Fixed: Passing only 2 arguments
  for (int f = 1800; f > 600; f -= 200) { playSpeaker(f, 50); }
  
  delay(600);
  lcd.noBacklight(); lcd.clear();
}
