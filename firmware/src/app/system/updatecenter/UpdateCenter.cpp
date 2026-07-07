// ============================================================================
// File:    UpdateCenter.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "app/system/updatecenter/UpdateCenter.h"

#include "app/AppStack.h"

#include "core/system/AppManager.h"
#include "core/system/InputManager.h"

#include "graphics/Renderer.h"

#include "network/OTAService.h"

const char *UpdateCenter::getName() {
  return "Software Update";
}

uint32_t UpdateCenter::getColor() {
  return COLOR(255, 213, 79);
}

void UpdateCenter::onEnter() {
  state = SoftwareUpdateState::Idle;
  isDirty = true;
}

void UpdateCenter::onExit() {
}

void UpdateCenter::update(uint32_t deltaTime) {
  switch (state) {
  // Idle Durumdaysa Kontrol Etmeye Geç
  case SoftwareUpdateState::Idle:
    state = SoftwareUpdateState::Checking;
    isDirty = true;
    return;
  // Kontrol Et
  case SoftwareUpdateState::Checking:
    state = OTAService::check();
    isDirty = true;
    return;
  // Güncelleme Mevcutsa İndirme Aşamasına Geç
  case SoftwareUpdateState::UpdateAvailable:
    state = SoftwareUpdateState::Downloading;
    isDirty = true;
    return;
  // İndir
  case SoftwareUpdateState::Downloading:
    state = OTAService::update();
    isDirty = true;
    return;
  // Bitti
  default:
    break;
  }
  // Güncelleme Aşamaları Bitti
  // Y Butonuna Basıldığında Ana Menüye Dön
  if (InputManager::buttonY.pressed()) {
    AppManager::setApp(AppStack::getSysApp(0));
  }
}

void UpdateCenter::render() {
  Point mcPos = {x : SCREEN_WIDTH / 2, y : SCREEN_HEIGHT / 2};
  Renderer::setTextSize(2);
  Renderer::fillScreen(getColor());
  Renderer::setTextDatum(MC_DATUM);
  Renderer::setTextColor(COLOR(33, 33, 33));
  Renderer::drawText(statusMessage(state), mcPos);
}

const char *UpdateCenter::statusMessage(SoftwareUpdateState state) {
  switch (state) {
  case SoftwareUpdateState::Idle:
    return "Ready";
  case SoftwareUpdateState::Checking:
    return "Checking for updates...";
  case SoftwareUpdateState::UpdateAvailable:
    return "Update available";
  case SoftwareUpdateState::NoUpdate:
    return "Software is up to date";
  case SoftwareUpdateState::Downloading:
    return "Downloading update...";
  case SoftwareUpdateState::Completed:
    return "Update completed";
  case SoftwareUpdateState::Failed:
    return "Update failed";
  }

  return "";
}
