// ============================================================================
// File:    AppStack.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "app/AppStack.h"

#include "app/system/launcher/Launcher.h"
#include "app/system/netmanager/NetManager.h"

#include "app/user/app1/App1.h"
#include "app/user/app2/App2.h"

#include "core/Logger.h"

// Sistem Uygulamaları
static Launcher launcher;
static NetManager netManager;

// Kullanıcı Uygulamaları
static App1 app1;
static App2 app2;

// Sistem Uygulamaları Listesi
IApplication *AppStack::sysApps[] = {
    &launcher,
    &netManager,
};

// Kullanıcı Uygulamaları Listesi
IApplication *AppStack::usrApps[] = {
    &launcher,
    &app1,
    &app2,
};

// Uygulama Adetleri
const size_t AppStack::SYS_APP_COUNT = sizeof(sysApps) / sizeof(sysApps[0]);
const size_t AppStack::USR_APP_COUNT = sizeof(usrApps) / sizeof(usrApps[0]);

// Sistem Uygulamasını Getir
IApplication *AppStack::getSysApp(uint32_t index) {
  if (index >= SYS_APP_COUNT) {
    LOG_ERROR("Parameter error: index out of bounds (index: %u, max: %u)", index, SYS_APP_COUNT);
    return nullptr;
  }
  return sysApps[index];
}

// Kullanıcı Uygulamasını Getir
IApplication *AppStack::getUsrApp(uint32_t index) {
  if (index >= USR_APP_COUNT) {
    LOG_ERROR("Parameter error: index out of bounds (index: %u, max: %u)", index, USR_APP_COUNT);
    return nullptr;
  }
  return usrApps[index];
}
