// ============================================================================
// File:    AppStack.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include "app/IApplication.h"

// DEFINES
#define SYS_APP_COUNT 1
#define USR_APP_COUNT 3

// CLASSES
class AppStack {
public:
  static IApplication *getSysApp(uint32_t index);
  static IApplication *getUsrApp(uint32_t index);

private:
  static IApplication *sysApps[];
  static IApplication *usrApps[];
};
