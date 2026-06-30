// ============================================================================
// File:    MelodyLoader.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "audio/MelodyLoader.h"

#include "core/Logger.h"

Melody *MelodyLoader::currentMelody = nullptr;

bool MelodyLoader::loadFromFile(const char *path, Melody *melody) {
  LOG_INFO("Loading melody file...");
  // Parametre Hatası
  if (!melody) {
    LOG_ERROR("Parameter error: melody cannot be null.");
    return false;
  }
  // Melodi İşaretçisini Değişkene Ata
  currentMelody = melody;
  // Stream Olarak Oku
  if (!Filesystem::readStream(path, melodyCallback)) {
    LOG_ERROR("Failed to load melody file.");
    return false;
  }
  LOG_INFO("Melody file loaded successfully.");
  return true;
}

bool MelodyLoader::loadFromFile(const String &path, Melody *melody) {
  return loadFromFile(path.c_str(), melody);
}

bool MelodyLoader::melodyCallback(Stream &s) {
  // Tempo Bilgisini Oku
  if (!s.available()) {
    LOG_ERROR("Invalid melody file: failed to read tempo.");
    return false;
  }
  currentMelody->setTempo(s.read());
  // Dosyayı Oku
  while (s.available()) {
    // Frekansı Oku
    uint8_t frequencyId = s.read();
    // Süreyi Oku
    if (!s.available()) {
      LOG_ERROR("Invalid melody file: failed to read duration.");
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
    LOG_ERROR("Invalid melody file: no note data found.");
    return false;
  }
  return true;
}
