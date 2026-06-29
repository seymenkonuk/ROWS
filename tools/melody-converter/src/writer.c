// ============================================================================
// File:    writer.c
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "writer.h"

#include "song.h"

#include <stdio.h>

void writeMelody(const char *filename) {
  FILE *file = fopen(filename, "wb");

  // Dosya Açılamadı
  if (!file) {
    perror(filename);
    return;
  }

  // Tempo Bilgisini Dosyaya Yaz
  fwrite(&songTempo, 1, 1, file);

  // Nota Bilgilerini Dosyaya Yaz
  for (unsigned int i = 0; i < songLength; i++) {
    // Nota Bilgisini Diziden Al
    uint8_t frequencyId = (uint8_t)songNotes[i].frequency;
    uint8_t durationId = (uint8_t)songNotes[i].duration;
    // Nota Bilgisini Dosyaya Yaz
    fwrite(&frequencyId, 1, 1, file);
    fwrite(&durationId, 1, 1, file);
  }

  // Dosyayı Kapat
  fclose(file);
}
