// ============================================================================
// File:    rows_screen.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "rows_screen.h"

#ifdef PARALLEL_CONNECTION
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
#endif

#ifdef SPI_CONNECTION
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

LGFX tft;
LGFX_Sprite tileSprite(&tft);

bool setupScreen() {
  bool result;
  result = tft.begin();
  tft.setRotation(SCREEN_ORIENTATION);
  tft.setBrightness(128);
  tft.setColorDepth(COLOR_DEPTH);
  tft.setTextDatum(MC_DATUM);
  tft.clear();
  showScreenLoadingMenu();
  tileSprite.setColorDepth(COLOR_DEPTH);
  tileSprite.createSprite(TILE_SIZE, TILE_SIZE);
  return result;
}

bool readImageAtlas(const char *srcPath, LGFX_Sprite *destSprite[][4], int atlasW, int atlasH, bool reinitialize) {
  for (int i = 0; i < atlasH; i++) {
    for (int j = 0; j < atlasW; j++) {
      if (reinitialize) {
        destSprite[i][j] = new LGFX_Sprite(&tft);
        destSprite[i][j]->setColorDepth(COLOR_DEPTH);
        destSprite[i][j]->createSprite(TILE_SIZE, TILE_SIZE);
      }
      drawSpriteFromImageFile(srcPath, destSprite[i][j], j * TILE_SIZE, i * TILE_SIZE, 0, 0, TILE_SIZE, TILE_SIZE, TILE_SIZE * atlasW, TILE_SIZE * atlasH, false);
    }
  }
  return true;
}

void drawSpriteFromImageFile(const char *srcPath, LGFX_Sprite *destSprite, int srcX, int srcY, int destX, int destY, int copyW, int copyH, int imageWidth, int imageHeight, bool isTransparent) {
  File file = FileFS.open(srcPath, "r");
  if (!file) {
    return;
  }
  for (int y = 0; y < copyH; y++) {
    size_t rowStart = ((srcY + y) * imageWidth + srcX) * 3;
    file.seek(rowStart, SeekSet);
    for (int x = 0; x < copyW; x++) {
      uint8_t r = file.read();
      uint8_t g = file.read();
      uint8_t b = file.read();
      // Şeffaf Renk
      if (isTransparent && r == TRANSPARENT_R && g == TRANSPARENT_G && b == TRANSPARENT_B) {
        continue;
      }
      destSprite->setColor(CONVERT_COLOR(r, g, b));
      destSprite->drawPixel(destX + x, destY + y);
      yield();
    }
  }
  file.close();
}

void drawSpriteFromSprite(LGFX_Sprite *srcSprite, LGFX_Sprite *destSprite, int srcX, int srcY, int destX, int destY, int copyW, int copyH, bool isTransparent) {
  auto *srcBuf = (COLOR_TYPE *)srcSprite->getBuffer();

  for (int y = 0; y < copyH; y++) {
    const COLOR_TYPE *srcLine = srcBuf + (srcY + y) * TILE_SIZE + srcX;

    for (int x = 0; x < copyW; x++) {
      // Şeffaf Renk
      if (isTransparent && CONVERT_COLOR(TRANSPARENT_R, TRANSPARENT_G, TRANSPARENT_B) == srcLine[x].raw) {
        continue;
      }
      destSprite->setColor(srcLine[x].raw);
      destSprite->drawPixel(destX + x, destY + y);
    }
  }
}

void renderTile(LGFX_Sprite sprite, int positionX, int positionY) {
  tft.startWrite();
  tft.setClipRect(positionX, positionY, TILE_SIZE, TILE_SIZE);

  sprite.pushSprite(positionX, positionY, CONVERT_COLOR(TRANSPARENT_R, TRANSPARENT_G, TRANSPARENT_B));

  tft.clearClipRect();
  tft.endWrite();
}

bool isScreenTouched(uint16_t *x, uint16_t *y) {
  return tft.getTouch(x, y);
}
