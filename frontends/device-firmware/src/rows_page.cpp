// ============================================================================
// File:    rows_page.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "rows_game.h"
#include "rows_ota.h"
#include "rows_random.h"
#include "rows_screen.h"

#define BACKGROUND_COLOR CONVERT_COLOR(0x6B, 0xB5, 0xFF)

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// START ROWS_PAGE_CPP
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

static String loseMessages[] = {"Basarisizlik yok, dene!", "Hata, ogrenmenin yolu!", "Yine dene, pes etme!",    "Denedikce guclenirsin!",  "Ogrenmek sabir ister!",
                                "Her deneme degerli!",     "Denemeye devam et!",     "Her seferinde daha iyi!", "Vazgecme, basaracaksin!", "Bir adim daha yakinsin!"};

void writeCenterScreen(String text, int textSize) {
  tft.setTextDatum(MC_DATUM);
  tft.setTextSize(textSize);
  tft.drawString(text, 160, 120);
}

void showScreenLoadingMenu() {
  tft.fillScreen(BACKGROUND_COLOR);
  tft.setTextSize(3);
  drawTextWithShadow("YUKLENIYOR...", MC_DATUM, 160, 120, 0, 3, lgfx::color888(0xFF, 0xFF, 0xFF), lgfx::color888(0x00, 0x00, 0x00));
}

void showScreenMainMenu() {
  tft.fillScreen(BACKGROUND_COLOR);
  tft.setTextSize(4);
  drawTextWithBorder("ROWS GAME", MC_DATUM, 160, 120, 4, lgfx::color888(0xFF, 0xFF, 0xFF), lgfx::color888(0x00, 0x00, 0x00));
  tft.setTextSize(2);
  drawTextWithShadow(currentSoftwareVersion, TL_DATUM, 4, 4, 0, 2, lgfx::color888(0xFF, 0xFF, 0xFF), lgfx::color888(0x00, 0x00, 0x00));
}

void showScreenWinMenu() {
  char scoreText[100];
  int index;
  index = snprintf(scoreText, sizeof(scoreText), "ADIM: %02d/%02d - PARA: %02d/%02d", stepCount, maxStepCount, collectedCoinCount, maxCoinCount);
  scoreText[index] = '\0';
  tft.fillScreen(BACKGROUND_COLOR);
  tft.setTextSize(4);
  drawTextWithBorder("Tebrikler!", MC_DATUM, 160, 62, 4, lgfx::color888(0x17, 0x66, 0x17), lgfx::color888(0x21, 0x8F, 0x22));
  tft.setTextSize(2);
  drawTextWithShadow(scoreText, MC_DATUM, 160, 102, 0, 2, lgfx::color888(0xFF, 0xFF, 0xFF), lgfx::color888(0x00, 0x00, 0x00));
  tft.setTextSize(2);
  drawTextWithBorder("[A] TEKRAR OYNA", MC_DATUM, 160, 162, 2, lgfx::color888(0xFF, 0xC2, 0x00), lgfx::color888(0x00, 0x00, 0x00));
  tft.setTextSize(2);
  drawTextWithBorder("[B] YENI OYUN", MC_DATUM, 160, 188, 2, lgfx::color888(0xFF, 0xC2, 0x00), lgfx::color888(0x00, 0x00, 0x00));
}

void showScreenLoseMenu() {
  tft.fillScreen(BACKGROUND_COLOR);
  tft.setTextSize(4);
  drawTextWithBorder("Tekrar Dene!", MC_DATUM, 160, 62, 4, lgfx::color888(0xDD, 0x44, 0x1E), lgfx::color888(0xEC, 0x76, 0x1B));
  tft.setTextSize(2);
  int loseMessageNum = generateRandom(0, sizeof(loseMessages) / sizeof(loseMessages[0]));
  drawTextWithShadow(loseMessages[loseMessageNum], MC_DATUM, 160, 102, 0, 2, lgfx::color888(0xFF, 0xFF, 0xFF), lgfx::color888(0x00, 0x00, 0x00));
  tft.setTextSize(2);
  drawTextWithBorder("[A] TEKRAR OYNA", MC_DATUM, 160, 162, 2, lgfx::color888(0xFF, 0xC2, 0x00), lgfx::color888(0x00, 0x00, 0x00));
  tft.setTextSize(2);
  drawTextWithBorder("[B] YENI OYUN", MC_DATUM, 160, 188, 2, lgfx::color888(0xFF, 0xC2, 0x00), lgfx::color888(0x00, 0x00, 0x00));
}

void showScreenUpdateFailMenu() {
  tft.fillScreen(BACKGROUND_COLOR);
  tft.setTextSize(2);
  drawTextWithShadow("GUNCELLEME BASARISIZ...", MC_DATUM, 160, 120, 0, 2, lgfx::color888(0xFF, 0xFF, 0xFF), lgfx::color888(0x00, 0x00, 0x00));
}

void showScreenUpdatingMenu() {
  tft.fillScreen(BACKGROUND_COLOR);
  tft.setTextSize(2);
  drawTextWithShadow("GUNCELLENIYOR...", MC_DATUM, 160, 120, 0, 2, lgfx::color888(0xFF, 0xFF, 0xFF), lgfx::color888(0x00, 0x00, 0x00));
}
