// ============================================================================
// File:    NetManager.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include "app/IApplication.h"

#include <Arduino.h>

// CLASSES
class NetManager : public IApplication {
public:
  const char *getName();
  uint32_t getColor();

  void onEnter();
  void onExit();

  void update(uint32_t deltaTime);
  void render();

private:
  uint32_t selectedIndex;
  void drawNetworkBox(uint8_t index, String title, String line1Name, String line1Value, String line2Name, String line2Value, uint32_t statusColor, bool selected);
};
