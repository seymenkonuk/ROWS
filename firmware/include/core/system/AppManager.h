// ============================================================================
// File:    AppManager.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include "app/IApplication.h"

// CLASSES
class AppManager {
public:
  static void setApp(IApplication *app);
  static void update(uint32_t deltaTime);
  static void render();

private:
  static IApplication *currentApp;
};
