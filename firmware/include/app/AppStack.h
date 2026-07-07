// ============================================================================
// File:    AppStack.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include "app/IApplication.h"

// CLASSES
class AppStack {
public:
  static const uint32_t SYS_APP_COUNT;
  static const uint32_t USR_APP_COUNT;

  static IApplication *getSysApp(uint32_t index);
  static IApplication *getUsrApp(uint32_t index);

private:
  static IApplication *sysApps[];
  static IApplication *usrApps[];
};
