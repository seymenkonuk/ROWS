// ============================================================================
// File:    MusicPlayer.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "audio/MusicPlayer.h"

#include "core/Logger.h"

#include "device/Speaker.h"

QueueHandle_t MusicPlayer::queue;
Timer<0> *MusicPlayer::timer;

WavFile MusicPlayer::wavFile;

bool MusicPlayer::isPlaying = false;
bool MusicPlayer::isLooping = false;

void MusicPlayer::init() {
  LOG_INFO("Initializing music player...");
  // Zamanlayıcı Oluştur
  timer = Timer<0>::create();
  // Zamanlayıcıyı Kilitle (Başkası Kullanamaz)
  timer->lock();
  // Zamanlayıcıyı Yapılandır
  timer->init(80, onTimer);
  // Kuyruk Oluştur
  queue = xQueueCreate(1024, sizeof(uint8_t));
  // Task Oluştur: Sample Çalma İşlemini Core'1 de Yap
  xTaskCreatePinnedToCore(loopTask, "MusicPlayTask", 4096, NULL, 1, NULL, 1);
}

bool MusicPlayer::play(const char *path, bool loopState) {
  LOG_INFO("Playing music: %s", path);
  // Değişkenleri Ayarla
  isLooping = loopState;
  // Dosyayı Aç
  if (!wavFile.open(path)) {
    LOG_ERROR("Audio play failed: Could not load file %s", path);
    return false;
  }
  // Zamanlayıcıyı Başlat
  resume();
  return true;
}

bool MusicPlayer::play(const String &path, bool loopState) {
  return play(path.c_str(), loopState);
}

void MusicPlayer::rewind() {
  wavFile.rewind();
  resume();
}

void MusicPlayer::stop() {
  pause();
  wavFile.close();
}

void MusicPlayer::pause() {
  isPlaying = false;
  Speaker::stop();
  timer->stop();
  xQueueReset(queue);
}

void MusicPlayer::resume() {
  isPlaying = true;
  timer->start(1000000 / wavFile.header.sampleRate);
}

// Yeni Sample Çalınması Gerektiğinde Tetiklenir
void MusicPlayer::onTimer() {
  // Yeni Sample Çalınması için Kuyruğa Herhangi Bir Değer Gönder
  uint8_t data = 1;
  BaseType_t xHigherPriorityTaskWoken = pdFALSE;

  xQueueSendFromISR(queue, &data, &xHigherPriorityTaskWoken);

  if (xHigherPriorityTaskWoken) {
    portYIELD_FROM_ISR();
  }
}

void MusicPlayer::playSample() {
  // Müzik Devam Ediyorsa Çal
  if (!wavFile.isFinished()) {
    Speaker::write(wavFile.read());
  }
  // Loopta ve Bittiyse Başa Sar
  else if (isLooping) {
    rewind();
  }
  // Loopta Değilse Durdur
  else {
    LOG_INFO("Music finished.");
    stop();
  }
}

void MusicPlayer::loopTask(void *p) {
  uint8_t event;
  while (1) {
    // Kuyruğa Veri Geldiğinde Sample Çal
    if (xQueueReceive(queue, &event, portMAX_DELAY)) {
      playSample();
    }
  }
}
