// ============================================================================
// File:    rows_direction.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#ifndef ROWS_DIRECTION_H
#define ROWS_DIRECTION_H

// INCLUDES
#include "rows_point.h"

// ENUMS
typedef enum { DOWN, UP, LEFT, RIGHT } Direction;

// FUNCTIONS
Point getDirectionVector(Direction direction);
Direction getOppositeDirection(Direction direction);

#endif // ROWS_DIRECTION_H
