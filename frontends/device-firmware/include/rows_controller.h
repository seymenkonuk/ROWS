// ============================================================================
// File:    rows_controller.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#ifndef ROWS_CONTROLLER_H
#define ROWS_CONTROLLER_H

// INCLUDES
#include "rows_screen.h"

// DEFINES
#define LEFT_BUTTON_PIN 32
#define RIGHT_BUTTON_PIN 33
#define DOWN_BUTTON_PIN 34
#define UP_BUTTON_PIN 35
#define A_BUTTON_PIN 25
#define B_BUTTON_PIN 27

// ENUMS
typedef enum { NONE_BUTTON, LEFT_BUTTON, RIGHT_BUTTON, DOWN_BUTTON, UP_BUTTON, A_BUTTON, B_BUTTON } controller_button;

// FUNCTIONS
bool setupController();
controller_button getPressedButton();

#endif // ROWS_CONTROLLER_H
