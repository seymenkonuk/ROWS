// ============================================================================
// File:    MQTTClient.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "network/MQTTClient.h"

#include "network/Certificate.h"

PubSubClient MQTTClient::client(Certificate::wifiClient);

void MQTTClient::setServer(const char *domain, uint16_t port) {
  client.setServer(domain, port);
}

void MQTTClient::setServer(const String &domain, uint16_t port) {
  setServer(domain.c_str(), port);
}

void MQTTClient::setCallback(MQTTHandler handler) {
  client.setCallback(handler);
}

bool MQTTClient::connect(const char *id) {
  return client.connect(id);
}

bool MQTTClient::connect(const String &id) {
  return connect(id.c_str());
}

void MQTTClient::disconnect() {
  client.disconnect();
}

bool MQTTClient::subscribe(const char *topic) {
  return client.subscribe(topic);
}

bool MQTTClient::subscribe(const char *topic, uint8_t qos) {
  return client.subscribe(topic, qos);
}

bool MQTTClient::subscribe(const String &topic) {
  return subscribe(topic.c_str());
}

bool MQTTClient::subscribe(const String &topic, uint8_t qos) {
  return subscribe(topic.c_str(), qos);
}

bool MQTTClient::publish(const char *topic, const char *message) {
  return client.publish(topic, message);
}

bool MQTTClient::publish(const char *topic, const String &message) {
  return publish(topic, message.c_str());
}

bool MQTTClient::publish(const String &topic, const char *message) {
  return publish(topic.c_str(), message);
}

bool MQTTClient::publish(const String &topic, const String &message) {
  return publish(topic.c_str(), message.c_str());
}
