// ============================================================================
// File:    rows_ota.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#ifndef ROWS_OTA_H
#define ROWS_OTA_H

// INCLUDES
#include "HardwareSerial.h"
#include "rows_api.h"
#include "rows_client.h"
#include "rows_filesystem.h"
#include "rows_menu.h"
#include <HTTPClient.h>
#include <Update.h>
#include <WiFiClient.h>

// DEFINES
#define OTA_SERVICE_PROTOCOL "https://"
#define OTA_SERVICE_HOST SERVER_DOMAIN
#define OTA_SERVICE_PORT "8443"

#define OTA_SERVICE_BASE_URL OTA_SERVICE_PROTOCOL OTA_SERVICE_HOST ":" OTA_SERVICE_PORT "/api/v1"

#define OTA_SERVICE_GET_LATEST_VERSION_PATH "/update/getLatestVersion"
#define OTA_SERVICE_GET_FIRMWARE_PATH "/update/download"

#define OTA_SERVICE_GET_LATEST_VERSION_URL OTA_SERVICE_BASE_URL OTA_SERVICE_GET_LATEST_VERSION_PATH
#define OTA_SERVICE_GET_FIRMWARE_URL OTA_SERVICE_BASE_URL OTA_SERVICE_GET_FIRMWARE_PATH

// EXTERN
extern String currentSoftwareVersion;

// FUNCTIONS
bool setupOTA();
bool checkOTAandUpdate();

#endif // ROWS_OTA_H
