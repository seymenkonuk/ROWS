// ============================================================================
// File:    WavFile.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include "audio/WavHeader.h"
#include "core/system/Filesystem.h"

#include <stdint.h>

// CLASSES
class WavFile {
public:
  WavHeader header;

  bool open(const char *path);
  void close();

  void rewind();
  bool isFinished();
  uint8_t read();

private:
  File file;

  bool parseHeader();
  bool checkHeader();
};
