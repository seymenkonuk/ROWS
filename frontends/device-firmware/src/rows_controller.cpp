// ============================================================================
// File:    rows_controller.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "rows_controller.h"

static bool oldIsTouch = false;

bool setupController() {
#ifndef TOUCH_SCREEN
  pinMode(LEFT_BUTTON_PIN, INPUT_PULLDOWN);
  pinMode(RIGHT_BUTTON_PIN, INPUT_PULLDOWN);
  pinMode(DOWN_BUTTON_PIN, INPUT_PULLDOWN);
  pinMode(UP_BUTTON_PIN, INPUT_PULLDOWN);
  pinMode(A_BUTTON_PIN, INPUT_PULLDOWN);
  pinMode(B_BUTTON_PIN, INPUT_PULLDOWN);
#endif
  return true;
}

static controller_button getPressedButtonTouchableScreen() {
  uint16_t x, y;
  bool isTouch = isScreenTouched(&x, &y);

  // State Değişmedi
  if (oldIsTouch == isTouch) {
    return NONE_BUTTON;
  }

  oldIsTouch = isTouch;

  // Ekrana Basmıyor
  if (!isTouch) {
    return NONE_BUTTON;
  }

  // Sola Basılıyor
  if (x <= SCREEN_WIDTH / 4) {
    return (y <= SCREEN_HEIGHT / 4 || y >= 3 * SCREEN_HEIGHT / 4) ? NONE_BUTTON : LEFT_BUTTON;
  }

  // Sağa Basılıyor
  if (x >= 3 * SCREEN_WIDTH / 4) {
    return (y <= SCREEN_HEIGHT / 4 || y >= 3 * SCREEN_HEIGHT / 4) ? NONE_BUTTON : RIGHT_BUTTON;
  }

  // Yukarı Basılıyor
  if (y <= SCREEN_HEIGHT / 4) {
    return UP_BUTTON;
  }

  // AŞAĞI Basılıyor
  if (y >= 3 * SCREEN_HEIGHT / 4) {
    return DOWN_BUTTON;
  }

  // Ortaya Basılıyor
  return A_BUTTON;
}

static controller_button getPressedButtonNonTouchScreen() {
  bool isTouch;
  int leftState = digitalRead(LEFT_BUTTON_PIN);
  int rightState = digitalRead(RIGHT_BUTTON_PIN);
  int downState = digitalRead(DOWN_BUTTON_PIN);
  int upState = digitalRead(UP_BUTTON_PIN);
  int aButtonState = digitalRead(A_BUTTON_PIN);
  int bButtonState = digitalRead(B_BUTTON_PIN);
  int buttonState = 0;

  // Hangi Butonlara Basılıyor
  buttonState += leftState << 5;
  buttonState += rightState << 4;
  buttonState += downState << 3;
  buttonState += upState << 2;
  buttonState += aButtonState << 1;
  buttonState += bButtonState << 0;

  // Herhangi Bir Butona Basılıyorsa
  isTouch = buttonState != 0;

  // State Değişmedi
  if (oldIsTouch == isTouch) {
    return NONE_BUTTON;
  }

  oldIsTouch = isTouch;

  // Ekrana Basmıyor
  if (!isTouch) {
    return NONE_BUTTON;
  }

  // Birden Fazla Butona Basmaması Lazım
  switch (buttonState) {
  case 0b100000:
    return LEFT_BUTTON;
  case 0b010000:
    return RIGHT_BUTTON;
  case 0b001000:
    return DOWN_BUTTON;
  case 0b000100:
    return UP_BUTTON;
  case 0b000010:
    return A_BUTTON;
  case 0b000001:
    return B_BUTTON;
  }

  return NONE_BUTTON;
}

controller_button getPressedButton() {
#ifdef TOUCH_SCREEN
  return getPressedButtonTouchableScreen();
#else
  return getPressedButtonNonTouchScreen();
#endif
}
