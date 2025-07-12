// ============================================================================
// File:    rows_enemy.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#ifndef ROWS_ENEMY_H
#define ROWS_ENEMY_H

// INCLUDES
#include "rows_direction.h"
#include "rows_entity.h"
#include "rows_map.h"
#include "rows_point.h"
#include "rows_screen.h"
#include "rows_state.h"

// DEFINES
#define ENEMY_IDLE_FRAME_COUNT 4

// CLASSES
class Enemy : public IEntity {
private:
  unsigned long tick;
  State state;
  Direction direction;
  int frameNumber;
  bool renderDirty;

public:
  // Değişkenler
  Point coord;
  Point oldCoord;
  // Fonksiyonlar
  Enemy();
  Enemy(Point, Direction);
  ~Enemy();
  void handleEvents();
  void update(int currentId);
  void updateAnimation(unsigned long);
  void render();
  void onDeath();
  EntityType getType();
  Direction getDirection();
};

// FUNCTIONS
bool setupEnemy();
bool initEnemy(Point coord, Direction direction);

#endif // ROWS_ENEMY_H
