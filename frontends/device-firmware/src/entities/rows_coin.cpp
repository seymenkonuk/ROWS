// ============================================================================
// File:    rows_coin.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "rows_coin.h"

static LGFX_Sprite *coinSprite[COIN_IDLE_FRAME_COUNT];

Coin::Coin() : Coin({0, 0}) {
}

Coin::Coin(Point coord) {
  this->tick = 0;
  this->state = State::IDLE;
  this->frameNumber = generateRandom(0, COIN_IDLE_FRAME_COUNT);
  this->renderDirty = true;
  this->coord.x = coord.x;
  this->coord.y = coord.y;
  this->oldCoord.x = coord.x;
  this->oldCoord.y = coord.y;
}

EntityType Coin::getType() {
  return COIN;
}

Coin::~Coin() {
}

void Coin::handleEvents() {
}

void Coin::update(int currentId) {
}

void Coin::updateAnimation(unsigned long deltaTime) {
  this->tick += deltaTime;
  // Update Zamanı Gelmedi
  if (this->tick < FRAME_TICK) {
    return;
  }
  // Güncelle
  this->tick -= FRAME_TICK;
  this->frameNumber = (this->frameNumber + 1) % COIN_IDLE_FRAME_COUNT;
  this->renderDirty = true;
}

void Coin::render() {
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
  drawSpriteFromSprite(coinSprite[this->frameNumber], &tileSprite, 0, 0, 0, 0, TILE_SIZE, TILE_SIZE, true);
  renderTile(tileSprite, OFFSET_X + this->coord.x * TILE_SIZE, OFFSET_Y + this->coord.y * TILE_SIZE);
}

void Coin::onDeath() {
  if (entityIdMap[this->oldCoord.y][this->oldCoord.x] == -1) {
    drawMapTile(&tileSprite, this->oldCoord.x, this->oldCoord.y);
    renderTile(tileSprite, OFFSET_X + this->oldCoord.x * TILE_SIZE, OFFSET_Y + this->oldCoord.y * TILE_SIZE);
  }
}

Direction Coin::getDirection() {
  return DOWN;
}

bool setupCoin() {
  for (int j = 0; j < COIN_IDLE_FRAME_COUNT; j++) {
    coinSprite[j] = new LGFX_Sprite(&tft);
    coinSprite[j]->setColorDepth(COLOR_DEPTH);
    coinSprite[j]->createSprite(TILE_SIZE, TILE_SIZE);
    drawSpriteFromImageFile("/texture/coin/IDLE", coinSprite[j], j * TILE_SIZE, 0, 0, 0, TILE_SIZE, TILE_SIZE, TILE_SIZE * COIN_IDLE_FRAME_COUNT, TILE_SIZE, false);
  }
  return true;
}

bool initCoin(Point coord) {
  Coin *entity = new Coin(coord);
  entityIdMap[coord.y][coord.x] = entitiesCount;
  return createEntity(entity);
}
