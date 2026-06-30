// ============================================================================
// File:    Launcher.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include "app/IApplication.h"

// CLASSES
class Launcher : public IApplication {
public:
  const char *getName();
  uint32_t getColor();

  void onEnter();
  void onExit();

  void update(uint32_t deltaTime);
  void render();

private:
  uint32_t sysAppIndex;
  uint32_t usrAppIndex;

  uint32_t currentAppType;
  uint32_t *currentAppIndex;
  uint32_t maxCurrentAppCount;
  IApplication *(*getApp)(uint32_t);
};
