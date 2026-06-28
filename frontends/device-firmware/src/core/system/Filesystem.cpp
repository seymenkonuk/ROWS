// ============================================================================
// File:    Filesystem.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "core/system/Filesystem.h"

bool Filesystem::init() {
  return LittleFS.begin(false);
}

File Filesystem::open(const char *path, const char *mode) {
  return LittleFS.open(path, mode);
}

File Filesystem::open(const String &path, const char *mode) {
  return LittleFS.open(path, mode);
}

bool Filesystem::change(const char *path, const char *text, const char *mode) {
  File file = open(path, mode);
  // Dosya Açılamadı
  if (!file) {
    return false;
  }
  // Dosyaya Yaz
  file.print(text);
  file.close();
  return true;
}

bool Filesystem::change(const char *path, const String &text, const char *mode) {
  return change(path, text.c_str(), mode);
}

bool Filesystem::change(const String &path, const char *text, const char *mode) {
  return change(path.c_str(), text, mode);
}

bool Filesystem::change(const String &path, const String &text, const char *mode) {
  return change(path.c_str(), text.c_str(), mode);
}

bool Filesystem::write(const char *path, const char *text) {
  return change(path, text, "w");
}

bool Filesystem::write(const char *path, const String &text) {
  return change(path, text, "w");
}

bool Filesystem::write(const String &path, const char *text) {
  return change(path, text, "w");
}

bool Filesystem::write(const String &path, const String &text) {
  return change(path, text, "w");
}

bool Filesystem::append(const char *path, const char *text) {
  return change(path, text, "a");
}

bool Filesystem::append(const char *path, const String &text) {
  return change(path, text, "a");
}

bool Filesystem::append(const String &path, const char *text) {
  return change(path, text, "a");
}

bool Filesystem::append(const String &path, const String &text) {
  return change(path, text, "a");
}

String Filesystem::read(const char *path) {
  File file = open(path, "r");
  String content = "";

  // Dosya Açılamadı
  if (!file) {
    return content;
  }

  // Dosyanın Tamamını Okuyoruz
  while (file.available()) {
    content += (char)file.read();
    yield();
  }

  file.close();
  return content;
}

String Filesystem::read(const String &path) {
  return read(path.c_str());
}

bool Filesystem::readStream(const char *path, StreamHandler handler) {
  // Parametre Hatası
  if (!handler) {
    return false;
  }

  File file = open(path, "r");

  // Dosya Açılamadı
  if (!file) {
    return false;
  }

  // Handle
  bool result = handler(file);

  file.close();
  return result;
}

bool Filesystem::readStream(const String &path, StreamHandler handler) {
  return readStream(path.c_str(), handler);
}
