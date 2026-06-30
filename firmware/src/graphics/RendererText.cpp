// ============================================================================
// File:    RendererText.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "graphics/Renderer.h"

void Renderer::setTextDatum(textdatum_t datum) {
  Screen::setTextDatum(datum);
}

void Renderer::setTextColor(uint32_t color) {
  Screen::setTextColor(color);
}

void Renderer::setTextSize(uint32_t size) {
  Screen::setTextSize(size);
}

void Renderer::drawText(const String &text, const Point &pos) {
  Screen::drawText(text, pos.x, pos.y);
}

void Renderer::drawText(const char *text, const Point &pos) {
  Screen::drawText(text, pos.x, pos.y);
}

void Renderer::drawTextWithBorder(const String &text, const Point &pos, int borderSize, uint32_t textColor, uint32_t borderColor) {
  setTextColor(borderColor);
  for (int dx = -borderSize; dx <= borderSize; dx++) {
    for (int dy = -borderSize; dy <= borderSize; dy++) {
      Point newPos = {x : pos.x + dx, y : pos.y + dy};
      if (dx != 0 || dy != 0) {
        drawText(text, newPos);
      }
    }
  }
  setTextColor(textColor);
  drawText(text, pos);
}

void Renderer::drawTextWithBorder(const char *text, const Point &pos, int borderSize, uint32_t textColor, uint32_t borderColor) {
  setTextColor(borderColor);
  for (int dx = -borderSize; dx <= borderSize; dx++) {
    for (int dy = -borderSize; dy <= borderSize; dy++) {
      Point newPos = {x : pos.x + dx, y : pos.y + dy};
      if (dx != 0 || dy != 0) {
        drawText(text, newPos);
      }
    }
  }
  setTextColor(textColor);
  drawText(text, pos);
}

void Renderer::drawTextWithShadow(const String &text, const Point &pos, const Point &offset, uint32_t textColor, uint32_t shadowColor) {
  Point newPos = {x : pos.x + offset.x, y : pos.y + offset.y};
  setTextColor(shadowColor);
  drawText(text, newPos);
  setTextColor(textColor);
  drawText(text, pos);
}

void Renderer::drawTextWithShadow(const char *text, const Point &pos, const Point &offset, uint32_t textColor, uint32_t shadowColor) {
  Point newPos = {x : pos.x + offset.x, y : pos.y + offset.y};
  setTextColor(shadowColor);
  drawText(text, newPos);
  setTextColor(textColor);
  drawText(text, pos);
}
