// ============================================================================
// File:    rows_player.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "rows_player.h"

static LGFX_Sprite *playerSprite[4][4];

Player::Player() : Player({0, 0}, Direction::DOWN) {
}

Player::Player(Point coord, Direction direction) {
  this->tick = 0;
  this->state = State::IDLE;
  this->direction = direction;
  this->frameNumber = generateRandom(0, PLAYER_IDLE_FRAME_COUNT);
  this->renderDirty = true;
  this->coord.x = coord.x;
  this->coord.y = coord.y;
  this->oldCoord.x = coord.x;
  this->oldCoord.y = coord.y;
}

EntityType Player::getType() {
  return PLAYER;
}

Player::~Player() {
}

void Player::handleEvents() {
  switch (getPressedButton()) {
  case LEFT_BUTTON:
    this->direction = Direction::LEFT;
    break;
  case RIGHT_BUTTON:
    this->direction = Direction::RIGHT;
    break;
  case DOWN_BUTTON:
    this->direction = Direction::DOWN;
    break;
  case UP_BUTTON:
    this->direction = Direction::UP;
    break;
  default:
    return;
  }

  tft.startWrite();

  // Olduğun Yeri Erit (Mantıksal)
  if (isIce) {
    wallMap[this->coord.y][this->coord.x] = true;
  }

  stepCount++;

  for (int i = 0; i < entitiesCount; i++) {
    if (entities[i] != NULL) {
      entities[i]->update(i);
    }
  }

  killEntities();
  tft.endWrite();
}

void Player::update(int currentId) {
  this->renderDirty = true;

  // Harita Dışı ya da Su'ya Düştün
  if (!isMoveAllowed(this->coord, this->direction)) {
    changeMenu(LOSE_MENU);
    return;
  }

  // Eski Konumu Temizle
  if (entityIdMap[this->coord.y][this->coord.x] == currentId) {
    entityIdMap[this->coord.y][this->coord.x] = -1;
  }

  // Olduğun Yeri Erit (Render)
  if (isIce) {
    calcMapTile(this->coord.y, this->coord.x);
    calcMapTile(this->coord.y, this->coord.x + 1);
    calcMapTile(this->coord.y + 1, this->coord.x);
    calcMapTile(this->coord.y + 1, this->coord.x + 1);
    renderMapTile(this->coord.y, this->coord.x);
    renderMapTile(this->coord.y, this->coord.x + 1);
    renderMapTile(this->coord.y + 1, this->coord.x);
    renderMapTile(this->coord.y + 1, this->coord.x + 1);
  }

  // Hareket Et
  Point vector = getDirectionVector(this->direction);
  this->coord.x += vector.x;
  this->coord.y += vector.y;

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
    collectedCoinCount++;
    return;
  // Oyun Bitti!
  // Tüm Altınlar Toplandıysa Oyunu Kazandın!
  // Altınların Tamamı Toplanmadıysa Oyunu Kaybettin!
  case EntityType::PORTAL:
    if (totalCoinCount > 0) {
      changeMenu(LOSE_MENU);
    } else {
      changeMenu(WIN_MENU);
    }
    return;
  // Düşmana Çarptın Oyun Bitti
  case EntityType::ENEMY:
    // Düşman Daha Önceden Hareket Etmiş ve Aynı Konumdayız
    if (entityId < currentId) {
      changeMenu(LOSE_MENU);
    }
    // Düşman Daha Hareket Etmedi, Ancak Benim Zıt Yönüme Hareket Ederse de Çarpışırız
    else if (entities[entityId]->getDirection() == getOppositeDirection(this->direction)) {
      changeMenu(LOSE_MENU);
    }
    return;
  }
}

void Player::updateAnimation(unsigned long deltaTime) {
  this->tick += deltaTime;
  // Update Zamanı Gelmedi
  if (this->tick < FRAME_TICK) {
    return;
  }
  // Güncelle
  this->tick -= FRAME_TICK;
  this->frameNumber = (this->frameNumber + 1) % PLAYER_IDLE_FRAME_COUNT;
  this->renderDirty = true;
}

void Player::render() {
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
  drawSpriteFromSprite(playerSprite[this->direction][this->frameNumber], &tileSprite, 0, 0, 0, 0, TILE_SIZE, TILE_SIZE, true);
  renderTile(tileSprite, OFFSET_X + this->coord.x * TILE_SIZE, OFFSET_Y + this->coord.y * TILE_SIZE);
}

void Player::onDeath() {
}

Direction Player::getDirection() {
  return this->direction;
}

bool setupPlayer() {
  return readImageAtlas("/texture/player/IDLE", playerSprite, 4, 4);
}

bool initPlayer(Point coord, Direction direction) {
  Player *entity = new Player(coord, direction);
  entityIdMap[coord.y][coord.x] = entitiesCount;
  return createEntity(entity);
}
