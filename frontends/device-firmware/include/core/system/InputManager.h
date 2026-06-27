// ============================================================================
// File:    InputManager.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include "device/Button.h"
#include "device/Joystick.h"

// CLASSES
class InputManager {
public:
  static void init();
  static void update();

  static Button<LEFT_BUTTON_PIN> buttonLeft;
  static Button<RIGHT_BUTTON_PIN> buttonRight;
  static Button<UP_BUTTON_PIN> buttonUp;
  static Button<DOWN_BUTTON_PIN> buttonDown;

  static Button<X_BUTTON_PIN> buttonX;
  static Button<Y_BUTTON_PIN> buttonY;
  static Button<A_BUTTON_PIN> buttonA;
  static Button<B_BUTTON_PIN> buttonB;

  static Button<JOYSTICK_1_BUTTON_PIN, true> joystick1Button;
  static Button<JOYSTICK_2_BUTTON_PIN, true> joystick2Button;

  static Joystick<JOYSTICK_1_X_PIN, JOYSTICK_1_Y_PIN> joystick1;
  static Joystick<JOYSTICK_2_X_PIN, JOYSTICK_2_Y_PIN> joystick2;
};
