// ============================================================================
// File:    rows_menu.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#ifndef ROWS_MENU_H
#define ROWS_MENU_H

// INCLUDES
#include "rows_controller.h"
#include "rows_game.h"
#include "rows_music.h"
#include "rows_screen.h"
#include "rows_wifi.h"

typedef enum { LOADING_MENU, MAIN_MENU, GAME_MENU, WIN_MENU, LOSE_MENU, UPDATE_MENU, UPDATE_FAIL_MENU } Menu;

// Extern
extern Menu activeMenu;

// FUNCTIONS
void changeMenu(Menu newMenu);
void handleMenu(unsigned long deltaTime, wl_status_t wifi_status);

#endif // ROWS_MENU_H
