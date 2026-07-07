// ============================================================================
// File:    Network.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include <WiFi.h>

// CLASSES
class Network {
public:
  static bool init();

  static bool connectWifi();
  static bool disconnectWifi();
  static bool toggleWifi();
  static bool refreshWifi();
  static bool isWifiConnected();

  static bool startAP();
  static bool stopAP();
  static bool toggleAP();
  static bool refreshAP();
  static bool isAPStarted();

private:
  static bool wifiConnected;
  static bool apStarted;
};
