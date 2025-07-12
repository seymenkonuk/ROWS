// ============================================================================
// File:    rows_music.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#ifndef ROWS_MUSIC_H
#define ROWS_MUSIC_H

// INCLUDES
#include "pitches.h"
#include "rows_filesystem.h"

// DEFINES
#define SPEAKER_PIN 26

// FUNCTIONS
void playMusic(String musicPath, bool loopState);
void handleMusic();
void stopMusic();
void continueMusic();
void setVolume(uint8_t level);
void volumeUp(uint8_t amount);
void volumeDown(uint8_t amount);

#endif // ROWS_MUSIC_H
