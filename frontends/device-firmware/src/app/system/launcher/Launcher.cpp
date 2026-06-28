// ============================================================================
// File:    Launcher.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "app/system/launcher/Launcher.h"

#include "app/AppStack.h"

#include "core/system/AppManager.h"
#include "core/system/InputManager.h"

#include "graphics/Renderer.h"

const char *Launcher::getName() {
  return "Launcher";
}

uint32_t Launcher::getColor() {
  return COLOR(153, 102, 255);
}

void Launcher::onEnter() {
  isDirty = true;
  sysAppIndex = 0;
  usrAppIndex = 0;
  // Sistem Uygulamaları Menüsünde Başlat
  currentAppType = 1;
  currentAppIndex = &usrAppIndex;
  maxCurrentAppCount = USR_APP_COUNT;
  getApp = AppStack::getUsrApp;
}

void Launcher::onExit() {
}

void Launcher::update(uint32_t deltaTime) {
  // Bir Önceki Uygulamayı Göster
  if (InputManager::buttonUp.pressed()) {
    *currentAppIndex = (*currentAppIndex == 0) ? maxCurrentAppCount - 1 : *currentAppIndex - 1;
    isDirty = true;
  }
  // Bir Sonraki Uygulamayı Göster
  else if (InputManager::buttonDown.pressed()) {
    *currentAppIndex = (*currentAppIndex == maxCurrentAppCount - 1) ? 0 : *currentAppIndex + 1;
    isDirty = true;
  }
  // Uygulamayı Başlat
  else if (InputManager::buttonA.pressed()) {
    AppManager::setApp((*getApp)(*currentAppIndex));
  }
  // Menüyü Değiştir (Sistem Uygulamaları Menüsü / Kullanıcı Uygulamaları Menüsü)
  else if (InputManager::buttonB.pressed()) {
    if (currentAppType == 0) {
      currentAppType = 1;
      currentAppIndex = &usrAppIndex;
      maxCurrentAppCount = USR_APP_COUNT;
      getApp = AppStack::getUsrApp;
    } else {
      currentAppType = 0;
      currentAppIndex = &sysAppIndex;
      maxCurrentAppCount = SYS_APP_COUNT;
      getApp = AppStack::getSysApp;
    }
    isDirty = true;
  }
}

void Launcher::render() {
  // Şimdilik Sadece Uygulama İsimlerini Yazdır
  Point mcPos = {x : SCREEN_WIDTH / 2, y : SCREEN_HEIGHT / 2};
  auto currentApp = (*getApp)(*currentAppIndex);
  Renderer::setTextSize(2);
  Renderer::fillScreen(getColor());
  Renderer::setTextDatum(MC_DATUM);
  Renderer::drawTextWithBorder(currentApp->getName(), mcPos, 2, currentApp->getColor(), COLOR(0x00, 0x00, 0x00));
}
