// ============================================================================
// File:    IApplication.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include <stdint.h>

// CLASSES
class IApplication {
public:
  virtual ~IApplication() = default;

  virtual const char *getName() = 0;
  virtual uint32_t getColor() = 0;

  virtual void onEnter() = 0;
  virtual void onExit() = 0;

  virtual void update(uint32_t deltaTime) = 0;
  virtual void render() = 0;

  bool isDirty;
};
