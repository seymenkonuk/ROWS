// ============================================================================
// File:    UpdateCenter.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include "app/IApplication.h"

#include "network/OTAService.h"

// CLASSES
class UpdateCenter : public IApplication {
public:
  const char *getName();
  uint32_t getColor();

  void onEnter();
  void onExit();

  void update(uint32_t deltaTime);
  void render();

private:
  const char *statusMessage(SoftwareUpdateState state);
  SoftwareUpdateState state;
};
