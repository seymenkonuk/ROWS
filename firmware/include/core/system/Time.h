// ============================================================================
// File:    Time.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include <stdint.h>

// CLASSES
class Time {
public:
  static void init();
  static void update();

  static uint32_t now();

  static uint32_t deltaTime();
  static uint32_t totalTime();

  static uint32_t deltaMs();
  static uint32_t totalMs();

private:
  static uint32_t _lastTime;
  static uint32_t _deltaTime;
  static uint32_t _totalTime;
};
