// ============================================================================
// File:    MusicPlayer.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "audio/MusicPlayer.h"

#include "audio/MelodyPlayer.h"

#include "core/Logger.h"

#include "device/Speaker.h"

QueueHandle_t MusicPlayer::queue;
Timer<0> *MusicPlayer::timer;

WavHeader MusicPlayer::wavHeader;
File MusicPlayer::wavFile;

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
  isPlaying = true;
  isLooping = loopState;
  // Dosyayı Aç
  if (!openFile(path)) {
    return false;
  }
  // Header'ı Oku
  if (!parseWavHeader()) {
    closeFile();
    return false;
  }
  // Zamanlayıcıyı Başlat
  timer->start(1000000 / wavHeader.sampleRate);
  return true;
}

bool MusicPlayer::play(const String &path, bool loopState) {
  return play(path.c_str(), loopState);
}

void MusicPlayer::rewind() {
  resetFilePosition();
  resume();
}

void MusicPlayer::stop() {
  pause();
  closeFile();
}

void MusicPlayer::pause() {
  isPlaying = false;
  Speaker::stop();
  timer->stop();
  xQueueReset(queue);
}

void MusicPlayer::resume() {
  isPlaying = true;
  timer->start(1000000 / wavHeader.sampleRate);
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
  if (hasMoreSamples()) {
    Speaker::write(readSample());
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

bool MusicPlayer::openFile(const char *path) {
  wavFile = Filesystem::open(path, "r");
  // Dosya Açılamadı
  if (!wavFile) {
    return false;
  }
  return true;
}

void MusicPlayer::closeFile() {
  wavFile.close();
}

bool MusicPlayer::parseWavHeader() {
  size_t size = wavFile.read((uint8_t *)&wavHeader, sizeof(WavHeader));
  if (size != sizeof(WavHeader)) {
    LOG_ERROR("Failed to parse WAV header.");
    return false;
  }
  return true;
}

void MusicPlayer::resetFilePosition() {
  wavFile.seek(sizeof(WavHeader));
}

bool MusicPlayer::hasMoreSamples() {
  return wavFile && wavFile.available();
}

uint8_t MusicPlayer::readSample() {
  return wavFile.read();
}
