// ============================================================================
// File:    rows_menu.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "rows_menu.h"

Menu activeMenu = LOADING_MENU;

void changeMenu(Menu newMenu) {
  // Menüler Arası Geçiş İzni Var mı?
  switch (activeMenu) {
  case LOADING_MENU:
    if (newMenu != MAIN_MENU && newMenu != UPDATE_MENU) {
      return;
    }
    break;
  case MAIN_MENU:
    if (newMenu != GAME_MENU && newMenu != UPDATE_MENU) {
      return;
    }
    break;
  case GAME_MENU:
    if (newMenu != MAIN_MENU && newMenu != GAME_MENU && newMenu != WIN_MENU && newMenu != LOSE_MENU && newMenu != UPDATE_MENU) {
      return;
    }
    break;
  case WIN_MENU:
    if (newMenu != MAIN_MENU && newMenu != GAME_MENU && newMenu != UPDATE_MENU) {
      return;
    }
    break;
  case LOSE_MENU:
    if (newMenu != MAIN_MENU && newMenu != GAME_MENU && newMenu != UPDATE_MENU) {
      return;
    }
    break;
  case UPDATE_MENU:
    if (newMenu != UPDATE_FAIL_MENU) {
      return;
    }
    break;
  case UPDATE_FAIL_MENU:
    if (newMenu != MAIN_MENU && newMenu != GAME_MENU && newMenu != UPDATE_MENU) {
      return;
    }
    break;
  }

  // Oyun Menüsündeydiysem ve Menü Değişiyorsa
  if (activeMenu == GAME_MENU) {
    clearGame();
  }

  // Menüyü Değiştir
  activeMenu = newMenu;

  // Menüyü Göster
  switch (activeMenu) {
  case LOADING_MENU:
    showScreenLoadingMenu();
    break;
  case MAIN_MENU:
    playMusic("/musics/MAIN", true);
    showScreenMainMenu();
    break;
  case GAME_MENU:
    playMusic("/musics/GAME", true);
    startGame();
    break;
  case WIN_MENU:
    playMusic("/musics/WIN", false);
    showScreenWinMenu();
    break;
  case LOSE_MENU:
    playMusic("/musics/LOSE", false);
    showScreenLoseMenu();
    break;
  case UPDATE_MENU:
    showScreenUpdatingMenu();
    break;
  case UPDATE_FAIL_MENU:
    playMusic("/musics/LOSE", false);
    showScreenUpdateFailMenu();
    break;
  }
}

void handleMenu(unsigned long deltaTime, wl_status_t wifi_status) {
  switch (activeMenu) {
  case LOADING_MENU:
    // Her Şey Yüklendiyse Ana Menüye Geç
    if (wifi_status != WL_DISCONNECTED && wifi_status != WL_IDLE_STATUS) {
      changeMenu(MAIN_MENU);
    }
    break;

  case MAIN_MENU:
    // Start Tuşuna Basıldıysa Oyun Menüsüne Geç
    switch (getPressedButton()) {
    case A_BUTTON:
      setGameRandom();
      changeMenu(GAME_MENU);
      break;
    }
    break;

  case GAME_MENU:
    handleGame(deltaTime);
    break;

  case WIN_MENU:
  case LOSE_MENU:
    switch (getPressedButton()) {
    case A_BUTTON:
      changeMenu(GAME_MENU);
      break;
    case B_BUTTON:
      setGameRandom();
      changeMenu(GAME_MENU);
      break;
    }
    break;

  case UPDATE_FAIL_MENU:
    // Start Tuşuna Basıldıysa Ana Menüye Geç
    switch (getPressedButton()) {
    case A_BUTTON:
      changeMenu(MAIN_MENU);
      break;
    }
    break;

  default:
    break;
  }
}
