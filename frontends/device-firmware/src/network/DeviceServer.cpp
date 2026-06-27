// ============================================================================
// File:    DeviceServer.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "network/DeviceServer.h"

#include "core/system/Filesystem.h"

#include "network/Network.h"

WebServer DeviceServer::server(80);

bool DeviceServer::serverRunning = false;

String DeviceServer::username, DeviceServer::password;
String DeviceServer::apSSID, DeviceServer::apPass;
String DeviceServer::wifiSSID, DeviceServer::wifiPass;

void DeviceServer::init() {
  // Gerekli Değişkenleri Oku
  username = Filesystem::read("/certificates/CN");
  password = Filesystem::read("/certificates/PASS");
  apSSID = Filesystem::read("/network/ap/SSID");
  apPass = Filesystem::read("/network/ap/PASS");
  wifiSSID = Filesystem::read("/network/wifi/SSID");
  wifiPass = Filesystem::read("/network/wifi/PASS");
  // Serveri Yapılandır
  server.on("/", HTTP_GET, handleHomeGet);
  server.on("/style.css", HTTP_GET, handleStyleGet);
  server.on("/", HTTP_POST, handleHomePost);
}

void DeviceServer::start() {
  server.begin();
  serverRunning = true;
}

void DeviceServer::stop() {
  server.stop();
  serverRunning = false;
}

void DeviceServer::loop() {
  if (serverRunning) {
    server.handleClient();
  }
}

void DeviceServer::handleHomeGet() {
  // Kimlik Doğrulama İste
  if (!authenticate()) {
    return;
  }
  // Cevabı Gönder
  String response = Filesystem::read("/www/index.html");
  // VERİ ESCAPE EDİLMELİ!!!!!!!!!!!
  response.replace("$AP_SSID________________________$", apSSID);
  response.replace("$AP_PASS________________________$", apPass);
  response.replace("$WIFI_SSID______________________$", wifiSSID);
  response.replace("$WIFI_PASS______________________$", wifiPass);
  server.send(200, "text/html", response);
}

void DeviceServer::handleHomePost() {
  // Kimlik Doğrulama İste
  if (!authenticate()) {
    return;
  }
  // Yeni Bilgileri Oku
  String newApSSID = server.arg("AP_SSID").substring(0, AP_SSID_LIMIT);
  String newApPass = server.arg("AP_PASS").substring(0, AP_PASS_LIMIT);
  String newWifiSSID = server.arg("WIFI_SSID").substring(0, WIFI_SSID_LIMIT);
  String newWifiPass = server.arg("WIFI_PASS").substring(0, WIFI_PASS_LIMIT);
  // WiFi Bilgileri Değiştiyse, Yeni Wifiye Bağlan
  if (newWifiSSID != wifiSSID || newWifiPass != wifiPass) {
    Filesystem::write("/network/wifi/SSID", newWifiSSID.c_str());
    Filesystem::write("/network/wifi/PASS", newWifiPass.c_str());
    wifiSSID = newWifiSSID;
    wifiPass = newWifiPass;
    Network::connectWifi();
  }
  // AP Bilgileri Değiştiyse, Yeni AP Başlat
  if (newApSSID != apSSID || newApPass != apPass) {
    Filesystem::write("/network/ap/SSID", newApSSID.c_str());
    Filesystem::write("/network/ap/PASS", newApPass.c_str());
    apSSID = newApSSID;
    apPass = newApPass;
    Network::startAP();
  }
  // PRG -> Post Redirect Get
  server.sendHeader("Location", "/");
  server.send(303, "text/plain", "");
}

void DeviceServer::handleStyleGet() {
  // Kimlik Doğrulama İste
  if (!authenticate()) {
    return;
  }
  // Stil Dosyasını Gönder
  String response = Filesystem::read("/www/style.css");
  server.send(200, "text/css", response);
}

bool DeviceServer::authenticate() {
  // Kimlik Doğrulama İste
  if (!server.authenticate(username.c_str(), password.c_str())) {
    server.requestAuthentication();
    return false;
  }
  return true;
}
