// ============================================================================
// File:    rows_coin.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#ifndef ROWS_COIN_H
#define ROWS_COIN_H

// INCLUDES
#include "rows_direction.h"
#include "rows_entity.h"
#include "rows_map.h"
#include "rows_point.h"
#include "rows_screen.h"
#include "rows_state.h"

// DEFINES
#define COIN_IDLE_FRAME_COUNT 4

// CLASSES
class Coin : public IEntity {
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
  Coin();
  Coin(Point);
  ~Coin();
  void handleEvents();
  void update(int currentId);
  void updateAnimation(unsigned long);
  void render();
  void onDeath();
  EntityType getType();
  Direction getDirection();
};

// FUNCTIONS
bool setupCoin();
bool initCoin(Point coord);

#endif // ROWS_COIN_H
