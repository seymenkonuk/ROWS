// ============================================================================
// File:    rows_music.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "rows_music.h"

static int notesFrequency[] = {NOTE_NONE, NOTE_B0,  NOTE_C1,  NOTE_CS1, NOTE_D1,  NOTE_DS1, NOTE_E1,  NOTE_F1,  NOTE_FS1, NOTE_G1,  NOTE_GS1, NOTE_A1,  NOTE_AS1, NOTE_B1,  NOTE_C2,
                               NOTE_CS2,  NOTE_D2,  NOTE_DS2, NOTE_E2,  NOTE_F2,  NOTE_FS2, NOTE_G2,  NOTE_GS2, NOTE_A2,  NOTE_AS2, NOTE_B2,  NOTE_C3,  NOTE_CS3, NOTE_D3,  NOTE_DS3,
                               NOTE_E3,   NOTE_F3,  NOTE_FS3, NOTE_G3,  NOTE_GS3, NOTE_A3,  NOTE_AS3, NOTE_B3,  NOTE_C4,  NOTE_CS4, NOTE_D4,  NOTE_DS4, NOTE_E4,  NOTE_F4,  NOTE_FS4,
                               NOTE_G4,   NOTE_GS4, NOTE_A4,  NOTE_AS4, NOTE_B4,  NOTE_C5,  NOTE_CS5, NOTE_D5,  NOTE_DS5, NOTE_E5,  NOTE_F5,  NOTE_FS5, NOTE_G5,  NOTE_GS5, NOTE_A5,
                               NOTE_AS5,  NOTE_B5,  NOTE_C6,  NOTE_CS6, NOTE_D6,  NOTE_DS6, NOTE_E6,  NOTE_F6,  NOTE_FS6, NOTE_G6,  NOTE_GS6, NOTE_A6,  NOTE_AS6, NOTE_B6,  NOTE_C7,
                               NOTE_CS7,  NOTE_D7,  NOTE_DS7, NOTE_E7,  NOTE_F7,  NOTE_FS7, NOTE_G7,  NOTE_GS7, NOTE_A7,  NOTE_AS7, NOTE_B7,  NOTE_C8,  NOTE_CS8, NOTE_D8,  NOTE_DS8};

static double notesDurations[] = {NOTE_SIXTY_FOURTH, NOTE_THIRTY_SECOND, NOTE_SIXTEENTH, NOTE_EIGHTH, NOTE_DOTTED_EIGHTH, NOTE_QUARTER, NOTE_DOTTED_QUARTER, NOTE_HALF, NOTE_WHOLE};

static uint8_t tempo;
static uint8_t notes[1000];
static uint8_t durations[1000];
static uint16_t noteCount = 0;

static bool isPlaying = false;
static bool isLooping = false;
static bool isNotePlaying;
static uint16_t currentNote;
static unsigned long noteStartTime;

static bool getMusic(String musicPath) {
  File file = FileFS.open(musicPath, "r");
  if (!file) {
    return false;
  }
  tempo = file.read();
  noteCount = 0;
  while (file.available()) {
    notes[noteCount] = file.read();
    durations[noteCount] = file.read();
    noteCount++;
  }
  file.close();
  return true;
}

static void rewindMusic() {
  currentNote = 0;
  isPlaying = true;
  isNotePlaying = false;
}

void playMusic(String musicPath, bool loopState) {
  isLooping = loopState;
  if (!getMusic(musicPath)) {
    return;
  }
  rewindMusic();
}

void stopMusic() {
  isPlaying = false;
  isNotePlaying = false;
  noTone(SPEAKER_PIN);
}

void continueMusic() {
  isPlaying = true;
  isNotePlaying = false;
}

void handleMusic() {
  unsigned long now = millis();
  int noteDuration = notesDurations[durations[currentNote]] * tempo;
  // Müzik Çalınmıyor
  if (!isPlaying) {
    return;
  }
  // Notanın Çalınması Bitmiş
  if (isNotePlaying && now - noteStartTime >= noteDuration) {
    noTone(SPEAKER_PIN);
    currentNote++;
    isNotePlaying = false;
  }
  // Müzik Bitti
  if (currentNote >= noteCount) {
    // Loop Var Mı
    if (isLooping) {
      rewindMusic();
    } else {
      isPlaying = false;
      return;
    }
  }
  // Yeni Notayı Çal
  if (!isNotePlaying) {
    // Ses Kapalıysa Ses Çıkarma
    if (notes[currentNote] < NOTE_COUNT && notesFrequency[notes[currentNote]] != NOTE_NONE) {
      tone(SPEAKER_PIN, notesFrequency[notes[currentNote]]);
    }
    isNotePlaying = true;
    noteStartTime = now;
  }
}
