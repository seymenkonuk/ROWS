// ============================================================================
// File:    Speaker.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include <stdint.h>

// DEFINES
#define SPEAKER_PIN 25

// CLASSES
class Speaker {
public:
  static void init();
  static void stop();
  static void stopNote();
  static void write(uint8_t data);
  static void writeNote(uint32_t data);
};
