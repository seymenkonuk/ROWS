// ============================================================================
// File:    rows_text.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "rows_screen.h"

void drawTextWithBorder(String text, textdatum_t datum, int x, int y, int borderSize, uint32_t textColor, uint32_t borderColor) {
  tft.setTextDatum(datum);
  tft.setTextColor(borderColor);
  for (int dx = -borderSize; dx <= borderSize; dx++) {
    for (int dy = -borderSize; dy <= borderSize; dy++) {
      if (dx != 0 || dy != 0) {
        tft.drawString(text, x + dx, y + dy);
      }
    }
  }
  tft.setTextColor(textColor);
  tft.drawString(text, x, y);
}

void drawTextWithShadow(String text, textdatum_t datum, int x, int y, int offset_x, int offset_y, uint32_t textColor, uint32_t shadowColor) {
  tft.setTextDatum(datum);
  tft.setTextColor(shadowColor);
  tft.drawString(text, x + offset_x, y + offset_y);
  tft.setTextColor(textColor);
  tft.drawString(text, x, y);
}
