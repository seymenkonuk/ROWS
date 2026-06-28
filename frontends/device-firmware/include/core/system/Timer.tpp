// ============================================================================
// File:    Timer.tpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "core/system/Timer.h"

template <uint8_t timerId> Timer<timerId> *Timer<timerId>::instance = nullptr;

template <uint8_t timerId> void IRAM_ATTR Timer<timerId>::onTimerStatic() {
  if (instance && instance->callback) {
    instance->callback();
  }
}

template <uint8_t timerId> Timer<timerId> *Timer<timerId>::create() {
  // İnstance Yoksa Üret
  if (!instance) {
    instance = new Timer<timerId>();
    return instance;
  }
  // Varsa null Döndür (Aynı Timer İki Kişi Kullanamaz)
  return nullptr;
}

template <uint8_t timerId> void Timer<timerId>::init(uint16_t prescaler, void (*cb)()) {
  // Degişkenleri Ayarla
  callback = cb;
  // Zamanlayıcıyı Ayarla
  timer = timerBegin(timerId, prescaler, true);
  timerAttachInterrupt(timer, &Timer<timerId>::onTimerStatic, true);
}

template <uint8_t timerId> void Timer<timerId>::start(uint32_t period_us) {
  timerAlarmDisable(timer);
  timerAlarmWrite(timer, period_us, true);
  timerAlarmEnable(timer);
}

template <uint8_t timerId> void Timer<timerId>::stop() {
  timerAlarmDisable(timer);
}
