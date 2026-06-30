// ============================================================================
// File:    MQTTClient.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "network/MQTTClient.h"

#include "core/Logger.h"

#include "network/Certificate.h"

PubSubClient MQTTClient::client(Certificate::wifiClient);

void MQTTClient::setServer(const char *domain, uint16_t port) {
  LOG_INFO("MQTT configured: %s:%u", domain, port);
  client.setServer(domain, port);
}

void MQTTClient::setServer(const String &domain, uint16_t port) {
  setServer(domain.c_str(), port);
}

void MQTTClient::setCallback(MQTTHandler handler) {
  client.setCallback(handler);
}

bool MQTTClient::connect(const char *id) {
  LOG_INFO("Connecting to MQTT with ID: %s", id);
  if (!client.connect(id)) {
    LOG_ERROR("Connection failed.");
    return false;
  }
  LOG_INFO("Connected.");
  return true;
}

bool MQTTClient::connect(const String &id) {
  return connect(id.c_str());
}

void MQTTClient::disconnect() {
  LOG_INFO("MQTT disconnected.");
  client.disconnect();
}

bool MQTTClient::subscribe(const char *topic) {
  LOG_INFO("Subscribing to topic: %s", topic);
  if (!client.subscribe(topic)) {
    LOG_ERROR("Subscription failed.");
    return false;
  }
  LOG_INFO("Subscribed.");
  return true;
}

bool MQTTClient::subscribe(const char *topic, uint8_t qos) {
  LOG_INFO("Subscribing to topic: %s", topic);
  if (!client.subscribe(topic, qos)) {
    LOG_ERROR("Subscription failed.");
    return false;
  }
  LOG_INFO("Subscribed.");
  return true;
}

bool MQTTClient::subscribe(const String &topic) {
  return subscribe(topic.c_str());
}

bool MQTTClient::subscribe(const String &topic, uint8_t qos) {
  return subscribe(topic.c_str(), qos);
}

bool MQTTClient::publish(const char *topic, const char *message) {
  LOG_INFO("Publishing to topic: %s", topic);
  if (!client.publish(topic, message)) {
    LOG_ERROR("Publish failed.");
    return false;
  }
  LOG_INFO("Published.");
  return true;
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
