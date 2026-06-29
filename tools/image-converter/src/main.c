// ============================================================================
// File:    main.c
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "writer.h"

#ifndef OUTPUT
#define OUTPUT "image.rif"
#endif

int main(void) {
  writeImage("out/" OUTPUT);
  return 0;
}
