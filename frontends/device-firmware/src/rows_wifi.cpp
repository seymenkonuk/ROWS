// ============================================================================
// File:    rows_wifi.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "rows_wifi.h"

bool setupWifi() {
  WiFi.setHostname((String("ROWS-") + readFile("/certificates/CN")).c_str());
  return WiFi.mode(WIFI_AP_STA);
}

bool connectWifi() {
  String ssid, pass;
  // Varsa Eski Bağlantıyı Sonlandır
  if (WiFi.status() == WL_CONNECTED) {
    WiFi.disconnect(false);
  }
  // Bilgileri Oku
  ssid = readFile("/wifi/internet/SSID");
  pass = readFile("/wifi/internet/PASS");
  // Bağlanacak Bir Şey Yok
  if (ssid == "") {
    return false;
  }
  // Bağlanmaya Çalış
  WiFi.begin(ssid, pass);
  return true;
}

bool startAP() {
  String ssid, pass;
  // Varsa Eski Bağlantıyı Sonlandır
  WiFi.softAPdisconnect(false);
  // Bilgileri Oku
  ssid = readFile("/wifi/ap/SSID");
  pass = readFile("/wifi/ap/PASS");
  // Bağlanacak Bir Şey Yok
  if (ssid == "") {
    return false;
  }
  // Bağlanmaya Çalış
  WiFi.softAP(ssid, pass);
  return true;
}
