// ============================================================================
// File:    rows_map_manager.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "rows_map.h"

bool wallMap[MAP_HEIGHT][MAP_WIDTH];
int entityIdMap[MAP_HEIGHT][MAP_WIDTH];

Point mapTile[MAP_HEIGHT + 1][MAP_WIDTH + 1];

bool mapTileRenderDirty[MAP_HEIGHT + 1][MAP_WIDTH + 1];

static Point offsets[2][2][2][2] = {2, 1, 3, 1, 2, 2, 1, 2, 2, 0, 3, 2, 0, 1, 3, 3, 1, 1, 2, 3, 1, 0, 0, 2, 3, 0, 0, 0, 1, 3, 0, 3};

// Koordinattaki Tile'ı destSprite'a Çizer
void drawMapTile(LGFX_Sprite *destSprite, int x, int y) {
  LGFX_Sprite *srcSprite;
  Point point;
  for (int y2 = 0; y2 < 2; y2++) {
    for (int x2 = 0; x2 < 2; x2++) {
      const int HALF_TILE_SIZE = TILE_SIZE / 2;
      point = mapTile[y + y2][x + x2];
      srcSprite = (*currentMapSprite)[point.y][point.x];
      drawSpriteFromSprite(srcSprite, destSprite, (1 - x2) * HALF_TILE_SIZE, (1 - y2) * HALF_TILE_SIZE, x2 * HALF_TILE_SIZE, y2 * HALF_TILE_SIZE, HALF_TILE_SIZE, HALF_TILE_SIZE, false);
    }
  }
}

// MapTile Değişkenini Oluşturur
void createMapTile() {
  for (int i = 0; i < MAP_HEIGHT + 1; i++) {
    for (int j = 0; j < MAP_WIDTH + 1; j++) {
      calcMapTile(i, j);
      yield();
    }
  }
}

// Komşularına Bakarak O Tile'a Hangi Resmin Gelmesi Gerektiğini Hesapla
void calcMapTile(int i, int j) {
  int adjacent1, adjacent2, adjacent3, adjacent4;

  adjacent1 = (i - 1 >= 0 && j - 1 >= 0 && wallMap[i - 1][j - 1]) ? 0 : 1;
  adjacent2 = (i - 1 >= 0 && j < MAP_WIDTH && wallMap[i - 1][j]) ? 0 : 1;
  adjacent3 = (i < MAP_HEIGHT && j - 1 >= 0 && wallMap[i][j - 1]) ? 0 : 1;
  adjacent4 = (i < MAP_HEIGHT && j < MAP_WIDTH && wallMap[i][j]) ? 0 : 1;

  mapTile[i][j].x = offsets[adjacent1][adjacent2][adjacent3][adjacent4].x;
  mapTile[i][j].y = offsets[adjacent1][adjacent2][adjacent3][adjacent4].y;
  mapTileRenderDirty[i][j] = true;
}

// Bir Adet Kareyi Renderla
void renderMapTile(int i, int j) {
  int x = OFFSET_X + j * TILE_SIZE - TILE_SIZE / 2;
  int y = OFFSET_Y + i * TILE_SIZE - TILE_SIZE / 2;
  tft.setClipRect(x, y, TILE_SIZE, TILE_SIZE);
  (*currentMapSprite)[mapTile[i][j].y][mapTile[i][j].x]->pushSprite(x, y, CONVERT_COLOR(TRANSPARENT_R, TRANSPARENT_G, TRANSPARENT_B));
  tft.clearClipRect();
}

static bool isRoadCell(Point coord) {
  if (coord.x < 0 || coord.x >= MAP_WIDTH) {
    return false;
  }
  if (coord.y < 0 || coord.y >= MAP_HEIGHT) {
    return false;
  }
  if (wallMap[coord.y][coord.x]) {
    return false;
  }
  return true;
}

static bool isAllowedCell(Point coord) {
  if (!isRoadCell(coord)) {
    return false;
  }
  if (entityIdMap[coord.y][coord.x] != -1) {
    return false;
  }
  return true;
}

bool isMoveAllowed(Point coord, Direction direction) {
  Point new_coord = {coord.x, coord.y};
  Point vector = getDirectionVector(direction);
  new_coord.x += vector.x;
  new_coord.y += vector.y;
  return isRoadCell(new_coord);
}

bool isMoveAllowedForEnemy(Point coord, Direction direction) {
  Point new_coord = {coord.x, coord.y};
  Point vector = getDirectionVector(direction);
  new_coord.x += vector.x;
  new_coord.y += vector.y;
  int entityId = entityIdMap[new_coord.y][new_coord.x];
  return isRoadCell(new_coord) && (entityId == -1 || entities[entityId]->getType() != PORTAL);
}

