// ============================================================================
// File:    rows_portal.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "rows_portal.h"

static LGFX_Sprite *portalSprite[PORTAL_IDLE_FRAME_COUNT];

Portal::Portal() : Portal({0, 0}) {
}

Portal::Portal(Point coord) {
  this->tick = 0;
  this->state = State::IDLE;
  this->frameNumber = generateRandom(0, PORTAL_IDLE_FRAME_COUNT);
  this->renderDirty = true;
  this->coord.x = coord.x;
  this->coord.y = coord.y;
  this->oldCoord.x = coord.x;
  this->oldCoord.y = coord.y;
}

EntityType Portal::getType() {
  return PORTAL;
}

Portal::~Portal() {
}

void Portal::handleEvents() {
}

void Portal::update(int currentId) {
}

void Portal::updateAnimation(unsigned long deltaTime) {
  this->tick += deltaTime;
  // Update Zamanı Gelmedi
  if (this->tick < FRAME_TICK) {
    return;
  }
  // Güncelle
  this->tick -= FRAME_TICK;
  this->frameNumber = (this->frameNumber + 1) % PORTAL_IDLE_FRAME_COUNT;
  this->renderDirty = true;
}

void Portal::render() {
  // Renderlamaya Gerek Yok
  if (!this->renderDirty) {
    return;
  }
  this->renderDirty = false;
  // Konum Değiştiyse (Hareket Edildiyse)
  if (this->oldCoord.x != this->coord.x || this->oldCoord.y != this->coord.y) {
    // Konumu Boşalt
    if (entityIdMap[this->oldCoord.y][this->oldCoord.x] == -1) {
      drawMapTile(&tileSprite, this->oldCoord.x, this->oldCoord.y);
      renderTile(tileSprite, OFFSET_X + this->oldCoord.x * TILE_SIZE, OFFSET_Y + this->oldCoord.y * TILE_SIZE);
    }
    // Eski Konumu Güncelle
    this->oldCoord.x = this->coord.x;
    this->oldCoord.y = this->coord.y;
  }
  // Yeni Konumu Render'la
  drawMapTile(&tileSprite, this->coord.x, this->coord.y);
  drawSpriteFromSprite(portalSprite[this->frameNumber], &tileSprite, 0, 0, 0, 0, TILE_SIZE, TILE_SIZE, true);
  renderTile(tileSprite, OFFSET_X + this->coord.x * TILE_SIZE, OFFSET_Y + this->coord.y * TILE_SIZE);
}

void Portal::onDeath() {
}

Direction Portal::getDirection() {
  return DOWN;
}

bool setupPortal() {
  for (int j = 0; j < PORTAL_IDLE_FRAME_COUNT; j++) {
    portalSprite[j] = new LGFX_Sprite(&tft);
    portalSprite[j]->setColorDepth(COLOR_DEPTH);
    portalSprite[j]->createSprite(TILE_SIZE, TILE_SIZE);
    drawSpriteFromImageFile("/texture/portal/IDLE", portalSprite[j], j * TILE_SIZE, 0, 0, 0, TILE_SIZE, TILE_SIZE, TILE_SIZE * PORTAL_IDLE_FRAME_COUNT, TILE_SIZE, false);
  }
  return true;
}

bool initPortal(Point coord) {
  Portal *entity = new Portal(coord);
  entityIdMap[coord.y][coord.x] = entitiesCount;
  return createEntity(entity);
}
