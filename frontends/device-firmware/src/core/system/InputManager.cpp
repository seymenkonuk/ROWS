// ============================================================================
// File:    InputManager.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>

// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "core/system/InputManager.h"

#include "core/Logger.h"

Button<LEFT_BUTTON_PIN> InputManager::buttonLeft;
Button<RIGHT_BUTTON_PIN> InputManager::buttonRight;
Button<UP_BUTTON_PIN> InputManager::buttonUp;
Button<DOWN_BUTTON_PIN> InputManager::buttonDown;

Button<X_BUTTON_PIN> InputManager::buttonX;
Button<Y_BUTTON_PIN> InputManager::buttonY;
Button<A_BUTTON_PIN> InputManager::buttonA;
Button<B_BUTTON_PIN> InputManager::buttonB;

Button<JOYSTICK_1_BUTTON_PIN, true> InputManager::joystick1Button;
Button<JOYSTICK_2_BUTTON_PIN, true> InputManager::joystick2Button;

Joystick<JOYSTICK_1_X_PIN, JOYSTICK_1_Y_PIN> InputManager::joystick1;
Joystick<JOYSTICK_2_X_PIN, JOYSTICK_2_Y_PIN> InputManager::joystick2;

void InputManager::init() {
  LOG_INFO("Initializing inputs...");
  buttonLeft.init();
  buttonRight.init();
  buttonUp.init();
  buttonDown.init();
  buttonX.init();
  buttonY.init();
  buttonA.init();
  buttonB.init();
  joystick1Button.init();
  joystick2Button.init();
  joystick1.init();
  joystick2.init();
}

void InputManager::update() {
  buttonLeft.update();
  buttonRight.update();
  buttonUp.update();
  buttonDown.update();
  buttonX.update();
  buttonY.update();
  buttonA.update();
  buttonB.update();
  joystick1Button.update();
  joystick2Button.update();
  joystick1.update();
  joystick2.update();
}
