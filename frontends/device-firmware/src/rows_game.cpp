// ============================================================================
// File:    rows_game.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "rows_game.h"

static String gameNotation = "";
bool isIce;
int totalCoinCount;
int collectedCoinCount;
int stepCount;

int maxCoinCount;
int maxStepCount;

static void handleEvent() {
  for (int i = 0; i < entitiesCount; i++) {
    if (entities[i] != NULL) {
      entities[i]->handleEvents();
    }
  }
}

static void updateAnimation(unsigned long deltaTime) {
  for (int i = 0; i < entitiesCount; i++) {
    if (entities[i] != NULL) {
      entities[i]->updateAnimation(deltaTime);
    }
  }
}

static void render() {
  for (int i = 0; i < entitiesCount; i++) {
    if (entities[i] != NULL) {
      entities[i]->render();
    }
  }
}

void handleGame(unsigned long deltaTime) {
  handleEvent();
  updateAnimation(deltaTime);
  render();
}

bool setupGame() {
  return setupEntities();
}

bool clearGame() {
  return clearEntities();
}

static bool checkNotation(String notation) {
  int playerCount = 0;
  int portalCount = 0;
  // uzunluk kontrol
  if (notation.length() != 2 * MAP_WIDTH * MAP_HEIGHT + 2 + MAP_HEIGHT) {
    return false;
  }
  // METADATA KONTROL
  if (notation[0] != '#' || (notation[1] != 'F' && notation[1] != 'I') || notation[2] != '#') {
    return false;
  }
  // satır sonu kontrol
  for (int i = 1; i < MAP_HEIGHT; i++) {
    if (notation.charAt((2 * MAP_WIDTH + 1) * i + 2) != '/') {
      return false;
    }
  }
  // hücre kontrol
  int index = 3;
  for (int i = 0; i < MAP_HEIGHT; i++) {
    for (int j = 0; j < MAP_WIDTH; j++) {
      char direction = notation[index];
      char entityType = notation[index + 1];
      String cell = String(notation[index]) + String(notation[index + 1]);
      if (entityType == 'P')
        playerCount++;
      if (cell == "Dd")
        portalCount++;

      if (cell != "Ww" && cell != "Rr" && cell != "Dd" && cell != "Cc") {
        if (entityType != 'P' && entityType != 'E') {
          return false;
        }
        if (direction != 'd' && direction != 'u' && direction != 'r' && direction != 'l') {
          return false;
        }
      }
      index += 2;
    }
    index += 1;
  }
  if (playerCount != 1)
    return false;
  if (portalCount != 1)
    return false;
  return true;
}

static void createWallMap(String notation) {
  int index = 3;
  for (int i = 0; i < MAP_HEIGHT; i++) {
    for (int j = 0; j < MAP_WIDTH; j++) {
      String cell = String(gameNotation[index]) + String(gameNotation[index + 1]);
      wallMap[i][j] = (cell == "Ww");
      index += 2;
    }
    index += 1;
  }
  createMapTile();
}

static void resetEntityIdMap() {
  for (int i = 0; i < MAP_HEIGHT; i++) {
    for (int j = 0; j < MAP_WIDTH; j++) {
      entityIdMap[i][j] = -1;
    }
  }
}

static void createEntities(String notation) {
  int index = 3;
  for (int8_t i = 0; i < MAP_HEIGHT; i++) {
    for (int8_t j = 0; j < MAP_WIDTH; j++) {
      Direction direction;
      char directionChar = gameNotation[index];
      char entityType = gameNotation[index + 1];
      String cell = String(gameNotation[index]) + String(gameNotation[index + 1]);
      if (cell != "Ww" && cell != "Rr") {
        // select direction
        switch (directionChar) {
        case 'd':
          direction = DOWN;
          break;
        case 'u':
          direction = UP;
          break;
        case 'r':
          direction = RIGHT;
          break;
        case 'l':
          direction = LEFT;
          break;
        }
        // select type
        if (cell == "Dd") {
          initPortal({j, i});
        } else if (cell == "Cc") {
          totalCoinCount++;
          initCoin({j, i});
        } else if (entityType == 'P') {
          initPlayer({j, i}, direction);
        } else if (entityType == 'E') {
          initEnemy({j, i}, direction);
        }
      }
      index += 2;
    }
    index += 1;
  }
}

// gameNotation oyununu başlatır
bool startGame() {
  totalCoinCount = 0;
  collectedCoinCount = 0;
  stepCount = 0;
  isIce = gameNotation.charAt(1) == 'I';
  initMap(isIce);
  createWallMap(gameNotation);
  resetEntityIdMap();
  createEntities(gameNotation);
  maxCoinCount = totalCoinCount;
  maxStepCount = 99;
  return true;
}

// gameNotation'ı rastgele değiştirir
bool setGameRandom() {
  latestTopic = NULL;
  resetEntityIdMap();
  gameNotation = generateRandomGame();
  return true;
}

// gameNotation'ı parametrede aldığı gibi yapar!
bool setGameWithNotation(String notation) {
  if (!checkNotation(notation)) {
    return false;
  }
  gameNotation = notation;
  return true;
}
