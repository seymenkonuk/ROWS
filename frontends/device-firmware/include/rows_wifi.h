// ============================================================================
// File:    rows_wifi.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#ifndef ROWS_WIFI_H
#define ROWS_WIFI_H

// INCLUDES
#include "rows_filesystem.h"
#include <WiFi.h>
#include <string.h>

// FUNCTIONS
bool setupWifi();
bool connectWifi();
bool startAP();

#endif // ROWS_WIFI_H
