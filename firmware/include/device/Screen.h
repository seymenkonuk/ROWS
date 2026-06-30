// ============================================================================
// File:    Screen.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include <LovyanGFX.hpp>

// DEFINES
#define LONG_SIDE 320
#define SHORT_SIDE 240

// BAĞLANTI ŞEKLİ
// #define PARALLEL_CONNECTION
#define SPI_CONNECTION

// ŞEFFAF RENK
#define TRANSPARENT_R 0x52
#define TRANSPARENT_G 0x4f
#define TRANSPARENT_B 0x57

// RENK DERİNLİĞİ
#define COLOR_DEPTH 8
#define COLOR lgfx::color888

#if COLOR_DEPTH == 8
#define CONVERT_COLOR lgfx::color332
#define COLOR_TYPE lgfx::rgb332_t
#elif COLOR_DEPTH == 16
#define CONVERT_COLOR lgfx::color565
#define COLOR_TYPE lgfx::rgb565_t
#elif COLOR_DEPTH == 24
#define CONVERT_COLOR lgfx::color888
#define COLOR_TYPE lgfx::rgb888_t
#endif

// PARALEL BAĞLANTI PİNLERİ
#if defined(PARALLEL_CONNECTION)
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

// SPI BAĞLANTI PİNLERİ
#elif defined(SPI_CONNECTION)
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

// CLASSES
class LGFX : public lgfx::LGFX_Device {
public:
  LGFX();

private:
#if defined(PARALLEL_CONNECTION)
  lgfx::Panel_ST7789 _panel;
  lgfx::Bus_Parallel8 _bus;
  lgfx::Touch_CST816S _touch;
#elif defined(SPI_CONNECTION)
  lgfx::Panel_ILI9341 _panel;
  lgfx::Bus_SPI _bus;
  lgfx::Touch_XPT2046 _touch;
#endif // SPI_CONNECTION
};

class Screen {
public:
  static bool init();

  // ÇİZİM İLE İLGİLİ (ŞEKİLLER)
  static void fillScreen(uint32_t color);
  static void setFillColor(uint32_t color);

  static void drawRect(int32_t pos_x, int32_t pos_y, int32_t width, int32_t height);
  static void fillRect(int32_t pos_x, int32_t pos_y, int32_t width, int32_t height);
  static void drawCircle(int32_t pos_x, int32_t pos_y, uint32_t r);
  static void fillCircle(int32_t pos_x, int32_t pos_y, uint32_t r);

  // METİN İLE İLGİLİ
  static void setTextDatum(textdatum_t datum);
  static void setTextColor(uint32_t color);
  static void setTextSize(uint32_t size);

  static void drawText(const String &text, int32_t pos_x, int32_t pos_y);
  static void drawText(const char *text, int32_t pos_x, int32_t pos_y);

private:
  static LGFX tft;
};
