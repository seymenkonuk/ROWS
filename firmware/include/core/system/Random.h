// ============================================================================
// File:    Random.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include <stdint.h>

// CLASSES
class Random {
public:
  static uint32_t next();
  static uint64_t next64();

  static uint32_t range(uint32_t max);            // [0, max)
  static int32_t range(int32_t min, int32_t max); // [min, max)

  static bool chance(uint8_t percent);
};
