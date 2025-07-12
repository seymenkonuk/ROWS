// ============================================================================
// File:    rows_random.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "rows_random.h"

static uint8_t getBitLength(uint32_t number) {
  uint8_t result;
  result = 0;
  do {
    number = number >> 1;
    result++;
  } while (number > 0);
  return result;
}

static uint32_t generateRandBit() {
  return esp_random() % 2;
}

static uint32_t generateRandBits(uint8_t bitLength) {
  uint32_t result;
  result = 0;
  while (bitLength > 0) {
    result = (result << 1) + generateRandBit();
    bitLength--;
  }
  return result;
}

static uint32_t generateRand(uint32_t max) {
  uint32_t result;
  uint8_t bitLength;
  bitLength = getBitLength(max);
  do {
    result = generateRandBits(bitLength);
  } while (result > max);
  return result;
}

static int32_t _generateRandom(int32_t min, int32_t max) {
  if (min > max) {
    return _generateRandom(max, min);
  }
  return min + (int32_t)generateRand(max - min);
}

int32_t generateRandom(int32_t min, int32_t max) {
  return _generateRandom(min, max - 1);
}
