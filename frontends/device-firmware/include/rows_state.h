// ============================================================================
// File:    rows_state.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#ifndef ROWS_STATE_H
#define ROWS_STATE_H

// INCLUDES
#include <Arduino.h>

// ENUMS
typedef enum { IDLE, RUN, DEATH } State;

// FUNCTIONS
String getStateName(State state);

#endif // ROWS_STATE_H
