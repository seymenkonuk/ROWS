// ============================================================================
// File:    pitches.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// FREKANS LİSTESİ
#define NOTE_FREQUENCY_LIST                                                                                                                                                                            \
  X(NOTE_NONE, 0)                                                                                                                                                                                      \
  X(NOTE_B0, 31)                                                                                                                                                                                       \
  X(NOTE_C1, 33)                                                                                                                                                                                       \
  X(NOTE_CS1, 35)                                                                                                                                                                                      \
  X(NOTE_D1, 37)                                                                                                                                                                                       \
  X(NOTE_DS1, 39)                                                                                                                                                                                      \
  X(NOTE_E1, 41)                                                                                                                                                                                       \
  X(NOTE_F1, 44)                                                                                                                                                                                       \
  X(NOTE_FS1, 46)                                                                                                                                                                                      \
  X(NOTE_G1, 49)                                                                                                                                                                                       \
  X(NOTE_GS1, 52)                                                                                                                                                                                      \
  X(NOTE_A1, 55)                                                                                                                                                                                       \
  X(NOTE_AS1, 58)                                                                                                                                                                                      \
  X(NOTE_B1, 62)                                                                                                                                                                                       \
  X(NOTE_C2, 65)                                                                                                                                                                                       \
  X(NOTE_CS2, 69)                                                                                                                                                                                      \
  X(NOTE_D2, 73)                                                                                                                                                                                       \
  X(NOTE_DS2, 78)                                                                                                                                                                                      \
  X(NOTE_E2, 82)                                                                                                                                                                                       \
  X(NOTE_F2, 87)                                                                                                                                                                                       \
  X(NOTE_FS2, 93)                                                                                                                                                                                      \
  X(NOTE_G2, 98)                                                                                                                                                                                       \
  X(NOTE_GS2, 104)                                                                                                                                                                                     \
  X(NOTE_A2, 110)                                                                                                                                                                                      \
  X(NOTE_AS2, 117)                                                                                                                                                                                     \
  X(NOTE_B2, 123)                                                                                                                                                                                      \
  X(NOTE_C3, 131)                                                                                                                                                                                      \
  X(NOTE_CS3, 139)                                                                                                                                                                                     \
  X(NOTE_D3, 147)                                                                                                                                                                                      \
  X(NOTE_DS3, 156)                                                                                                                                                                                     \
  X(NOTE_E3, 165)                                                                                                                                                                                      \
  X(NOTE_F3, 175)                                                                                                                                                                                      \
  X(NOTE_FS3, 185)                                                                                                                                                                                     \
  X(NOTE_G3, 196)                                                                                                                                                                                      \
  X(NOTE_GS3, 208)                                                                                                                                                                                     \
  X(NOTE_A3, 220)                                                                                                                                                                                      \
  X(NOTE_AS3, 233)                                                                                                                                                                                     \
  X(NOTE_B3, 247)                                                                                                                                                                                      \
  X(NOTE_C4, 262)                                                                                                                                                                                      \
  X(NOTE_CS4, 277)                                                                                                                                                                                     \
  X(NOTE_D4, 294)                                                                                                                                                                                      \
  X(NOTE_DS4, 311)                                                                                                                                                                                     \
  X(NOTE_E4, 330)                                                                                                                                                                                      \
  X(NOTE_F4, 349)                                                                                                                                                                                      \
  X(NOTE_FS4, 370)                                                                                                                                                                                     \
  X(NOTE_G4, 392)                                                                                                                                                                                      \
  X(NOTE_GS4, 415)                                                                                                                                                                                     \
  X(NOTE_A4, 440)                                                                                                                                                                                      \
  X(NOTE_AS4, 466)                                                                                                                                                                                     \
  X(NOTE_B4, 494)                                                                                                                                                                                      \
  X(NOTE_C5, 523)                                                                                                                                                                                      \
  X(NOTE_CS5, 554)                                                                                                                                                                                     \
  X(NOTE_D5, 587)                                                                                                                                                                                      \
  X(NOTE_DS5, 622)                                                                                                                                                                                     \
  X(NOTE_E5, 659)                                                                                                                                                                                      \
  X(NOTE_F5, 698)                                                                                                                                                                                      \
  X(NOTE_FS5, 740)                                                                                                                                                                                     \
  X(NOTE_G5, 784)                                                                                                                                                                                      \
  X(NOTE_GS5, 831)                                                                                                                                                                                     \
  X(NOTE_A5, 880)                                                                                                                                                                                      \
  X(NOTE_AS5, 932)                                                                                                                                                                                     \
  X(NOTE_B5, 988)                                                                                                                                                                                      \
  X(NOTE_C6, 1047)                                                                                                                                                                                     \
  X(NOTE_CS6, 1109)                                                                                                                                                                                    \
  X(NOTE_D6, 1175)                                                                                                                                                                                     \
  X(NOTE_DS6, 1245)                                                                                                                                                                                    \
  X(NOTE_E6, 1319)                                                                                                                                                                                     \
  X(NOTE_F6, 1397)                                                                                                                                                                                     \
  X(NOTE_FS6, 1480)                                                                                                                                                                                    \
  X(NOTE_G6, 1568)                                                                                                                                                                                     \
  X(NOTE_GS6, 1661)                                                                                                                                                                                    \
  X(NOTE_A6, 1760)                                                                                                                                                                                     \
  X(NOTE_AS6, 1865)                                                                                                                                                                                    \
  X(NOTE_B6, 1976)                                                                                                                                                                                     \
  X(NOTE_C7, 2093)                                                                                                                                                                                     \
  X(NOTE_CS7, 2217)                                                                                                                                                                                    \
  X(NOTE_D7, 2349)                                                                                                                                                                                     \
  X(NOTE_DS7, 2489)                                                                                                                                                                                    \
  X(NOTE_E7, 2637)                                                                                                                                                                                     \
  X(NOTE_F7, 2794)                                                                                                                                                                                     \
  X(NOTE_FS7, 2960)                                                                                                                                                                                    \
  X(NOTE_G7, 3136)                                                                                                                                                                                     \
  X(NOTE_GS7, 3322)                                                                                                                                                                                    \
  X(NOTE_A7, 3520)                                                                                                                                                                                     \
  X(NOTE_AS7, 3729)                                                                                                                                                                                    \
  X(NOTE_B7, 3951)                                                                                                                                                                                     \
  X(NOTE_C8, 4186)                                                                                                                                                                                     \
  X(NOTE_CS8, 4435)                                                                                                                                                                                    \
  X(NOTE_D8, 4699)                                                                                                                                                                                     \
  X(NOTE_DS8, 4978)

