// ============================================================================
// File:    Logger.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include <Arduino.h>
#include <stdint.h>

// DEFINES
#define LOG_LEVEL_ERROR 1
#define LOG_LEVEL_WARN 2
#define LOG_LEVEL_INFO 3

#ifndef LOG_LEVEL
#define LOG_LEVEL LOG_LEVEL_ERROR
#endif

#define LOG_COLOR_RESET "\033[0m"
#define LOG_COLOR_RED "\033[31m"
#define LOG_COLOR_YELLOW "\033[33m"
#define LOG_COLOR_GREEN "\033[32m"

#ifdef DEBUG

#define LOG_INIT(baud)                                                                                                                                                                                 \
  do {                                                                                                                                                                                                 \
    Serial.begin(baud);                                                                                                                                                                                \
  } while (0)

#define LOG_BASE(level_str, color, ...)                                                                                                                                                                \
  do {                                                                                                                                                                                                 \
    Serial.print(color);                                                                                                                                                                               \
    Serial.print("[");                                                                                                                                                                                 \
    Serial.print(level_str);                                                                                                                                                                           \
    Serial.print("] ");                                                                                                                                                                                \
    Serial.print(millis());                                                                                                                                                                            \
    Serial.print("ms ");                                                                                                                                                                               \
    Serial.print(__FILE__);                                                                                                                                                                            \
    Serial.print(":");                                                                                                                                                                                 \
    Serial.print(__LINE__);                                                                                                                                                                            \
    Serial.print(" (");                                                                                                                                                                                \
    Serial.print(__FUNCTION__);                                                                                                                                                                        \
    Serial.print(") -> ");                                                                                                                                                                             \
    Serial.printf(__VA_ARGS__);                                                                                                                                                                        \
    Serial.print(LOG_COLOR_RESET);                                                                                                                                                                     \
    Serial.println();                                                                                                                                                                                  \
  } while (0)

#if LOG_LEVEL >= LOG_LEVEL_INFO
#define LOG_INFO(...) LOG_BASE("INFO", LOG_COLOR_GREEN, __VA_ARGS__)
#else
#define LOG_INFO(...)                                                                                                                                                                                  \
  do {                                                                                                                                                                                                 \
  } while (0)
#endif

#if LOG_LEVEL >= LOG_LEVEL_WARN
#define LOG_WARN(...) LOG_BASE("WARN", LOG_COLOR_YELLOW, __VA_ARGS__)
#else
#define LOG_WARN(...)                                                                                                                                                                                  \
  do {                                                                                                                                                                                                 \
  } while (0)
#endif

#if LOG_LEVEL >= LOG_LEVEL_ERROR
#define LOG_ERROR(...) LOG_BASE("ERROR", LOG_COLOR_RED, __VA_ARGS__)
#else
#define LOG_ERROR(...)                                                                                                                                                                                 \
  do {                                                                                                                                                                                                 \
  } while (0)
#endif

#else

#define LOG_INIT(baud)                                                                                                                                                                                 \
  do {                                                                                                                                                                                                 \
  } while (0)

#define LOG_INFO(msg)                                                                                                                                                                                  \
  do {                                                                                                                                                                                                 \
  } while (0)

#define LOG_WARN(msg)                                                                                                                                                                                  \
  do {                                                                                                                                                                                                 \
  } while (0)

#define LOG_ERROR(msg)                                                                                                                                                                                 \
  do {                                                                                                                                                                                                 \
  } while (0)

#endif
