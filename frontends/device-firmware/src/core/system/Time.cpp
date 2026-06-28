// ============================================================================
// File:    Time.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "core/system/Time.h"

#include "core/Logger.h"

#include <Arduino.h>

uint32_t Time::_lastTime = 0;
uint32_t Time::_deltaTime = 0;
uint32_t Time::_totalTime = 0;

void Time::init() {
  LOG_INFO("Initializing time...");
  _lastTime = now();
}

void Time::update() {
  uint32_t _now = now();
  _deltaTime = _now - _lastTime;
  _lastTime = _now;
  _totalTime += _deltaTime;
}

uint32_t Time::now() {
  return micros();
}

uint32_t Time::deltaMs() {
  return _deltaTime / 1000;
}

uint32_t Time::totalMs() {
  return _totalTime / 1000;
}

uint32_t Time::deltaTime() {
  return _deltaTime;
}

uint32_t Time::totalTime() {
  return _totalTime;
}
