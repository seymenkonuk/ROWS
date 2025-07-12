// ============================================================================
// File:    rows_screen.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#ifndef ROWS_SCREEN_H
#define ROWS_SCREEN_H

// INCLUDES
#include "rows_filesystem.h"
#include <LovyanGFX.hpp>

// DEFINES
#define LONG_SIDE 320
#define SHORT_SIDE 240
#define TILE_SIZE 32

#define FRAME_PER_SECOND 4

// BAĞLANTI ŞEKLİ
// #define PARALLEL_CONNECTION
#define SPI_CONNECTION

// ŞEFFAF RENK
#define TRANSPARENT_R 0x52
#define TRANSPARENT_G 0x4f
#define TRANSPARENT_B 0x57

// RENK DERİNLİĞİ
#define COLOR_DEPTH 8
#define CONVERT_COLOR lgfx::color332
#define COLOR_TYPE lgfx::rgb332_t
// #define COLOR_DEPTH   16
// #define CONVERT_COLOR lgfx::color565
// #define COLOR_TYPE    lgfx::rgb565_t
// #define COLOR_DEPTH   24
// #define CONVERT_COLOR lgfx::color888
// #define COLOR_TYPE    lgfx::rgb888_t

// Frame Tick
#define FRAME_TICK (1000 / FRAME_PER_SECOND)

// PARALEL BAĞLANTI PİNLERİ
#ifdef PARALLEL_CONNECTION
//
#define SCREEN_ORIENTATION 3
// Bus
#define WR_PIN 4
#define RD_PIN 2
#define RS_PIN 16
// Panel
#define CS_PIN 17
#define RST_PIN 0
// Data
#define D0_PIN 15
#define D1_PIN 13
#define D2_PIN 12
#define D3_PIN 14
#define D4_PIN 27
#define D5_PIN 25
#define D6_PIN 33
#define D7_PIN 32
// Dokunmatik
#define SDA_PIN 21
#define SCL_PIN 22
#define INT_PIN 0
//
#define TOUCH_SCREEN
#endif // PARALLEL_CONNECTION

// SPI BAĞLANTI PİNLERİ
#ifdef SPI_CONNECTION
//
#define SCREEN_ORIENTATION 1
// Bus
#define DC_PIN 2
#define MOSI_PIN 23
#define MISO_PIN 19
#define SCK_PIN 18
// Panel
#define CS_PIN 5
#define RST_PIN 4
// Dokunmatik
#define T_DO_PIN MISO_PIN
#define T_DIN_PIN MOSI_PIN
#define T_CLK_PIN SCK_PIN
#define T_CS_PIN 15
//
#endif // SPI_CONNECTION

// EKRAN YÖNÜNE GÖRE BOYLAR
#if SCREEN_ORIENTATION == 2 || SCREEN_ORIENTATION == 0
#define SCREEN_WIDTH SHORT_SIDE
#define SCREEN_HEIGHT LONG_SIDE
#else
#define SCREEN_WIDTH LONG_SIDE
#define SCREEN_HEIGHT SHORT_SIDE
#endif // SCREEN_ORIENTATION == 2 || SCREEN_ORIENTATION == 0

// MAP İLE İLGİLİ
#define MAP_WIDTH (SCREEN_WIDTH / TILE_SIZE)
#define MAP_HEIGHT (SCREEN_HEIGHT / TILE_SIZE)
#define OFFSET_X ((SCREEN_WIDTH - (MAP_WIDTH * TILE_SIZE)) / 2)
#define OFFSET_Y ((SCREEN_HEIGHT - (MAP_HEIGHT * TILE_SIZE)) / 2)

// FUNCTIONS
bool setupScreen();

void showScreenLoadingMenu();
void showScreenMainMenu();
void showScreenWinMenu();
void showScreenLoseMenu();
void showScreenUpdatingMenu();
void showScreenUpdateFailMenu();

void drawTextWithBorder(String text, textdatum_t datum, int x, int y, int borderSize, uint32_t textColor, uint32_t borderColor);
void drawTextWithShadow(String text, textdatum_t datum, int x, int y, int offset_x, int offset_y, uint32_t textColor, uint32_t shadowColor);

bool readImageAtlas(const char *srcPath, LGFX_Sprite *destSprite[][4], int atlasW, int atlasH, bool reinitialize = true);
void drawSpriteFromImageFile(const char *srcPath, LGFX_Sprite *destSprite, int srcX, int srcY, int destX, int destY, int copyW, int copyH, int imageWidth, int imageHeight, bool isTransparent);
void drawSpriteFromSprite(LGFX_Sprite *srcSprite, LGFX_Sprite *destSprite, int srcX, int srcY, int destX, int destY, int copyW, int copyH, bool isTransparent);
bool isScreenTouched(uint16_t *x, uint16_t *y);
void renderTile(LGFX_Sprite sprite, int positionX, int positionY);

// CLASSES
class LGFX : public lgfx::LGFX_Device {

#ifdef PARALLEL_CONNECTION
  lgfx::Panel_ST7789 _panel;
  lgfx::Bus_Parallel8 _bus;
  lgfx::Touch_CST816S _touch;
#endif // PARALLEL_CONNECTION

#ifdef SPI_CONNECTION
  lgfx::Panel_ILI9341 _panel;
  lgfx::Bus_SPI _bus;
  lgfx::Touch_XPT2046 _touch;
#endif // SPI_CONNECTION

public:
  LGFX();
};

// EXTERN
extern LGFX tft;
extern LGFX_Sprite tileSprite;

#endif // ROWS_SCREEN_H
