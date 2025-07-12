// ============================================================================
// File:    rows_game.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#ifndef ROWS_GAME_H
#define ROWS_GAME_H

// INCLUDES
#include "rows_coin.h"
#include "rows_enemy.h"
#include "rows_entity.h"
#include "rows_map.h"
#include "rows_mqtt.h"
#include "rows_player.h"
#include "rows_portal.h"

// EXTERN
extern bool isIce;
extern int totalCoinCount;
extern int collectedCoinCount;
extern int stepCount;
extern int maxCoinCount;
extern int maxStepCount;

// FUNCTIONS
bool setupGame();
bool clearGame();
void handleGame(unsigned long deltaTime);
bool startGame();
bool setGameRandom();
bool setGameWithNotation(String gameNotation);

#endif // ROWS_GAME_H
