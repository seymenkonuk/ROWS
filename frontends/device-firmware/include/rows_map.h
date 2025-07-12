// ============================================================================
// File:    rows_map.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#ifndef ROWS_MAP_H
#define ROWS_MAP_H

// INCLUDES
#include "rows_direction.h"
#include "rows_entity.h"
#include "rows_point.h"
#include "rows_random.h"
#include "rows_screen.h"

// CLASS
class Map : public IEntity {
private:
  bool renderDirty;

public:
  Map();
  ~Map();
  void handleEvents();
  void update(int currentId);
  void updateAnimation(unsigned long);
  void render();
  void onDeath();
  EntityType getType();
  Direction getDirection();
};

// EXTERN
extern LGFX_Sprite *iceMapSprite[4][4];
extern LGFX_Sprite *forestMapSprite[4][4];
extern LGFX_Sprite *(*currentMapSprite)[4][4];
extern bool wallMap[MAP_HEIGHT][MAP_WIDTH];
extern int entityIdMap[MAP_HEIGHT][MAP_WIDTH];
extern Point mapTile[MAP_HEIGHT + 1][MAP_WIDTH + 1];

// FUNCTIONS
bool initMap(bool isIce);
bool setupMap();
void createMapTile();
void drawMapTile(LGFX_Sprite *sprite, int x, int y);
void renderMapTile(int i, int j);
void calcMapTile(int i, int j);
bool isMoveAllowed(Point coord, Direction direction);
bool isMoveAllowedForEnemy(Point coord, Direction direction);
Point findRandomEmptyCell();
String generateRandomGame();

#endif // ROWS_MAP_H
