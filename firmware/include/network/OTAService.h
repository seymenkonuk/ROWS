// ============================================================================
// File:    OTAService.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include "network/APIResponse.h"

// DEFINES
#define OTA_SERVICE_PROTOCOL "https://"
#define OTA_SERVICE_HOST "ota.rows.local"
#define OTA_SERVICE_PORT "3000"

#define OTA_SERVICE_BASE_URL OTA_SERVICE_PROTOCOL OTA_SERVICE_HOST ":" OTA_SERVICE_PORT "/api/v1"

#define OTA_SERVICE_GET_NEW_VERSION_PATH "/update/version"
#define OTA_SERVICE_GET_FIRMWARE_PATH "/update/download"

#define OTA_SERVICE_GET_NEW_VERSION_URL OTA_SERVICE_BASE_URL OTA_SERVICE_GET_NEW_VERSION_PATH
#define OTA_SERVICE_GET_FIRMWARE_URL OTA_SERVICE_BASE_URL OTA_SERVICE_GET_FIRMWARE_PATH

// CLASSES
class OTAService {
public:
  static void init();
  static bool check();
  static bool update();

private:
  static String currentSoftwareVersion;
  static String newSoftwareVersion;
  static bool updateCallback(const APIResponse &res);
};
