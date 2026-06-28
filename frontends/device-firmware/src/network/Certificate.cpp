// ============================================================================
// File:    Certificate.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "network/Certificate.h"

#include "core/Logger.h"
#include "core/system/Filesystem.h"

WiFiClientSecure Certificate::wifiClient;

String Certificate::caCert;
String Certificate::clientCert;
String Certificate::clientKey;

void Certificate::init() {
  LOG_INFO("Initializing certificates...");
  // Sertifikaları Oku
  caCert = Filesystem::read("/certificates/ca.crt");
  clientCert = Filesystem::read("/certificates/client.crt");
  clientKey = Filesystem::read("/certificates/client.key");
  // Yapılandır
  wifiClient.setCACert(caCert.c_str());
  wifiClient.setCertificate(clientCert.c_str());
  wifiClient.setPrivateKey(clientKey.c_str());
}
