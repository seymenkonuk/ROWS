// ============================================================================
// File:    rows_entity.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "rows_entity.h"

IEntity *entities[MAX_ENTITIES];
bool killedEntities[MAX_ENTITIES];
int entitiesCount = 0;

bool createEntity(IEntity *entity) {
  if (entitiesCount < MAX_ENTITIES) {
    entities[entitiesCount] = entity;
    killedEntities[entitiesCount] = false;
    entitiesCount++;
    return true;
  }
  return false;
}

bool deleteEntity(int index) {
  if (index < 0 || index >= entitiesCount) {
    return false;
  }
  // Sil
  delete entities[index];
  entities[index] = NULL;
  return true;
}

bool swapEntities(int index1, int index2) {
  if (index1 < 0 || index1 >= entitiesCount) {
    return false;
  }
  if (index2 < 0 || index2 >= entitiesCount) {
    return false;
  }
  if (index1 == index2) {
    return false;
  }
  IEntity *entity = entities[index1];
  entities[index1] = entities[index2];
  entities[index2] = entity;
  return true;
}

bool clearEntities() {
  for (int i = 0; i < entitiesCount; i++) {
    delete entities[i];
    entities[i] = NULL;
  }
  entitiesCount = 0;
  return true;
}

bool killEntities() {
  for (int i = 0; i < entitiesCount; i++) {
    if (killedEntities[i] && entities[i] != NULL) {
      entities[i]->onDeath();
      deleteEntity(i);
    }
  }
  return true;
}

bool setupEntities() {
  return setupMap() && setupPlayer() && setupEnemy() && setupPortal() && setupCoin();
}
