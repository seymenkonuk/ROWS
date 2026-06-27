// ============================================================================
// File:    Joystick.tpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "device/Joystick.h"

#include <Arduino.h>

template <uint8_t PinX, uint8_t PinY, uint8_t Deadzone> int Joystick<PinX, PinY, Deadzone>::_rawX = 0;
template <uint8_t PinX, uint8_t PinY, uint8_t Deadzone> int Joystick<PinX, PinY, Deadzone>::_rawY = 0;
template <uint8_t PinX, uint8_t PinY, uint8_t Deadzone> int16_t Joystick<PinX, PinY, Deadzone>::_normX = 0;
template <uint8_t PinX, uint8_t PinY, uint8_t Deadzone> int16_t Joystick<PinX, PinY, Deadzone>::_normY = 0;

template <uint8_t PinX, uint8_t PinY, uint8_t Deadzone> void Joystick<PinX, PinY, Deadzone>::init() {
  pinMode(PinX, INPUT);
  pinMode(PinY, INPUT);
}

template <uint8_t PinX, uint8_t PinY, uint8_t Deadzone> void Joystick<PinX, PinY, Deadzone>::update() {
  _rawX = readRaw(PinX);
  _rawY = readRaw(PinY);

  _normX = normalize(_rawX);
  _normY = normalize(_rawY);
}

template <uint8_t PinX, uint8_t PinY, uint8_t Deadzone> int16_t Joystick<PinX, PinY, Deadzone>::x() {
  return _normX;
}

template <uint8_t PinX, uint8_t PinY, uint8_t Deadzone> int16_t Joystick<PinX, PinY, Deadzone>::y() {
  return _normY;
}

template <uint8_t PinX, uint8_t PinY, uint8_t Deadzone> uint16_t Joystick<PinX, PinY, Deadzone>::readRaw(uint8_t pin) {
  return analogRead(pin);
}

template <uint8_t PinX, uint8_t PinY, uint8_t Deadzone> int16_t Joystick<PinX, PinY, Deadzone>::normalize(int value) {
  int16_t centered = value - 2048;

  if (abs(centered) < Deadzone)
    return 0;

  return centered;
}