Point findRandomEmptyCell() {
  Point coord;
  do {
    coord.x = generateRandom(0, MAP_WIDTH);
    coord.y = generateRandom(0, MAP_HEIGHT);
  } while (!isAllowedCell(coord));
  return coord;
}

/*--------------------------------------------------------------------------------------------------------------------------------*/

static int point2notationIndex(int x, int y) {
  return 3 + (MAP_WIDTH * 2 + 1) * y + 2 * x;
}

static int direction2Char(uint8_t direction) {
  switch (direction) {
  case 0:
    return 'd';
  case 1:
    return 'u';
  case 2:
    return 'r';
  default:
    return 'l';
  }
}

static void placeRoadWall(String &notation, int x, int y, bool value) {
  if (value) {
    notation[point2notationIndex(x, y)] = 'W';
    notation[point2notationIndex(x, y) + 1] = 'w';
  } else {
    notation[point2notationIndex(x, y)] = 'R';
    notation[point2notationIndex(x, y) + 1] = 'r';
  }
}

static void placeEntity(String &notation, int x, int y, char c1, char c2) {
  notation[point2notationIndex(x, y)] = c1;
  notation[point2notationIndex(x, y) + 1] = c2;
}

static void fillMap(String &notation, bool value) {
  for (int i = 0; i < MAP_HEIGHT; i++) {
    for (int j = 0; j < MAP_WIDTH; j++) {
      wallMap[i][j] = value;
      placeRoadWall(notation, j, i, value);
      yield();
    }
  }
}

static bool isAdjacent(int x, int y, bool value) {
  if (x - 1 >= 0 && wallMap[y][x - 1] == value) {
    return true;
  }
  if (y - 1 >= 0 && wallMap[y - 1][x] == value) {
    return true;
  }
  if (x + 1 < MAP_WIDTH && wallMap[y][x + 1] == value) {
    return true;
  }
  if (y + 1 < MAP_HEIGHT && wallMap[y + 1][x] == value) {
    return true;
  }
  return false;
}

static Point findAdjacent(bool value) {
  Point point;
  while (1) {
    point.x = generateRandom(0, MAP_WIDTH);
    point.y = generateRandom(0, MAP_HEIGHT);

    if (wallMap[point.y][point.x] == value) {
      continue;
    }

    if (isAdjacent(point.x, point.y, value)) {
      break;
    }
  }

  return point;
}

static void createRandomMap(String &notation) {
  Point point;
  int roadCount;

  // Map'i Tamamen WALL ile Doldur
  fillMap(notation, true);

  // 1 Adet Yere ROAD Yerleştir
  point.x = generateRandom(0, MAP_WIDTH);
  point.y = generateRandom(0, MAP_HEIGHT);

  // Kaç Adet ROAD Olacağını Belirle
  roadCount = generateRandom((MAP_HEIGHT * MAP_WIDTH * 3) / 8, (MAP_HEIGHT * MAP_WIDTH * 3) / 4);

  // O Kadar ROAD Yerleştir
  for (int i = 0; i < roadCount; i++) {
    wallMap[point.y][point.x] = false;
    placeRoadWall(notation, point.x, point.y, false);
    point = findAdjacent(false);
  }
}

static void placeRandomEntities(String &notation) {
  Point point;
  uint8_t enemyCount, coinCount, direction;

  // Karakteri Yerleştir
  point = findRandomEmptyCell();
  entityIdMap[point.y][point.x] = 0;
  direction = generateRandom(0, 4);
  placeEntity(notation, point.x, point.y, direction2Char(direction), 'P');

  // Portalı Yerleştir
  point = findRandomEmptyCell();
  entityIdMap[point.y][point.x] = 0;
  placeEntity(notation, point.x, point.y, 'D', 'd');

  // Düşman ve Altın Sayısını Belirle
  do {
    enemyCount = generateRandom(0, 8);
    coinCount = generateRandom(0, 8);
  } while (enemyCount + coinCount > 13);

  // Düşmanları Yerleştir
  for (int i = 0; i < enemyCount; i++) {
    point = findRandomEmptyCell();
    entityIdMap[point.y][point.x] = 0;
    direction = generateRandom(0, 4);
    placeEntity(notation, point.x, point.y, direction2Char(direction), 'E');
  }

  // Altınları Yerleştir
  for (int i = 0; i < coinCount; i++) {
    point = findRandomEmptyCell();
    entityIdMap[point.y][point.x] = 0;
    placeEntity(notation, point.x, point.y, 'C', 'c');
  }
}

String generateRandomGame() {
  String result;
  result = String("#.#..................../..................../..................../..................../..................../..................../....................");
  // Türü Belirle
  result[1] = generateRandom(0, 100) < 70 ? 'F' : 'I';

  createRandomMap(result);
  placeRandomEntities(result);
  return result;
}
