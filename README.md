## Student Information
- *Name:* Ahmed M. A. Erjaila
- *Student ID:* 220202901
- *Department:* Electrical and Electronics Engineering
- *University:* Ostim Technical University

## Project Objective
An advanced embedded system developed to sense and classify AC electromagnetic fields (EMF) using a C-programmed ATmega328P microcontroller (Arduino Uno).

## Module Breakdown
1. *Sensing Module:* Custom-built hybrid inductive sensor (Coil + Iron Core).
2. *Processing Module:* Real-time signal sampling and Peak Detection logic via ADC.
3. *Display Module:* 16x2 LCD interface using I2C communication protocol for real-time data visualization.
4. *Alert Module:* Multi-step audible feedback (Buzzer) based on signal intensity levels.

## Hardware Components
- Arduino Uno (ATmega328P)
- I2C LCD 1602
- Speaker
- Custom Probe (Copper Wire + Iron Core)
- 100k Ohm Resistor (Pull-down)
- Tactical Push Button
- IR Receiver
- remote
- ## Workload Distribution
- *Responsible Student:* Ahmed M. A. Erjaila (Individual Project)
- *Role:* Full system design, hardware fabrication (inductive sensor), C-firmware development, and circuit integration.

## Phase 1: Design & Simulate Strategy
The Problem:
During the design phase with Proteus, we noticed that the simulation process does not simulate real life EMFs. An antenna floating inside an electronic environment will not be able to detect the necessary ambient noise (50/60 Hz) for activating the sensor.
The Solution:
Before moving on to the programming stage, we will replace our real-life coil with a 10K potentiometer.
Objective:
This will allow us to feed the pin (A0) with different levels of voltage ranging from 0V to 5V.
Validation:
We can now use this system to test our threshold logic and verify if our buzzer/LCD code works.
