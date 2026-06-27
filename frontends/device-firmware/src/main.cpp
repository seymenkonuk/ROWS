// ============================================================================
// File:    main.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "app/AppStack.h"

#include "audio/MelodyPlayer.h"

#include "core/system/AppManager.h"
#include "core/system/Filesystem.h"
#include "core/system/InputManager.h"
#include "core/system/Time.h"

#include "device/Screen.h"
#include "device/Speaker.h"

#include "network/APIClient.h"
#include "network/Certificate.h"
#include "network/DeviceServer.h"
#include "network/Network.h"
#include "network/OTAService.h"

void setup() {
  // Donanımı Başlat
  Screen::init();
  InputManager::init();
  Speaker::init();
  // Dosya Sistemini Başlat
  Filesystem::init();
  // Audio'yu Başlat
  MelodyPlayer::init();
  // Network'u Yapılandır
  Network::init();
  Certificate::init();
  DeviceServer::init();
  APIClient::init();
  OTAService::init();
  // Network'u Başlat
  DeviceServer::start();
  Network::startAP();
  Network::connectWifi();
  // Time Init
  Time::init();
  // Uygulamayı Başlat
  AppManager::setApp(AppStack::getSysApp(0));
}

void loop() {
  // Zamanı Güncelle
  Time::update();
  // Inputları Güncelle
  InputManager::update();
  // Uygulamayı Yönet
  AppManager::update(Time::deltaMs());
  AppManager::render();
  // Server'ı Yönet
  DeviceServer::loop();
  // Melodiyi Devam Ettir
  MelodyPlayer::loop();
}
