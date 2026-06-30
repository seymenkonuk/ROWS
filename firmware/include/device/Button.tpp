// ============================================================================
// File:    Button.tpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "device/Button.h"

#include "core/Logger.h"

#include <Arduino.h>

template <uint8_t Pin, bool Pullup, uint16_t DebounceMs> bool Button<Pin, Pullup, DebounceMs>::_state = false;
template <uint8_t Pin, bool Pullup, uint16_t DebounceMs> bool Button<Pin, Pullup, DebounceMs>::_lastRaw = false;
template <uint8_t Pin, bool Pullup, uint16_t DebounceMs> bool Button<Pin, Pullup, DebounceMs>::_changed = false;
template <uint8_t Pin, bool Pullup, uint16_t DebounceMs> uint32_t Button<Pin, Pullup, DebounceMs>::_lastChangeTime = 0;

template <uint8_t Pin, bool Pullup, uint16_t DebounceMs> void Button<Pin, Pullup, DebounceMs>::init() {
  LOG_INFO("Initializing Button<%u>...", Pin);
  if (Pullup)
    pinMode(Pin, INPUT_PULLUP);
  else
    pinMode(Pin, INPUT_PULLDOWN);
}

template <uint8_t Pin, bool Pullup, uint16_t DebounceMs> void Button<Pin, Pullup, DebounceMs>::update() {
  bool raw = readRaw();
  uint32_t now = millis();

  if (raw != _lastRaw) {
    _lastChangeTime = now;
    _lastRaw = raw;
  }

  if ((now - _lastChangeTime) > DebounceMs) {
    if (_state != raw) {
      _state = raw;
      _changed = true;
      LOG_INFO("Button<%d> %s.", Pin, _state ? "pressed" : "released");
    } else {
      _changed = false;
    }
  } else {
    _changed = false;
  }
}

template <uint8_t Pin, bool Pullup, uint16_t DebounceMs> bool Button<Pin, Pullup, DebounceMs>::pressed() {
  return _changed && _state;
}

template <uint8_t Pin, bool Pullup, uint16_t DebounceMs> bool Button<Pin, Pullup, DebounceMs>::released() {
  return _changed && !_state;
}

template <uint8_t Pin, bool Pullup, uint16_t DebounceMs> bool Button<Pin, Pullup, DebounceMs>::held() {
  return _state;
}

template <uint8_t Pin, bool Pullup, uint16_t DebounceMs> bool Button<Pin, Pullup, DebounceMs>::readRaw() {
  if (Pullup)
    return digitalRead(Pin) == LOW;
  else
    return digitalRead(Pin) == HIGH;
}
