// ============================================================================
// File:    rows_entity.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#ifndef ROWS_ENTITY_H
#define ROWS_ENTITY_H

// INCLUDES
#include "rows_direction.h"

// DEFINES
#define MAX_ENTITIES 100

// ENUMS
typedef enum { PLAYER, PORTAL, ENEMY, COIN, MAP } EntityType;

// CLASSES
class IEntity {
public:
  IEntity() = default;
  virtual ~IEntity() = default;
  virtual void handleEvents() = 0;
  virtual void update(int currentId) = 0;
  virtual void updateAnimation(unsigned long) = 0;
  virtual void render() = 0;
  virtual void onDeath() = 0;
  virtual EntityType getType() = 0;
  virtual Direction getDirection() = 0;
};

// EXTERN
extern IEntity *entities[MAX_ENTITIES];
extern bool killedEntities[MAX_ENTITIES];
extern int entitiesCount;

// FUNCTIONS
bool createEntity(IEntity *entity);
bool deleteEntity(int index);
bool swapEntities(int index1, int index2);
bool killEntities();
bool clearEntities();
bool setupEntities();

// INCLUDES
#include "rows_coin.h"
#include "rows_enemy.h"
#include "rows_map.h"
#include "rows_player.h"
#include "rows_portal.h"

#endif // ROWS_ENTITY_H
