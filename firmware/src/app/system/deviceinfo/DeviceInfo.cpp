// ============================================================================
// File:    DeviceInfo.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "app/system/deviceinfo/DeviceInfo.h"

#include "app/AppStack.h"

#include "core/system/AppManager.h"
#include "core/system/Filesystem.h"
#include "core/system/InputManager.h"

#include "graphics/Renderer.h"

const char *DeviceInfo::getName() {
  return "Device Info";
}

uint32_t DeviceInfo::getColor() {
  return COLOR(129, 199, 132);
}

void DeviceInfo::onEnter() {
  isDirty = true;
}

void DeviceInfo::onExit() {
}

void DeviceInfo::update(uint32_t deltaTime) {
  // Y Butonuna Basıldığında Ana Menüye Dön
  if (InputManager::buttonY.pressed()) {
    AppManager::setApp(AppStack::getSysApp(0));
  }
}

void DeviceInfo::render() {
  String serialNumber = Filesystem::read("/certificates/CN");
  String password = Filesystem::read("/certificates/PASS");
  String version = Filesystem::read("/info/VERSION");

  // Arkaplan
  Renderer::setFillColor(COLOR(28, 28, 32));
  Renderer::fillRect({0, 0}, {320, 240});

  // Header Arkaplan
  Renderer::setFillColor(COLOR(55, 55, 65));
  Renderer::fillRect({0, 0}, {320, 28});

  // Header Title
  Renderer::setTextSize(2);
  Renderer::setTextDatum(TL_DATUM);
  Renderer::setTextColor(COLOR(255, 255, 255));
  Renderer::drawText("Device Info", {8, 7});

  // Seri Numarası
  Renderer::setTextSize(1);
  Renderer::setTextColor(COLOR(150, 150, 150));
  Renderer::drawText("Serial Number:", {8, 36});
  Renderer::setTextColor(COLOR(240, 240, 240));
  Renderer::drawText(serialNumber, {100, 36});

  // Parola
  Renderer::setTextColor(COLOR(150, 150, 150));
  Renderer::drawText("Password:", {8, 52});
  Renderer::setTextColor(COLOR(240, 240, 240));
  Renderer::drawText(password, {100, 52});

  // Version
  Renderer::setTextColor(COLOR(150, 150, 150));
  Renderer::drawText("Version:", {8, 68});
  Renderer::setTextColor(COLOR(240, 240, 240));
  Renderer::drawText(version, {100, 68});
}
