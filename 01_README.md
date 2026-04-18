## Student Information
- *Name:* Ahmed M. A. Erjaila
- *Student ID:* 220202901
- *Department:* Electrical and Electronics Engineering
- *University:* Ostim Technical University

## Project Objective
An advanced embedded system developed to sense and classify AC electromagnetic fields (EMF) using a C++-programmed ATmega328P microcontroller (Arduino Uno).

## Module Breakdown
1. *Sensing Module:* Custom-built hybrid inductive sensor (Coil + Iron Core).
2. *Processing Module:* Real-time signal sampling and Peak Detection logic via ADC.
3. *Display Module:* 16x2 LCD interface using I2C communication protocol for real-time data visualization.
4. *Alert Module:* Multi-step audible feedback (Buzzer) based on signal intensity levels.

## Hardware Components
- Arduino Uno (ATmega328P)
- RED-LED
- 330ohm-Resistor
- I2C LCD 1602
- Speaker
- Custom Probe (Copper Wire + Iron Core)
- 100k Ohm Resistor (Pull-down)
- Tactical Push Button
- IR Receiver
- remote
- ## Workload Distribution
- *Responsible Student:* Ahmed M. A. Erjaila (Individual Project)
- *Role:* Full system design, hardware fabrication (inductive sensor), C++-firmware development, and circuit integration.

## Challenges and Sulutions
### 1. Simulation Limitations (proteus)
**Challenge:**
During the design phase with Proteus, we noticed that the simulation process does not simulate real life EMFs. An antenna floating inside an electronic environment will not be able to detect the necessary ambient noise (50/60 Hz) for activating the sensor. *
 **Solution:**
Before moving on to the programming stage, we will replace our real-life coil with a **10K potentiometer**.

### 2. IR Signal Interference and Audio Upgrade
**Challenge:** When connecting the IR Receiver and Remote Control together, there was an issue of conflicting signals. The Buzzer produced electronic noise and timing conflicts, which affected the IR sensor’s ability to interpret the commands sent by the remote control. In addition, the frequency of the buzz emitted when the buzzer is operated manually is too shrill and unpleasant to the user's ears.
**Solution:** To fix this problem and enhance the performance of the system, we upgraded the audio component of the circuit. Instead of using the buzzer, we substituted it with a Speaker.

### 3. Voice Commands and Audio Amplification Issues
**Challenge:** Our attempt to use voice commands (such as “System ON”) with the help of a specific Arduino library failed, as the output was hard to hear and sounded like noise. Using a resistor to reduce noise levels as well as incorporating a Motor Driver by using its internal transistors as an amplifier did not result in intelligible speech. Limitations in the components prevented successful outputting of voices due to insufficient speaker driving capabilities.
**Solution:** In order to keep the audio feedback feature alive while avoiding any complications related to the construction of a new audio amplifier, we resorted to playing different melodies through a speaker instead. We created our own code for melodies to make sure they are simple enough and would not conflict with the infrared remote protocol memory constraints

### 4. High Sensitivity and Effects of Ambient Noise
**Challenge:** In order to make sure that the device will be able to detect any weak signal of EMF, we made the sensitivity of the device extremely high. This however, resulted in the device being "too sensitive" and hence, was picking up stray signals in the form of static electricity from our bodies, as well as electronic interference from the surrounding environment.
**Solution:** Our solution to this problem is through a Calibration Step when starting up the device. The device detects the noise signal in the environment when it is powered up, and after a few seconds, this is taken as the offset. This offset value is then deducted from all readings in the code.
