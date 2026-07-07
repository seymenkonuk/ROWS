// ============================================================================
// File:    DeviceServer.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include <WebServer.h>

// CLASSES
class DeviceServer {
  static constexpr uint8_t AP_SSID_LIMIT = 32;
  static constexpr uint8_t AP_PASS_LIMIT = 32;
  static constexpr uint8_t WIFI_SSID_LIMIT = 32;
  static constexpr uint8_t WIFI_PASS_LIMIT = 32;

public:
  static void init();

  static void start();
  static void stop();
  static void toggle();
  static bool isRunning();

  static void loop();

private:
  static WebServer server;
  static String username, password;
  static String apSSID, apPass;
  static String wifiSSID, wifiPass;
  static bool serverRunning;

  static void handleHomeGet();
  static void handleHomePost();
  static void handleStyleGet();
  static bool authenticate();
};
