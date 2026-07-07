// ============================================================================
// File:    NetManager.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "app/system/netmanager/NetManager.h"

#include "app/AppStack.h"

#include "core/system/AppManager.h"
#include "core/system/InputManager.h"

#include "graphics/Renderer.h"

#include "network/DeviceServer.h"
#include "network/Network.h"

const char *NetManager::getName() {
  return "Network Manager";
}

uint32_t NetManager::getColor() {
  return COLOR(220, 220, 220);
}

void NetManager::onEnter() {
  selectedIndex = 0;
  isDirty = true;
}

void NetManager::onExit() {
}

void NetManager::update(uint32_t deltaTime) {
  // Bir Önceki Ayara Geç
  if (InputManager::buttonUp.pressed()) {
    selectedIndex = (selectedIndex == 0) ? 2 : selectedIndex - 1;
    isDirty = true;
  }
  // Bir Sonraki Ayara Geç
  else if (InputManager::buttonDown.pressed()) {
    selectedIndex = (selectedIndex == 2) ? 0 : selectedIndex + 1;
    isDirty = true;
  }
  // Y Butonuna Basıldığında Ana Menüye Dön
  else if (InputManager::buttonY.pressed()) {
    AppManager::setApp(AppStack::getSysApp(0));
  }
  // Ayarı Değiştir
  else if (InputManager::buttonA.pressed()) {
    // Wifi'nin Durumunu Değiştir
    if (selectedIndex == 0) {
      Network::toggleWifi();
    }
    // Ap'nin Durumunu Değiştir
    else if (selectedIndex == 1) {
      Network::toggleAP();
    }
    // Server'in Durumunu Değiştir
    else if (selectedIndex == 2) {
      DeviceServer::toggle();
    }
    isDirty = true;
  }
}

void NetManager::render() {
  // Color
  uint32_t okColor = COLOR(0, 200, 120);
  uint32_t errorColor = COLOR(240, 80, 90);

  // Wi-Fi Bilgilerini Al
  String wifiSSID = Network::wifiSSID();
  bool wifiConnected = Network::isWifiConnected();
  uint32_t wifiStatusColor = wifiConnected ? okColor : errorColor;
  const char *wifiStatusText = wifiConnected ? "Connected" : "Disconnected";
  bool wifiSelected = selectedIndex == 0;
  // Ap Bilgilerini Al
  String apSSID = Network::apSSID();
  bool apStarted = Network::isAPStarted();
  uint32_t apStatusColor = apStarted ? okColor : errorColor;
  const char *apStatusText = apStarted ? "On" : "Off";
  bool apSelected = selectedIndex == 1;
  // Server Bilgilerini Al
  String serverIP = Network::serverIP();
  bool serverRunning = DeviceServer::isRunning();
  uint32_t serverStatusColor = serverRunning ? okColor : errorColor;
  const char *serverStatusText = serverRunning ? "On" : "Off";
  bool serverSelected = selectedIndex == 2;

  // Metinlerin Hizalaması: Sol Üst Köşe
  Renderer::setTextDatum(TL_DATUM);

  // Arkaplan
  Renderer::setFillColor(COLOR(28, 28, 32));
  Renderer::fillRect({0, 0}, {320, 240});

  // Header Arkaplan
  Renderer::setFillColor(COLOR(55, 55, 65));
  Renderer::fillRect({0, 0}, {320, 28});

  // Header Title
  Renderer::setTextSize(2);
  Renderer::setTextColor(COLOR(255, 255, 255));
  Renderer::drawText("Network Settings", {8, 7});

  // Wifi Kutusu
  drawNetworkBox(0, "Wi-Fi", "SSID:", wifiSSID, "Durum:", wifiStatusText, wifiStatusColor, wifiSelected);

  // AP Kutusu
  drawNetworkBox(1, "Access Point", "SSID:", apSSID, "Durum:", apStatusText, apStatusColor, apSelected);

  // Server Kutusu
  drawNetworkBox(2, "Server", "IP:", serverIP, "Durum:", serverStatusText, serverStatusColor, serverSelected);
}

void NetManager::drawNetworkBox(uint8_t index, String title, String line1Name, String line1Value, String line2Name, String line2Value, uint32_t statusColor, bool selected) {
  // Kutunun Boyutu
  uint32_t w = 304;
  uint32_t h = 60;

  // Kutunun Pozisyonu
  int x = 8;
  int y = 35 + 69 * index;

  // Çerçeve
  Renderer::setFillColor(selected ? COLOR(40, 140, 255) : COLOR(70, 70, 80));
  Renderer::fillRect({x - 2, y - 2}, {w + 4, h + 4});

  // Arkaplan
  Renderer::setFillColor(COLOR(38, 38, 44));
  Renderer::fillRect({x, y}, {w, h});

  // Durum Göstergesi
  Renderer::setFillColor(statusColor);
  Renderer::fillCircle({x + 280, y + 30}, 8);

  // Yazı Stilini Ayarla
  Renderer::setTextSize(1);

  // Başlığı Yaz
  Renderer::setTextColor(COLOR(255, 255, 255));
  Renderer::drawText(title, {x + 10, y + 8});

  // 1. Satırın Başlığı
  Renderer::setTextColor(COLOR(150, 150, 150));
  Renderer::drawText(line1Name, {x + 10, y + 28});

  // 1. Satırın Değeri
  Renderer::setTextColor(COLOR(240, 240, 240));
  Renderer::drawText(line1Value, {x + 70, y + 28});

  // 2. Satırın Başlığı
  Renderer::setTextColor(COLOR(150, 150, 150));
  Renderer::drawText(line2Name, {x + 10, y + 44});

  // 2. Satırın Değeri
  Renderer::setTextColor(statusColor);
  Renderer::drawText(line2Value, {x + 70, y + 44});
}