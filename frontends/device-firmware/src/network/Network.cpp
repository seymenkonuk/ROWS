// ============================================================================
// File:    Network.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "network/Network.h"

#include "core/system/Filesystem.h"

bool Network::init() {
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
    return false;
  }
  // Bağlanmaya Çalış
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
    return false;
  }
  // Bağlanmaya Çalış
  WiFi.softAP(ssid, pass);
  return true;
}

bool Network::disconnectWifi() {
  return WiFi.disconnect(false);
}

bool Network::stopAP() {
  return WiFi.softAPdisconnect(false);
}
