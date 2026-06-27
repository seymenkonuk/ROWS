// ============================================================================
// File:    MQTTClient.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include <PubSubClient.h>

// CLASSES
class MQTTClient {
  typedef void (*MQTTHandler)(char *topic, uint8_t *payload, unsigned int length);

public:
  static void setServer(const char *domain, uint16_t port);
  static void setServer(const String &domain, uint16_t port);

  static void setCallback(MQTTHandler handler);

  static bool connect(const char *id);
  static bool connect(const String &id);
  static void disconnect();

  static bool subscribe(const char *topic);
  static bool subscribe(const char *topic, uint8_t qos);
  static bool subscribe(const String &topic);
  static bool subscribe(const String &topic, uint8_t qos);

  static bool publish(const char *topic, const char *message);
  static bool publish(const char *topic, const String &message);
  static bool publish(const String &topic, const char *message);
  static bool publish(const String &topic, const String &message);

private:
  static PubSubClient client;
};
