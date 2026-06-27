// ============================================================================
// File:    Melody.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "audio/Melody.h"

#define X(name, value) value,
uint32_t Melody::notesFrequency[] = {NOTE_FREQUENCY_LIST};
#undef X

#define X(name, value) value,
double Melody::notesDurations[] = {NOTE_DURATION_LIST};
#undef X

void Melody::setTempo(uint8_t value) {
  tempo = value;
}

bool Melody::setNote(uint8_t frequencyId, uint8_t durationId) {
  // Frekansı Ayarla
  if (!setFrequency(frequencyId, noteCount)) {
    return false;
  }
  // Duration Ayarla
  if (!setDuration(durationId, noteCount)) {
    return false;
  }
  // Notayı Sayısını Arttır
  noteCount++;
  return true;
}

bool Melody::setFrequency(uint8_t frequencyId, uint32_t index) {
  // Dizi Limitlerini Aştı
  if (index >= MAX_MELODY_SIZE) {
    return false;
  }
  // Böyle Bir Frekans Yok
  if (frequencyId >= NOTE_FREQUENCY_COUNT) {
    return false;
  }
  // Frekansı Ayarla
  frequency[index] = frequencyId;
  return true;
}

bool Melody::setDuration(uint8_t durationId, uint32_t index) {
  // Dizi Limitlerini Aştı
  if (index >= MAX_MELODY_SIZE) {
    return false;
  }
  // Böyle Bir Nota Süresi Yok
  if (durationId >= NOTE_DURATION_COUNT) {
    return false;
  }
  // Süreyi Ayarla
  durations[index] = durationId;
  return true;
}

void Melody::reset() {
  tempo = 0;
  noteCount = 0;
  currentIndex = 0;
  frequency[0] = 0;
  durations[0] = 0;
}

void Melody::resetIndex() {
  currentIndex = 0;
}

bool Melody::isFinished() {
  return currentIndex >= noteCount;
}

bool Melody::increaseIndex() {
  // Melodi Bitti (Başka Notası Kalmadı)
  if (isFinished()) {
    return false;
  }
  // Indexi Arttır
  currentIndex++;
  return true;
}

uint8_t Melody::getTempo() {
  return tempo;
}

uint32_t Melody::getLength() {
  return noteCount;
}

uint32_t Melody::getIndex() {
  return currentIndex;
}

uint32_t Melody::getCurrentFrequency() {
  return notesFrequency[frequency[currentIndex]];
}

double Melody::getCurrentDuration() {
  return notesDurations[durations[currentIndex]] * tempo;
}
