// ============================================================================
// File:    rows_filesystem.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#ifndef ROWS_FILESYSTEM_H
#define ROWS_FILESYSTEM_H

// INCLUDES
#include <LittleFS.h>

// DEFINES
#define FileFS LittleFS

// FUNCTIONS
bool setupFileSystem();
bool writeFile(const char *path, const char *text);
bool appendFile(const char *path, const char *text);
String readFile(const char *path);

#endif // ROWS_FILESYSTEM_H
