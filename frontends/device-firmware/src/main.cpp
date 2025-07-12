// ============================================================================
// File:    main.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "rows_client.h"
#include "rows_controller.h"
#include "rows_filesystem.h"
#include "rows_mqtt.h"
#include "rows_music.h"
#include "rows_ota.h"
#include "rows_screen.h"
#include "rows_server.h"
#include "rows_wifi.h"

static unsigned long previousTime = 0;
static unsigned long currentTime = 0;
static unsigned long deltaTime = 0;

static bool checkOTA = true;
static bool isMqttConnected = false;

void setup() {
  Serial.begin(115200);
  setupScreen();
  setupFileSystem();
  setupController();
  setupWifi();
  setupClient();
  setupOTA();
  setupGame();
  setupWebServer();
  startAP();
  if (!connectWifi()) {
    changeMenu(MAIN_MENU);
  }
  previousTime = millis();
}

void loop() {
  // Delta Time Hesapla
  currentTime = millis();
  deltaTime = currentTime - previousTime;
  previousTime = currentTime;

  wl_status_t wifi_status = WiFi.status();

  // Wi-Fi'ye bağlandıktan sonra yapılması gereken işlemler
  if (wifi_status == WL_CONNECTED) {
    // OTA Güncellemesi Kontrol Et
    if (checkOTA) {
      checkOTAandUpdate();
      checkOTA = false;
    }
    // MQTT'ye Bağlan
    if (!isMqttConnected) {
      connectMQTT();
      isMqttConnected = true;
    }
  } else {
    // Bağlantı Koptuktan Sonra, Tekrar İnternete Bağlandığında OTA ve MQTT Baştan Yapılsın
    checkOTA = true;
    isMqttConnected = false;
  }

  // Menüler Arası Geçiş Butonlarını Kontrol Et
  handleMenu(deltaTime, wifi_status);

  // Server'ı Yönet
  server.handleClient();
  // MQTT Bağlantısını Sürdür
  mqttClient.loop();
  // Müziği Devam Ettir
  handleMusic();
}
