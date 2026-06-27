// ============================================================================
// File:    MelodyLoader.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include "audio/Melody.h"

#include "core/system/Filesystem.h"

// CLASSES
class MelodyLoader {
public:
  static bool loadFromFile(const char *path, Melody *music);
  static bool loadFromFile(const String &path, Melody *music);

private:
  static bool melodyCallback(Stream &s);
  static Melody *currentMelody;
};
