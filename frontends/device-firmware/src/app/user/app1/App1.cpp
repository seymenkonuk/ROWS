// ============================================================================
// File:    App1.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "app/AppStack.h"

#include "app/user/app1/App1.h"

#include "core/system/AppManager.h"
#include "core/system/InputManager.h"

#include "graphics/Renderer.h"

const char *App1::getName() {
  return "App 1";
}

uint32_t App1::getColor() {
  return COLOR(155, 89, 182);
}

void App1::onEnter() {
  isDirty = true;
}

void App1::onExit() {
}

void App1::update(uint32_t deltaTime) {
  // A Butonuna Basıldığında Ana Menüye Dön
  if (InputManager::buttonA.pressed()) {
    AppManager::setApp(AppStack::getSysApp(0));
  }
  // B Butonuna Basınca Restart Yap
  else if (InputManager::buttonB.pressed()) {
    AppManager::setApp(this);
  }
}

void App1::render() {
  // Şimdilik Sadece Oyunun İsmini Yaz
  Point mcPos = {x : SCREEN_WIDTH / 2, y : SCREEN_HEIGHT / 2};
  Renderer::fillScreen(getColor());
  Renderer::setTextDatum(CC_DATUM);
  Renderer::drawTextWithBorder(getName(), mcPos, 2, COLOR(0xFF, 0xFF, 0xFF), COLOR(0x00, 0x00, 0x00));
}
