// ============================================================================
// File:    APIClient.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include "network/APIResponse.h"

// CLASSES
class APIClient {
  typedef bool (*StreamHandler)(const APIResponse &res);

public:
  static void init(uint32_t timeoutMs = 10000);

  static APIResponse get(const String &url);
  static APIResponse post(const String &url, const String &contentType, const String &body);

  static bool getStream(const String &url, StreamHandler handler);
  static bool postStream(const String &url, const String &contentType, const String &body, StreamHandler handler);

private:
  static uint32_t _timeout;
};
