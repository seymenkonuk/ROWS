// ============================================================================
// File:    rows_mqtt.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#ifndef ROWS_MQTT_H
#define ROWS_MQTT_H

// INCLUDES
#include "rows_api.h"
#include "rows_client.h"
#include "rows_filesystem.h"
#include "rows_game.h"
#include "rows_menu.h"
#include "rows_random.h"
#include <PubSubClient.h>

// Extern
extern PubSubClient mqttClient;
extern char *latestTopic;

// DEFINES
#define MAX_TOPIC_LENGTH 100
#define MAX_CLASS_COUNT 100
#define CODE_LENGTH 32

// FUNCTIONS
bool connectMQTT();
bool publishFinishTask(String message);

#endif // ROWS_MQTT_H
