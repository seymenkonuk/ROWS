// ============================================================================
// File:    rows_server.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "rows_server.h"

WebServer server(80);

static String username, password;

static String calcResponse() {
  String response;
  String apSSID, apPass;
  String wifiSSID, wifiPass;
  // AP Bilgilerini Al
  apSSID = readFile("/wifi/ap/SSID");
  apSSID.replace("\"", "\\\"");
  apPass = readFile("/wifi/ap/PASS");
  apPass.replace("\"", "\\\"");
  // WIFI Bilgilerini Al
  wifiSSID = readFile("/wifi/internet/SSID");
  wifiSSID.replace("\"", "\\\"");
  wifiPass = readFile("/wifi/internet/PASS");
  wifiPass.replace("\"", "\\\"");
  // Cevabı Hesapla
  response = readFile("/www/index.html");
  response.replace("$AP_SSID________________________$", apSSID);
  response.replace("$AP_PASS________________________$", apPass);
  response.replace("$WIFI_SSID______________________$", wifiSSID);
  response.replace("$WIFI_PASS______________________$", wifiPass);
  // Sonucu Döndür
  return response;
}

static void handleGet() {
  if (!server.authenticate(username.c_str(), password.c_str())) {
    return server.requestAuthentication();
  }
  String response;
  response = calcResponse();
  server.send(200, "text/html", response);
}

static void handlePost() {
  if (!server.authenticate(username.c_str(), password.c_str())) {
    return server.requestAuthentication();
  }
  // Eski Bilgiler
  String oldApSSID, oldApPass;
  String oldWifiSSID, oldWifiPass;
  // Yeni Gelen Bilgiler
  String apSSID, apPass;
  String wifiSSID, wifiPass;
  // Eski Bilgileri Oku
  oldApSSID = readFile("/wifi/ap/SSID");
  oldApPass = readFile("/wifi/ap/PASS");
  oldWifiSSID = readFile("/wifi/internet/SSID");
  oldWifiPass = readFile("/wifi/internet/PASS");
  // Yeni Bilgileri Oku
  apSSID = server.arg("AP_SSID");
  apPass = server.arg("AP_PASS");
  wifiSSID = server.arg("WIFI_SSID");
  wifiPass = server.arg("WIFI_PASS");
  // Dosyaya Kaydet
  writeFile("/wifi/ap/SSID", apSSID.substring(0, 32).c_str());
  writeFile("/wifi/ap/PASS", apPass.substring(0, 32).c_str());
  writeFile("/wifi/internet/SSID", wifiSSID.substring(0, 32).c_str());
  writeFile("/wifi/internet/PASS", wifiPass.substring(0, 32).c_str());
  // Değişiklikleri Uygula
  if (oldWifiSSID != wifiSSID || oldWifiPass != wifiPass) {
    connectWifi();
  }
  if (oldApSSID != apSSID || oldApPass != apPass) {
    startAP();
  }
  // Cevap Gönder
  handleGet();
}

static void handleStyle() {
  if (!server.authenticate(username.c_str(), password.c_str())) {
    return server.requestAuthentication();
  }
  String response;
  response = readFile("/www/style.css");
  server.send(200, "text/css", response);
}

bool setupWebServer() {
  // Bilgileri Oku
  username = readFile("/certificates/CN");
  password = readFile("/certificates/PASS");
  // GET ile gelen istek
  server.on("/", HTTP_GET, handleGet);
  server.on("/index.html", HTTP_GET, handleGet);
  server.on("/style.css", HTTP_GET, handleStyle);
  // POST ile gelen istek
  server.on("/", HTTP_POST, handlePost);
  server.on("/index.html", HTTP_POST, handlePost);
  // Server Başlat
  server.begin();
  return true;
}
