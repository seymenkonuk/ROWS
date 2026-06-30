// ============================================================================
// File:    Renderer.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "graphics/Renderer.h"

void Renderer::fillScreen(uint32_t color) {
  Screen::fillScreen(color);
}

void Renderer::setFillColor(uint32_t color) {
  Screen::setFillColor(color);
}

void Renderer::drawRect(const Point &pos, const Size &size) {
  Screen::drawRect(pos.x, pos.y, size.width, size.height);
}

void Renderer::fillRect(const Point &pos, const Size &size) {
  Screen::fillRect(pos.x, pos.y, size.width, size.height);
}

void Renderer::drawCircle(const Point &pos, uint32_t r) {
  Screen::drawCircle(pos.x, pos.y, r);
}

void Renderer::fillCircle(const Point &pos, uint32_t r) {
  Screen::fillCircle(pos.x, pos.y, r);
}
