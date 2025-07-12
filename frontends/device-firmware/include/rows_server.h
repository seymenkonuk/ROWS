// ============================================================================
// File:    rows_server.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#ifndef ROWS_SERVER_H
#define ROWS_SERVER_H

// INCLUDES
#include "rows_filesystem.h"
#include "rows_wifi.h"
#include <WebServer.h>

// EXTERN
extern WebServer server;

// FUNCTIONS
bool setupWebServer();

#endif // ROWS_SERVER_H
