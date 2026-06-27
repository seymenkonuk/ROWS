// ============================================================================
// File:    OTAService.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "network/OTAService.h"

#include "core/system/Filesystem.h"

#include "network/APIClient.h"

#include <Update.h>

String OTAService::currentSoftwareVersion;
String OTAService::newSoftwareVersion;

void OTAService::init() {
  currentSoftwareVersion = Filesystem::read("/info/VERSION");
}

bool OTAService::check() {
  String url = String(OTA_SERVICE_GET_NEW_VERSION_URL) + "?version=" + currentSoftwareVersion;
  APIResponse res = APIClient::get(url);
  // Bağlantı veya Sunucu Hatası
  if (res.isError() || res.statusCode != 200) {
    return false;
  }
  // Yeni Güncelleme Yok
  if (res.body == currentSoftwareVersion) {
    return false;
  }
  // Güncelleme Mevcut
  newSoftwareVersion = res.body;
  return true;
}

bool OTAService::update() {
  String url = String(OTA_SERVICE_GET_FIRMWARE_URL) + "?version=" + currentSoftwareVersion;
  // Sunucudan Güncellemeyi İste
  if (!APIClient::getStream(url, updateCallback)) {
    return false;
  }
  // Güncelleme Tamamlandı
  Filesystem::write("/info/VERSION", newSoftwareVersion);
  delay(1000);
  ESP.restart();
  return true;
}

bool OTAService::updateCallback(const APIResponse &res) {
  // Bağlantı veya Sunucu Hatası
  if (res.isError() || res.statusCode != 200) {
    return false;
  }

  // Dosya Boyutu Hatası
  if (res.contentLength < 0 || !Update.begin(res.contentLength)) {
    return false;
  }

  // Memory'ye Yaz
  size_t totalWritten = 0;
  size_t written;
  do {
    written = Update.writeStream(*res.stream);
    yield();
    totalWritten += written;
  } while (written != 0);

  // Dosya Boyutu Doğru Gelmedi
  if (totalWritten != res.contentLength) {
    return false;
  }

  // Güncelleme İşlemini Bitir
  return Update.end();
}
