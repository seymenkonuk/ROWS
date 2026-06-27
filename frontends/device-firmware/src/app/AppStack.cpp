// ============================================================================
// File:    AppStack.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "app/AppStack.h"

#include "app/system/launcher/Launcher.h"

#include "app/user/app1/App1.h"
#include "app/user/app2/App2.h"

// Sistem Uygulamaları
static Launcher launcher;

// Kullanıcı Uygulamaları
static App1 app1;
static App2 app2;

// Sistem Uygulamaları Listesi
IApplication *AppStack::sysApps[] = {
    &launcher,
};

// Kullanıcı Uygulamaları Listesi
IApplication *AppStack::usrApps[] = {
    &app1,
    &app2,
};

IApplication *AppStack::getSysApp(uint32_t index) {
  if (index >= SYS_APP_COUNT) {
    return nullptr;
  }
  return sysApps[index];
}

IApplication *AppStack::getUsrApp(uint32_t index) {
  if (index >= USR_APP_COUNT) {
    return nullptr;
  }
  return usrApps[index];
}
