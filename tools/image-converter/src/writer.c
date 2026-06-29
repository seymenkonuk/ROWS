// ============================================================================
// File:    writer.c
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "writer.h"

#include "image.h"

#include <stdio.h>

void writeImage(const char *filename) {
  FILE *file = fopen(filename, "wb");

  // Dosya Açılamadı
  if (!file) {
    perror(filename);
    return;
  }

  // Piksel Renk Verilerini Dosyaya Yaz
  for (unsigned int i = 0; i < imageWidth * imageHeight; i++) {
    // Renk Verilerini Diziden Oku
    uint8_t r = (imageData[i] << 24) >> 24;
    uint8_t g = (imageData[i] << 16) >> 24;
    uint8_t b = (imageData[i] << 8) >> 24;
    uint8_t a = (imageData[i] << 0) >> 24;

    // Renk Saydam ise
    if (a == 0x00) {
      r = TRANSPARENT_R;
      g = TRANSPARENT_G;
      b = TRANSPARENT_B;
    }
    // Saydam Renk ile Denk Geliyorsa
    else if (r == TRANSPARENT_R && g == TRANSPARENT_G && b == TRANSPARENT_B) {
      b = b - 1;
    }
    // Renk Verilerini Dosyaya Yaz
    fwrite(&r, 1, 1, file);
    fwrite(&g, 1, 1, file);
    fwrite(&b, 1, 1, file);
  }

  // Dosyayı Kapat
  fclose(file);
}
