// ============================================================================
// File:    MelodyLoader.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "audio/MelodyLoader.h"

Melody *MelodyLoader::currentMelody = nullptr;

bool MelodyLoader::loadFromFile(const char *path, Melody *melody) {
  // Parametre Hatası
  if (!melody) {
    return false;
  }
  // Stream Olarak Oku
  currentMelody = melody;
  return Filesystem::readStream(path, melodyCallback);
}

bool MelodyLoader::loadFromFile(const String &path, Melody *melody) {
  return loadFromFile(path.c_str(), melody);
}

bool MelodyLoader::melodyCallback(Stream &s) {
  // Tempo Bilgisini Oku
  if (!s.available()) {
    return false;
  }
  currentMelody->setTempo(s.read());
  // Dosyayı Oku
  while (s.available()) {
    // Frekansı Oku
    uint8_t frequencyId = s.read();
    // Süreyi Oku
    if (!s.available()) {
      return false;
    }
    uint8_t durationId = s.read();
    // Dosyaya Yaz
    if (!currentMelody->setNote(frequencyId, durationId)) {
      return false;
    }
  }
  // Hiç Notası Olmayan Melodi Dosyası Olmaz
  if (currentMelody->getLength() <= 0) {
    return false;
  }
  return true;
}
