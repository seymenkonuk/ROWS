// ============================================================================
// File:    Screen.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "device/Screen.h"

#if defined(PARALLEL_CONNECTION)
LGFX::LGFX() {
  // Bus Ayarları
  {
    auto cfg = _bus.config();

    cfg.freq_write = 20000000;
    cfg.pin_wr = WR_PIN;
    cfg.pin_rd = RD_PIN;
    cfg.pin_rs = RS_PIN;

    cfg.pin_d0 = D0_PIN;
    cfg.pin_d1 = D1_PIN;
    cfg.pin_d2 = D2_PIN;
    cfg.pin_d3 = D3_PIN;
    cfg.pin_d4 = D4_PIN;
    cfg.pin_d5 = D5_PIN;
    cfg.pin_d6 = D6_PIN;
    cfg.pin_d7 = D7_PIN;

    _bus.config(cfg);
    _panel.setBus(&_bus);
  }

  // Panel Ayarları
  {
    auto cfg = _panel.config();
    cfg.pin_cs = CS_PIN;
    cfg.pin_rst = RST_PIN;
    cfg.pin_busy = -1;

    _panel.config(cfg);
  }

  // Dokunmatik Ekran Ayarları
  {
    auto cfg = _touch.config();

    cfg.x_min = 0;
    cfg.x_max = SHORT_SIDE - 1;
    cfg.y_min = 0;
    cfg.y_max = LONG_SIDE - 1;

    cfg.pin_sda = SDA_PIN;
    cfg.pin_scl = SCL_PIN;
    cfg.pin_int = INT_PIN;
    cfg.pin_rst = RST_PIN;
    cfg.i2c_port = 0;
    cfg.i2c_addr = 0x15;

    _touch.config(cfg);
    _panel.setTouch(&_touch);
  }

  setPanel(&_panel);
}
#elif defined(SPI_CONNECTION)
LGFX::LGFX() {
  // Bus Ayarları
  {
    auto cfg = _bus.config();
    cfg.spi_host = VSPI_HOST;
    cfg.spi_mode = 0;
    cfg.freq_write = 40000000;
    cfg.freq_read = 16000000;
    cfg.spi_3wire = false;
    cfg.use_lock = true;
    cfg.dma_channel = 1;
    cfg.pin_sclk = SCK_PIN;
    cfg.pin_mosi = MOSI_PIN;
    cfg.pin_miso = MISO_PIN;
    cfg.pin_dc = DC_PIN;
    _bus.config(cfg);
    _panel.setBus(&_bus);
  }

  // Panel Ayarları
  {
    auto cfg = _panel.config();
    cfg.pin_cs = CS_PIN;
    cfg.pin_rst = RST_PIN;
    cfg.pin_busy = -1;
    _panel.config(cfg);
  }

  // Dokunmatik Ekran Ayarları
  {
    auto cfg = _touch.config();

    cfg.x_min = 0;
    cfg.x_max = SHORT_SIDE - 1;
    cfg.y_min = 0;
    cfg.y_max = LONG_SIDE - 1;

    cfg.spi_host = VSPI_HOST;
    cfg.freq = 2500000;
    cfg.pin_sclk = T_CLK_PIN;
    cfg.pin_mosi = T_DIN_PIN;
    cfg.pin_miso = T_DO_PIN;
    cfg.pin_cs = T_CS_PIN;
    cfg.pin_int = -1;
    cfg.bus_shared = true;
    cfg.offset_rotation = 0;

    _touch.config(cfg);
    _panel.setTouch(&_touch);
  }

  setPanel(&_panel);
}
#endif

LGFX Screen::tft;

bool Screen::init() {
  bool result;
  result = tft.begin();
  tft.setRotation(SCREEN_ORIENTATION);
  tft.setBrightness(255);
  tft.setColorDepth(COLOR_DEPTH);
  tft.setTextDatum(MC_DATUM);
  return result;
}

void Screen::fillScreen(uint32_t color) {
  tft.fillScreen(color);
}

void Screen::setFillColor(uint32_t color) {
  tft.setColor(color);
}

void Screen::drawRect(int32_t pos_x, int32_t pos_y, int32_t width, int32_t height) {
  tft.drawRect(pos_x, pos_y, width, height);
}

void Screen::fillRect(int32_t pos_x, int32_t pos_y, int32_t width, int32_t height) {
  tft.fillRect(pos_x, pos_y, width, height);
}

void Screen::drawCircle(int32_t pos_x, int32_t pos_y, uint32_t r) {
  tft.drawCircle(pos_x, pos_y, r);
}

void Screen::fillCircle(int32_t pos_x, int32_t pos_y, uint32_t r) {
  tft.fillCircle(pos_x, pos_y, r);
}

void Screen::setTextDatum(textdatum_t datum) {
  tft.setTextDatum(datum);
}

void Screen::setTextColor(uint32_t color) {
  tft.setTextColor(color);
}

void Screen::setTextSize(uint32_t size) {
  tft.setTextSize(size);
}

void Screen::drawText(const String &text, int32_t pos_x, int32_t pos_y) {
  tft.drawString(text, pos_x, pos_y);
}

void Screen::drawText(const char *text, int32_t pos_x, int32_t pos_y) {
  tft.drawString(text, pos_x, pos_y);
}
