// ============================================================================
// File:    Random.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include <esp_system.h>

#include "core/system/Random.h"

uint32_t Random::next() {
  return esp_random();
}

uint64_t Random::next64() {
  uint64_t high = (uint64_t)next() << 32;
  uint64_t low = next();
  return high | low;
}

uint32_t Random::range(uint32_t max) {
  if (max == 0)
    return 0;

  uint32_t threshold = -max % max;

  while (true) {
    uint32_t r = next();
    if (r >= threshold)
      return r % max;
  }
}

int32_t Random::range(int32_t min, int32_t max) {
  // Parametre Hatası
  if (min >= max) {
    return min;
  }
  // Rastgele Üret
  uint32_t diff = (uint32_t)(max - min);
  return min + (int32_t)range(diff);
}

bool Random::chance(uint8_t percent) {
  // Parametre Hatası
  if (percent >= 100) {
    return true;
  }

  if (percent == 0)
    return false;

  return range(100) < percent;
}
