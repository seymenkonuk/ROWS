// ============================================================================
// File:    rows_map.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "rows_map.h"

LGFX_Sprite *iceMapSprite[4][4];
LGFX_Sprite *forestMapSprite[4][4];
LGFX_Sprite *(*currentMapSprite)[4][4];

Map::Map() {
  this->renderDirty = true;
}

EntityType Map::getType() {
  return MAP;
}

Map::~Map() {
}

void Map::handleEvents() {
}

void Map::update(int currentId) {
}

void Map::updateAnimation(unsigned long deltaTime) {
}

void Map::render() {
  // Renderlamaya Gerek Yok
  if (!this->renderDirty) {
    return;
  }
  // Render'la
  this->renderDirty = false;
  tft.startWrite();
  for (int i = 0; i < MAP_HEIGHT + 1; i++) {
    for (int j = 0; j < MAP_WIDTH + 1; j++) {
      renderMapTile(i, j);
      yield();
    }
  }
  tft.endWrite();
}

void Map::onDeath() {
}

Direction Map::getDirection() {
  return DOWN;
}

bool setupMap() {
  return readImageAtlas("/texture/map/ICE", iceMapSprite, 4, 4) && readImageAtlas("/texture/map/FOREST", forestMapSprite, 4, 4);
}

bool initMap(bool isIce) {
  Map *entity = new Map();
  currentMapSprite = (isIce) ? &iceMapSprite : &forestMapSprite;
  return createEntity(entity);
}
