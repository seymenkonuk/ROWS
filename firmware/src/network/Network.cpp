// ============================================================================
// File:    Network.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "network/Network.h"

#include "core/Logger.h"
#include "core/system/Filesystem.h"

bool Network::init() {
  LOG_INFO("Initializing network...");
  String hostname = String("ROWS-") + Filesystem::read("/certificates/CN");
  WiFi.setHostname(hostname.c_str());
  return WiFi.mode(WIFI_AP_STA);
}

wl_status_t Network::status() {
  return WiFi.status();
}

bool Network::connectWifi() {
  String ssid, pass;
  // Varsa Eski Bağlantıyı Sonlandır
  disconnectWifi();
  // Bilgileri Oku
  ssid = Filesystem::read("/network/wifi/SSID");
  pass = Filesystem::read("/network/wifi/PASS");
  // Bağlanacak Bir Şey Yok
  if (ssid == "") {
    LOG_INFO("Skipped Wi-Fi connection: No SSID provided.");
    return false;
  }
  // Bağlanmaya Çalış
  LOG_INFO("Connecting to Wi-Fi: %s", ssid.c_str());
  WiFi.begin(ssid, pass);
  return true;
}

bool Network::startAP() {
  String ssid, pass;
  // Varsa Eski Bağlantıyı Sonlandır
  stopAP();
  // Bilgileri Oku
  ssid = Filesystem::read("/network/ap/SSID");
  pass = Filesystem::read("/network/ap/PASS");
  // Bağlanacak Bir Şey Yok
  if (ssid == "") {
    LOG_INFO("Skipped Access Point startup: No SSID provided.");
    return false;
  }
  // Bağlanmaya Çalış
  LOG_INFO("Starting Access Point: %s", ssid.c_str());
  WiFi.softAP(ssid, pass);
  return true;
}

bool Network::disconnectWifi() {
  LOG_INFO("Disconnecting from Wi-Fi...");
  return WiFi.disconnect(false);
}

bool Network::stopAP() {
  LOG_INFO("Stopping Access Point...");
  return WiFi.softAPdisconnect(false);
}
