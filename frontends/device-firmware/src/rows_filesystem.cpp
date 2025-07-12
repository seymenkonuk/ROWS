// ============================================================================
// File:    rows_filesystem.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "rows_filesystem.h"

bool setupFileSystem() {
  return FileFS.begin(false);
}

static bool changeFile(const char *path, const char *text, const char *mode) {
  File file = FileFS.open(path, mode);
  if (!file) {
    return false;
  }
  file.print(text);
  file.close();
  return true;
}

bool writeFile(const char *path, const char *text) {
  return changeFile(path, text, "w");
}

bool appendFile(const char *path, const char *text) {
  return changeFile(path, text, "a");
}

String readFile(const char *path) {
  File file = FileFS.open(path, "r");
  String content = "";

  if (!file) {
    return "";
  }

  // Dosyanın tamamını okuyoruz
  while (file.available()) {
    content += (char)file.read();
    yield();
  }

  file.close();
  return content;
}
