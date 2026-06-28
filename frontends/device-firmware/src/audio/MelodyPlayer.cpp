// ============================================================================
// File:    MelodyPlayer.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "audio/MelodyPlayer.h"

#include "audio/MelodyLoader.h"

#include "core/Logger.h"
#include "core/system/Time.h"

#include "device/Speaker.h"

#include <Arduino.h>

Melody MelodyPlayer::melody;
bool MelodyPlayer::isPlaying = false;
bool MelodyPlayer::isLooping = false;
bool MelodyPlayer::isNotePlaying = false;
uint32_t MelodyPlayer::noteStartTime;

void MelodyPlayer::init() {
  LOG_INFO("Initializing melody player...");
}

bool MelodyPlayer::play(const char *path, bool loopState) {
  isLooping = loopState;
  LOG_INFO("Playing melody: %s", path);
  // Melodiyi Dosyadan Oku
  if (!MelodyLoader::loadFromFile(path, &melody)) {
    LOG_ERROR("Audio play failed: Could not load file %s", path);
    return false;
  }
  // Başa Sar
  rewind();
  return true;
}

bool MelodyPlayer::play(const String &path, bool loopState) {
  return play(path.c_str(), loopState);
}

void MelodyPlayer::rewind() {
  melody.resetIndex();
  isPlaying = true;
  isNotePlaying = false;
}

void MelodyPlayer::stop() {
  melody.resetIndex();
  pause();
}

void MelodyPlayer::pause() {
  isPlaying = false;
  isNotePlaying = false;
  Speaker::stopNote();
}

void MelodyPlayer::resume() {
  isPlaying = true;
  isNotePlaying = false;
}

void MelodyPlayer::loop() {
  // Gerekli Bilgileri Oku
  uint32_t now = Time::now();
  double noteDuration = melody.getCurrentDuration();
  uint32_t noteFrequency = melody.getCurrentFrequency();
  // Müzik Çalınmıyor
  if (!isPlaying) {
    return;
  }
  // Nota Yeterince Süre Çalmış
  if (isNotePlaying && now - noteStartTime >= noteDuration) {
    // Nota Çalmayı Durdur
    Speaker::stopNote();
    isNotePlaying = false;
    // Müzik Bittiyse Başa Al
    if (melody.isFinished() && isLooping) {
      rewind();
      return;
    }
    // Müzik Bittiyse Durdur
    if (melody.isFinished() && !isLooping) {
      LOG_INFO("Melody finished.");
      stop();
      return;
    }
    // Bir Sonraki Notaya Geç
    melody.increaseIndex();
  }
  // Yeni Nota Çal
  if (!isNotePlaying) {
    Speaker::writeNote(noteFrequency);
    isNotePlaying = true;
    noteStartTime = now;
  }
}
