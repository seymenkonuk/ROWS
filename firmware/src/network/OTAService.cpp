// ============================================================================
// File:    OTAService.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "network/OTAService.h"

#include "core/Logger.h"
#include "core/system/Filesystem.h"

#include "network/APIClient.h"

#include <Update.h>

String OTAService::currentSoftwareVersion;
String OTAService::newSoftwareVersion;

void OTAService::init() {
  LOG_INFO("Initializing OTA service...");
  currentSoftwareVersion = Filesystem::read("/info/VERSION");
}

SoftwareUpdateState OTAService::check() {
  LOG_INFO("Checking for updates...");
  String url = String(OTA_SERVICE_GET_NEW_VERSION_URL) + "?version=" + currentSoftwareVersion;
  APIResponse res = APIClient::get(url);
  // Bağlantı veya Sunucu Hatası
  if (res.isError() || res.statusCode != 200) {
    LOG_ERROR("Update check failed: Invalid response from server");
    return SoftwareUpdateState::Failed;
  }
  // Yeni Güncelleme Yok
  if (res.body == currentSoftwareVersion) {
    LOG_INFO("No update available.");
    return SoftwareUpdateState::NoUpdate;
  }
  // Güncelleme Mevcut
  newSoftwareVersion = res.body;
  LOG_INFO("Update found: version %s", newSoftwareVersion.c_str());
  return SoftwareUpdateState::UpdateAvailable;
}

SoftwareUpdateState OTAService::update() {
  LOG_INFO("Update in progress...");
  String url = String(OTA_SERVICE_GET_FIRMWARE_URL) + "?version=" + currentSoftwareVersion;
  // Sunucudan Güncellemeyi İste
  if (!APIClient::getStream(url, updateCallback)) {
    return SoftwareUpdateState::Failed;
  }
  // Güncelleme Tamamlandı
  LOG_INFO("Update complete. Restarting...");
  Filesystem::write("/info/VERSION", newSoftwareVersion);
  delay(1000);
  ESP.restart();
  return SoftwareUpdateState::Completed;
}

bool OTAService::updateCallback(const APIResponse &res) {
  // Bağlantı veya Sunucu Hatası
  if (res.isError() || res.statusCode != 200) {
    LOG_ERROR("Update failed: Invalid response from server");
    return false;
  }

  // Dosya Boyutu Hatası
  if (res.contentLength < 0 || !Update.begin(res.contentLength)) {
    LOG_ERROR("Update failed: Invalid response from server");
    return false;
  }

  // Memory'ye Yaz
  size_t totalWritten = 0;
  size_t written;
  LOG_INFO("Downloading...");
  do {
    written = Update.writeStream(*res.stream);
    yield();
    totalWritten += written;
  } while (written != 0);

  // Dosya Boyutu Doğru Gelmedi
  if (totalWritten != res.contentLength) {
    LOG_ERROR("Update failed: File size mismatch");
    return false;
  }

  // Güncelleme İşlemini Bitir
  return Update.end();
}
