// ============================================================================
// File:    Timer.tpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "core/system/Timer.h"

#include "core/Logger.h"

template <uint8_t timerId> Timer<timerId> *Timer<timerId>::instance = nullptr;

template <uint8_t timerId> void IRAM_ATTR Timer<timerId>::onTimerStatic() {
  if (instance && instance->callback) {
    instance->callback();
  }
}

template <uint8_t timerId> Timer<timerId> *Timer<timerId>::create() {
  LOG_INFO("Creating Timer<%u>...", timerId);
  // İnstance Yoksa Üret
  if (!instance) {
    LOG_INFO("Timer<%u> created successfully.", timerId);
    instance = new Timer<timerId>();
    return instance;
  }
  // Varsa null Döndür (Aynı Timer İki Kişi Kullanamaz)
  LOG_ERROR("Timer creation failed: Timer<%u> is already in use.", timerId);
  return nullptr;
}

template <uint8_t timerId> void Timer<timerId>::init(uint16_t prescaler, void (*cb)()) {
  LOG_INFO("Initializing Timer<%u>...", timerId);
  // Degişkenleri Ayarla
  callback = cb;
  // Zamanlayıcıyı Ayarla
  timer = timerBegin(timerId, prescaler, true);
  timerAttachInterrupt(timer, &Timer<timerId>::onTimerStatic, true);
}

template <uint8_t timerId> void Timer<timerId>::start(uint32_t period_us) {
  LOG_INFO("Starting Timer<%u>...", timerId);
  timerAlarmDisable(timer);
  timerAlarmWrite(timer, period_us, true);
  timerAlarmEnable(timer);
}

template <uint8_t timerId> void Timer<timerId>::stop() {
  LOG_INFO("Stopping Timer<%u>...", timerId);
  timerAlarmDisable(timer);
}
