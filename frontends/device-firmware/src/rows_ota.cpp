// ============================================================================
// File:    rows_ota.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "rows_ota.h"

String currentSoftwareVersion;

bool setupOTA() {
  currentSoftwareVersion = readFile("/info/VERSION");
  return true;
}

static String fetchLatestVersion() {
  return postHTTP(OTA_SERVICE_GET_LATEST_VERSION_URL, "plain/text", currentSoftwareVersion);
}

static bool isUpdateNeeded(const String &latestVersion) {
  return latestVersion != "" && latestVersion != currentSoftwareVersion;
}

static bool beginFirmwareDownload(HTTPClient &https) {
  https.begin(wifiClient, OTA_SERVICE_GET_FIRMWARE_URL);
  https.addHeader("Content-Type", "plain/text");
  int httpCode = https.POST(currentSoftwareVersion);
  return httpCode == HTTP_CODE_OK;
}

static bool validateContent(HTTPClient &https, int &contentLength) {
  contentLength = https.getSize();
  return contentLength > 0 && Update.begin(contentLength);
}

static bool writeFirmwareToMemory(HTTPClient &https, int contentLength) {
  WiFiClient *stream = https.getStreamPtr();
  size_t totalWritten = 0;

  while (totalWritten < contentLength) {
    size_t written = Update.writeStream(*stream);
    totalWritten += written;
    yield();
    if (written == 0) {
      return false;
    }
  }

  return totalWritten == contentLength;
}

static bool finalizeFirmwareUpdate(const String &latestVersion) {
  if (!Update.end()) {
    return false;
  }
  writeFile("/info/VERSION", latestVersion.c_str());
  return true;
}

static bool downloadAndWriteFirmware(const String &latestVersion) {
  HTTPClient https;
  if (!beginFirmwareDownload(https)) {
    https.end();
    return false;
  }
  int contentLength;
  if (!validateContent(https, contentLength)) {
    https.end();
    return false;
  }

  if (!writeFirmwareToMemory(https, contentLength)) {
    https.end();
    return false;
  }

  https.end();

  if (!finalizeFirmwareUpdate(latestVersion)) {
    return false;
  }

  return true;
}

bool checkOTAandUpdate() {
  String latestVersion = fetchLatestVersion();
  // Bağlantı veya sunucu hatası
  if (latestVersion == "") {
    return false;
  }

  // Zaten güncel
  if (!isUpdateNeeded(latestVersion)) {
    return true;
  }

  changeMenu(UPDATE_MENU);

  // Firmware indir ve yaz
  if (!downloadAndWriteFirmware(latestVersion)) {
    changeMenu(UPDATE_FAIL_MENU);
    return false;
  }

  // Güncelleme Tamamlandı
  delay(1000);
  ESP.restart();
  return true;
}
