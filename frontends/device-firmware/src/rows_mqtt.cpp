// ============================================================================
// File:    rows_mqtt.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "rows_mqtt.h"

PubSubClient mqttClient(wifiClient);

char *latestTopic = NULL;

static bool hasSetupCompleted = false;

static String id;
static String cn;
static String activeStudentCode;

static char changedStudent[MAX_TOPIC_LENGTH];
static char studentPlayTask[MAX_TOPIC_LENGTH];
static char classPlayTask[MAX_CLASS_COUNT][MAX_TOPIC_LENGTH];
static int classCount = 0;

static void handleMQTTMessage(char *topic, byte *payload, unsigned int length) {
  String message = "";
  // Mesajı Hesapla
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  latestTopic = topic;
  // Öğrenci Değişti Verisi Geldiyse Restart
  if (topic[0] == 'd') {
    delay(1000);
    ESP.restart();
    return;
  }
  // Diğer Tüm Durumlar Görev Oyna Verisidir
  // Görevin Geçerliliğini Kontrol Et ve Oyunu Başlat
  if (setGameWithNotation(message)) {
    changeMenu(GAME_MENU);
  }
}

static bool getClassCodes() {
  HTTPClient https;
  https.begin(wifiClient, API_GET_MY_CLASSES_URL);
  int httpCode = https.GET();
  char buffer[CODE_LENGTH + 1];
  classCount = 0;

  if (httpCode > 0) {
    WiFiClient *stream = https.getStreamPtr();
    while (https.connected() || stream->available()) {
      if (stream->available() >= CODE_LENGTH) {
        size_t bytesRead = stream->readBytes(buffer, CODE_LENGTH);
        buffer[bytesRead] = '\0';
        snprintf(classPlayTask[classCount], sizeof(classPlayTask[classCount]), "class/%s/playTask", buffer);
        classCount++;
        if (classCount >= MAX_CLASS_COUNT) {
          break;
        }
        stream->read();
      }
    }
  }

  https.end();
  return true;
}

static bool setupMQTT() {
  hasSetupCompleted = true;
  // Bilgileri Ayarla
  id = String(generateRandom(0, 0x7FFFFFFF), HEX) + String(generateRandom(0, 0x7FFFFFFF), HEX);
  cn = readFile("/certificates/CN");
  activeStudentCode = getHTTP(API_GET_ACTIVE_STUDENT_CODE_URL);
  snprintf(changedStudent, sizeof(changedStudent), "device/%s/changedStudent", cn.c_str());
  snprintf(studentPlayTask, sizeof(studentPlayTask), "student/%s/playTask", activeStudentCode.c_str());
  getClassCodes();
  return true;
}

bool connectMQTT() {
  // Yapılandır
  if (!hasSetupCompleted) {
    setupMQTT();
  }
  // MQTT Ayarları
  mqttClient.setServer(SERVER_DOMAIN, 8884);
  mqttClient.setCallback(handleMQTTMessage);
  // Bağlantıyı Kur
  if (!mqttClient.connect(id.c_str())) {
    return false;
  }
  // Cihazın Kendi Topic'lerine Abone Ol
  if (!mqttClient.subscribe(changedStudent)) {
    return false;
  }
  // Aktif Öğrencinin Topiclerine Abone Ol
  if (!mqttClient.subscribe(studentPlayTask)) {
    return false;
  }
  // Kayıtlı Sınıfların Topiclerine Abone Ol
  for (int i = 0; i < classCount; i++) {
    if (!mqttClient.subscribe(classPlayTask[i])) {
      return false;
    }
  }
  return true;
}

bool publishFinishTask(String message) {
  if (latestTopic) {
    return mqttClient.publish(latestTopic, message.c_str());
  }
  return true;
}
