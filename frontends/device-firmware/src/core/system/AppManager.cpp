// ============================================================================
// File:    AppManager.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "core/system/AppManager.h"

IApplication *AppManager::currentApp = nullptr;

void AppManager::setApp(IApplication *app) {
  // Parametre Hatası
  if (!app) {
    return;
  }
  // Acik Olan Uygulamayi Kapat
  if (currentApp) {
    currentApp->onExit();
  }
  // Yeni Uygulamayi Degiskene Ata
  currentApp = app;
  // Yeni Uygulamayi Ac
  if (currentApp) {
    currentApp->onEnter();
  }
}

void AppManager::update(uint32_t deltaTime) {
  // Herhangi Bir Uygulama Aciksa
  if (currentApp) {
    currentApp->update(deltaTime);
  }
}

void AppManager::render() {
  // Herhangi Bir Uygulama Aciksa ve Render Edilmesi Gerekiyorsa
  if (currentApp && currentApp->isDirty) {
    currentApp->render();
    currentApp->isDirty = false;
  }
}
