// ============================================================================
// File:    rows_portal.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#ifndef ROWS_PORTAL_H
#define ROWS_PORTAL_H

// INCLUDES
#include "rows_direction.h"
#include "rows_entity.h"
#include "rows_map.h"
#include "rows_point.h"
#include "rows_screen.h"
#include "rows_state.h"

// DEFINES
#define PORTAL_IDLE_FRAME_COUNT 1

// CLASSES
class Portal : public IEntity {
private:
  unsigned long tick;
  State state;
  int frameNumber;
  bool renderDirty;

public:
  // Değişkenler
  Point coord;
  Point oldCoord;
  // Fonksiyonlar
  Portal();
  Portal(Point);
  ~Portal();
  void handleEvents();
  void update(int currentId);
  void updateAnimation(unsigned long);
  void render();
  void onDeath();
  EntityType getType();
  Direction getDirection();
};

// FUNCTIONS
bool setupPortal();
bool initPortal(Point coord);

#endif // ROWS_PORTAL_H
