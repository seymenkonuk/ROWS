// ============================================================================
// File:    Filesystem.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include <LittleFS.h>

// CLASSES
class Filesystem {
  typedef bool (*StreamHandler)(Stream &stream);

public:
  static bool init();

  static File open(const char *path, const char *mode);
  static File open(const String &path, const char *mode);

  static bool write(const char *path, const char *text);
  static bool write(const char *path, const String &text);
  static bool write(const String &path, const char *text);
  static bool write(const String &path, const String &text);

  static bool append(const char *path, const char *text);
  static bool append(const char *path, const String &text);
  static bool append(const String &path, const char *text);
  static bool append(const String &path, const String &text);

  static String read(const char *path);
  static String read(const String &path);

  static bool readStream(const char *path, StreamHandler handler);
  static bool readStream(const String &path, StreamHandler handler);

private:
  static bool change(const char *path, const char *text, const char *mode);
  static bool change(const char *path, const String &text, const char *mode);
  static bool change(const String &path, const char *text, const char *mode);
  static bool change(const String &path, const String &text, const char *mode);
};
