// ============================================================================
// File:    MusicPlayer.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "device/Speaker.h"

#include "core/Logger.h"

#include <Arduino.h>

void Speaker::init() {
  LOG_INFO("Initializing speaker...");
  pinMode(SPEAKER_PIN, OUTPUT);
}

void Speaker::write(uint8_t data) {
  dacWrite(SPEAKER_PIN, data);
}

void Speaker::writeNote(uint32_t data) {
  tone(SPEAKER_PIN, data);
}

void Speaker::stop() {
  dacWrite(SPEAKER_PIN, 0);
}

void Speaker::stopNote() {
  noTone(SPEAKER_PIN);
}
