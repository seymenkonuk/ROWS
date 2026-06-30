// ============================================================================
// File:    Renderer.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include "core/types/Point.h"
#include "core/types/Size.h"

#include "device/Screen.h"

#include <stdint.h>

// CLASSES
class Renderer {
public:
  // ÇİZİM İLE İLGİLİ (ŞEKİLLER)
  static void fillScreen(uint32_t color);
  static void setFillColor(uint32_t color);

  static void drawRect(const Point &pos, const Size &size);
  static void fillRect(const Point &pos, const Size &size);
  static void drawCircle(const Point &pos, uint32_t r);
  static void fillCircle(const Point &pos, uint32_t r);

  // METİN İLE İLGİLİ
  static void setTextDatum(textdatum_t datum);
  static void setTextColor(uint32_t color);
  static void setTextSize(uint32_t size);

  static void drawText(const String &text, const Point &pos);
  static void drawText(const char *text, const Point &pos);
  static void drawTextWithBorder(const String &text, const Point &pos, int borderSize, uint32_t textColor, uint32_t borderColor);
  static void drawTextWithBorder(const char *text, const Point &pos, int borderSize, uint32_t textColor, uint32_t borderColor);
  static void drawTextWithShadow(const String &text, const Point &pos, const Point &offset, uint32_t textColor, uint32_t shadowColor);
  static void drawTextWithShadow(const char *text, const Point &pos, const Point &offset, uint32_t textColor, uint32_t shadowColor);
};
