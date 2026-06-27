// ============================================================================
// File:    MelodyPlayer.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include <Arduino.h>

#include "audio/Melody.h"

// CLASSES
class MelodyPlayer {
public:
  static void init();
  static bool play(const char *path, bool loopState);
  static bool play(const String &path, bool loopState);
  static void rewind();
  static void stop();
  static void pause();
  static void resume();
  static void loop();

private:
  static Melody melody;
  static bool isPlaying;
  static bool isLooping;
  static bool isNotePlaying;
  static uint32_t noteStartTime;
};
