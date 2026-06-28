// ============================================================================
// File:    Random.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "core/system/Random.h"

#include "core/Logger.h"

#include <esp_system.h>

uint32_t Random::next() {
  return esp_random();
}

uint64_t Random::next64() {
  uint64_t high = (uint64_t)next() << 32;
  uint64_t low = next();
  return high | low;
}

uint32_t Random::range(uint32_t max) {
  // Parametre Hatası
  if (max == 0) {
    LOG_ERROR("Parameter error: value cannot be zero");
    return 0;
  }

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
    LOG_ERROR("Parameter error: min cannot be greater than or equal to max (min: %d, max: %d)", min, max);
    return min;
  }
  // Rastgele Üret
  uint32_t diff = (uint32_t)(max - min);
  return min + (int32_t)range(diff);
}

bool Random::chance(uint8_t percent) {
  // Parametre Hatası
  if (percent > 100) {
    LOG_WARN("Parameter error: chance percentage cannot be greater than 100 (provided: %u)", percent);
    return true;
  }

  if (percent == 0)
    return false;

  return range(100) < percent;
}
