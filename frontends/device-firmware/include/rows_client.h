// ============================================================================
// File:    rows_client.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#ifndef ROWS_CLIENT_H
#define ROWS_CLIENT_H

// INCLUDES
#include "rows_filesystem.h"
#include <HTTPClient.h>
#include <WiFiClientSecure.h>

// Extern
extern WiFiClientSecure wifiClient;

// FUNCTIONS
bool setupClient();
String getHTTP(String serverName);
String postHTTP(String serverName, String contentType, String postData);

#endif // ROWS_CLIENT_H
