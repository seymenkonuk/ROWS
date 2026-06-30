// ============================================================================
// File:    Timer.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include <Arduino.h>
#include <stdint.h>

// CLASSES
template <uint8_t timerId> class Timer {
private:
  hw_timer_t *timer = nullptr;
  void (*callback)() = nullptr;

  bool isLocked = false;

  static Timer<timerId> *instance;
  static void IRAM_ATTR onTimerStatic();

  Timer() {};

public:
  static Timer<timerId> *create();

  void init(uint16_t prescaler, void (*cb)());
  void start(uint32_t period_us);
  void stop();
  void lock();
};

#include "Timer.tpp"
