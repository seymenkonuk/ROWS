// ============================================================================
// File:    MusicPlayer.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include "audio/WavHeader.h"

#include "core/system/Filesystem.h"
#include "core/system/Timer.h"

// CLASSES
class MusicPlayer {
public:
  static void init();
  static bool play(const char *path, bool loopState);
  static bool play(const String &path, bool loopState);
  static void rewind();
  static void stop();
  static void pause();
  static void resume();

private:
  static QueueHandle_t queue;
  static Timer<0> *timer;

  static File wavFile;
  static WavHeader wavHeader;

  static bool isPlaying;
  static bool isLooping;

  static void onTimer();
  static void playSample();
  static void loopTask(void *p);

  static bool openFile(const char *path);
  static void closeFile();
  static bool parseWavHeader();
  static void resetFilePosition();
  static bool hasMoreSamples();
  static uint8_t readSample();
};
