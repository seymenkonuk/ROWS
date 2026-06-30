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
  static bool startAP();
  static bool stopAP();
  static wl_status_t status();
};
