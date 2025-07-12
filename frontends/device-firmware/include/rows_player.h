// ============================================================================
// File:    rows_player.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#ifndef ROWS_PLAYER_H
#define ROWS_PLAYER_H

// INCLUDES
#include "rows_controller.h"
#include "rows_direction.h"
#include "rows_entity.h"
#include "rows_map.h"
#include "rows_menu.h"
#include "rows_point.h"
#include "rows_screen.h"
#include "rows_state.h"

// DEFINES
#define PLAYER_IDLE_FRAME_COUNT 4

// CLASSES
class Player : public IEntity {
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
  Player();
  Player(Point, Direction);
  ~Player();
  void handleEvents();
  void update(int currentId);
  void updateAnimation(unsigned long);
  void render();
  void onDeath();
  EntityType getType();
  Direction getDirection();
};

// FUNCTIONS
bool setupPlayer();
bool initPlayer(Point coord, Direction direction);

#endif // ROWS_PLAYER_H
