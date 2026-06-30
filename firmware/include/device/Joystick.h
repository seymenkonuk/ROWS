// ============================================================================
// File:    Joystick.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include <stdint.h>

// DEFINES
#define JOYSTICK_1_X_PIN 33
#define JOYSTICK_1_Y_PIN 32
#define JOYSTICK_2_X_PIN 35
#define JOYSTICK_2_Y_PIN 34

// CLASSES
template <uint8_t PinX, uint8_t PinY, uint8_t Deadzone = 10> class Joystick {
public:
  static void init();
  static void update();
  static int16_t x();
  static int16_t y();

private:
  static uint16_t readRaw(uint8_t pin);
  static int16_t normalize(int value);

  static int _rawX;
  static int _rawY;
  static int16_t _normX;
  static int16_t _normY;
};

#include "Joystick.tpp"
