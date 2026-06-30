// ============================================================================
// File:    APIResponse.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#pragma once

// INCLUDES
#include <HTTPClient.h>

// STRUCTURES
typedef struct {
  int32_t statusCode = -1;

  int32_t contentLength = 0;
  String contentType;

  String body;

  String error;

  WiFiClient *stream = nullptr;

  bool isError() const {
    return statusCode <= 0;
  }

  bool isStream() const {
    return stream != nullptr;
  }
} APIResponse;
