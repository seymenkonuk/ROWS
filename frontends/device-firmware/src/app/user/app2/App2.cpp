// ============================================================================
// File:    App2.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "app/AppStack.h"

#include "app/user/app2/App2.h"

#include "core/system/AppManager.h"
#include "core/system/InputManager.h"

#include "graphics/Renderer.h"

const char *App2::getName() {
  return "App 2";
}

uint32_t App2::getColor() {
  return COLOR(255, 159, 64);
}

void App2::onEnter() {
  isDirty = true;
}

void App2::onExit() {
}

void App2::update(uint32_t deltaTime) {
  // A Butonuna Basıldığında Ana Menüye Dön
  if (InputManager::buttonA.pressed()) {
    AppManager::setApp(AppStack::getSysApp(0));
  }
  // B Butonuna Basınca Restart Yap
  else if (InputManager::buttonB.pressed()) {
    AppManager::setApp(this);
  }
}

void App2::render() {
  // Şimdilik Sadece Oyunun İsmini Yaz
  Point mcPos = {x : SCREEN_WIDTH / 2, y : SCREEN_HEIGHT / 2};
  Renderer::fillScreen(getColor());
  Renderer::setTextDatum(CC_DATUM);
  Renderer::drawTextWithBorder(getName(), mcPos, 2, COLOR(0xFF, 0xFF, 0xFF), COLOR(0x00, 0x00, 0x00));
}
