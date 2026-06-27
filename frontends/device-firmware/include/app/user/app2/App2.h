// ============================================================================
// File:    App2.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include "app/IApplication.h"

// CLASSES
class App2 : public IApplication {
public:
  const char *getName();
  uint32_t getColor();

  void onEnter();
  void onExit();

  void update(uint32_t deltaTime);
  void render();
};
