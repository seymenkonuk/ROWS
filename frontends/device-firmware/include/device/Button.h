// ============================================================================
// File:    Button.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include <stdint.h>

// DEFINES
#define LEFT_BUTTON_PIN 12
#define RIGHT_BUTTON_PIN 27
#define DOWN_BUTTON_PIN 14
#define UP_BUTTON_PIN 13

#define X_BUTTON_PIN 22
#define Y_BUTTON_PIN 16
#define A_BUTTON_PIN 17
#define B_BUTTON_PIN 15

#define JOYSTICK_1_BUTTON_PIN 26
#define JOYSTICK_2_BUTTON_PIN 21

// CLASSES
template <uint8_t Pin, bool Pullup = false, uint16_t DebounceMs = 20> class Button {
public:
  static void init();
  static void update();
  static bool pressed();
  static bool released();
  static bool held();

private:
  static bool readRaw();

  static bool _state;
  static bool _lastRaw;
  static bool _changed;
  static uint32_t _lastChangeTime;
};

#include "Button.tpp"
