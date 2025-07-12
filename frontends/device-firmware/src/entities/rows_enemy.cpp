// ============================================================================
// File:    rows_enemy.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "rows_enemy.h"

static LGFX_Sprite *enemySprite[4][4];

Enemy::Enemy() : Enemy({0, 0}, Direction::DOWN) {
}

Enemy::Enemy(Point coord, Direction direction) {
  this->tick = 0;
  this->state = State::IDLE;
  this->direction = direction;
  this->frameNumber = generateRandom(0, ENEMY_IDLE_FRAME_COUNT);
  this->renderDirty = true;
  this->coord.x = coord.x;
  this->coord.y = coord.y;
  this->oldCoord.x = coord.x;
  this->oldCoord.y = coord.y;
}

EntityType Enemy::getType() {
  return ENEMY;
}

Enemy::~Enemy() {
}

void Enemy::handleEvents() {
}

void Enemy::update(int currentId) {
  this->renderDirty = true;

  // Eski Konumu Temizle
  if (entityIdMap[this->coord.y][this->coord.x] == currentId) {
    entityIdMap[this->coord.y][this->coord.x] = -1;
  }

  // Hareket Et Ya Da Yön Değiştir
  if (!isMoveAllowedForEnemy(this->coord, this->direction)) {
    this->direction = getOppositeDirection(this->direction);
  } else {
    Point vector = getDirectionVector(this->direction);
    this->coord.x += vector.x;
    this->coord.y += vector.y;
  }

  // Haritayı Güncelle
  int entityId = entityIdMap[this->coord.y][this->coord.x];
  entityIdMap[this->coord.y][this->coord.x] = currentId;

  // Konumda Hiçbir Şey Yoktu
  if (entityId == -1) {
    return;
  }

  // Konumda Olan Şeyi Kontrol Et
  switch (entities[entityId]->getType()) {
  // Altını Topla
  case EntityType::COIN:
    killedEntities[entityId] = true;
    totalCoinCount--;
    return;
  // İki Düşman Çarpıştı (ikisi de öldü)
  case EntityType::ENEMY:
    if (entityId < currentId) {
      killedEntities[entityId] = true;
      killedEntities[currentId] = true;
      entityIdMap[this->coord.y][this->coord.x] = -1;
    }
    return;
  // Karaktere Çarptın Oyun Bitti
  case EntityType::PLAYER:
    // Oyuncu Daha Önceden Hareket Etmiş ve Aynı Konumdayız
    if (entityId < currentId) {
      changeMenu(LOSE_MENU);
    }
    // Oyuncu Daha Hareket Etmedi, Ancak Benim Zıt Yönüme Hareket Ederse de Çarpışırız
    else if (entities[entityId]->getDirection() == getOppositeDirection(this->direction)) {
      changeMenu(LOSE_MENU);
    }
    return;
  }
}

void Enemy::updateAnimation(unsigned long deltaTime) {
  this->tick += deltaTime;
  // Update Zamanı Gelmedi
  if (this->tick < FRAME_TICK) {
    return;
  }
  // Güncelle
  this->tick -= FRAME_TICK;
  this->frameNumber = (this->frameNumber + 1) % ENEMY_IDLE_FRAME_COUNT;
  this->renderDirty = true;
}

void Enemy::render() {
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
  drawSpriteFromSprite(enemySprite[this->direction][this->frameNumber], &tileSprite, 0, 0, 0, 0, TILE_SIZE, TILE_SIZE, true);
  renderTile(tileSprite, OFFSET_X + this->coord.x * TILE_SIZE, OFFSET_Y + this->coord.y * TILE_SIZE);
}

void Enemy::onDeath() {
  if (entityIdMap[this->oldCoord.y][this->oldCoord.x] == -1) {
    drawMapTile(&tileSprite, this->oldCoord.x, this->oldCoord.y);
    renderTile(tileSprite, OFFSET_X + this->oldCoord.x * TILE_SIZE, OFFSET_Y + this->oldCoord.y * TILE_SIZE);
  }
}

Direction Enemy::getDirection() {
  return this->direction;
}

bool setupEnemy() {
  return readImageAtlas("/texture/enemy/IDLE", enemySprite, 4, 4);
}

bool initEnemy(Point coord, Direction direction) {
  Enemy *entity = new Enemy(coord, direction);
  entityIdMap[coord.y][coord.x] = entitiesCount;
  return createEntity(entity);
}
