// ============================================================================
// File:    main.c
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "writer.h"

#ifndef OUTPUT
#define OUTPUT "song.rmf"
#endif

int main(void) {
  writeMelody("out/" OUTPUT);
  return 0;
}