// NOTA SÜRELERİ LİSTESİ
#define NOTE_DURATION_LIST                                                                                                                                                                             \
  X(NOTE_SIXTY_FOURTH, (1.0 / 16.0))                                                                                                                                                                   \
  X(NOTE_THIRTY_SECOND, (1.0 / 8.0))                                                                                                                                                                   \
  X(NOTE_SIXTEENTH, (1.0 / 4.0))                                                                                                                                                                       \
  X(NOTE_EIGHTH, (1.0 / 2.0))                                                                                                                                                                          \
  X(NOTE_DOTTED_EIGHTH, (3.0 / 4.0))                                                                                                                                                                   \
  X(NOTE_QUARTER, (1.0))                                                                                                                                                                               \
  X(NOTE_DOTTED_QUARTER, (3.0 / 2.0))                                                                                                                                                                  \
  X(NOTE_HALF, (2.0))                                                                                                                                                                                  \
  X(NOTE_WHOLE, (4.0))

// NOTA SAYISI
#define X(name, value) +1
static const int NOTE_FREQUENCY_COUNT = 0 NOTE_FREQUENCY_LIST;
#undef X

// NOTA SÜRESİ SAYISI
#define X(name, value) +1
static const int NOTE_DURATION_COUNT = 0 NOTE_DURATION_LIST;
#undef X

// NOTA FREKANSLARI
#define X(name, value) name,
typedef enum { NOTE_FREQUENCY_LIST } NoteFrequency;
#undef X

// NOTA SÜRELERİ
#define X(name, value) name,
typedef enum { NOTE_DURATION_LIST } NoteDuration;
#undef X

// NOTA
typedef struct {
  NoteFrequency frequency;
  NoteDuration duration;
} Note;
