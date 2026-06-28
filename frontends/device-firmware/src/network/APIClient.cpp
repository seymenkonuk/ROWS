// ============================================================================
// File:    APIClient.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "network/APIClient.h"

#include "core/Logger.h"

#include "network/Certificate.h"

uint32_t APIClient::_timeout;

void APIClient::init(uint32_t timeoutMs) {
  LOG_INFO("Initializing API client...");
  _timeout = timeoutMs;
}

APIResponse APIClient::get(const String &url) {
  APIResponse response;
  HTTPClient https;

  // Timeout'u Ayarla
  https.setTimeout(_timeout);

  // HTTP Başlatılamadı
  if (!https.begin(Certificate::wifiClient, url)) {
    LOG_ERROR("HTTP begin failed: GET %s", url.c_str());
    response.error = "HTTP begin failed";
    return response;
  }

  // İsteği Gönder
  int httpCode = https.GET();
  response.statusCode = httpCode;
  LOG_INFO("HTTP request sent: GET %s", url.c_str());

  // Cevabı Al
  if (httpCode > 0) {
    response.contentLength = https.getSize();
    response.contentType = https.header("Content-Type");
    response.body = https.getString();
  } else {
    response.error = https.errorToString(httpCode);
  }

  // Bağlantıyı Sonlandır
  https.end();
  return response;
}

APIResponse APIClient::post(const String &url, const String &contentType, const String &body) {
  APIResponse response;
  HTTPClient https;

  // Timeout'u Ayarla
  https.setTimeout(_timeout);

  // HTTP Başlatılamadı
  if (!https.begin(Certificate::wifiClient, url)) {
    LOG_ERROR("HTTP begin failed: POST %s", url.c_str());
    response.error = "HTTP begin failed";
    return response;
  }

  // Header Ekle
  https.addHeader("Content-Type", contentType);

  // İsteği Gönder
  int httpCode = https.POST(body);
  response.statusCode = httpCode;
  LOG_INFO("HTTP request sent: POST %s", url.c_str());

  // Cevabı Al
  if (httpCode > 0) {
    response.contentLength = https.getSize();
    response.contentType = https.header("Content-Type");
    response.body = https.getString();
  } else {
    response.error = https.errorToString(httpCode);
  }

  // Bağlantıyı Sonlandır
  https.end();
  return response;
}

bool APIClient::getStream(const String &url, StreamHandler handler) {
  APIResponse response;
  HTTPClient https;
  bool result = false;

  // Parametre Hatası
  if (!handler) {
    LOG_ERROR("Parameter error: handler cannot be null");
    return false;
  }

  // Timeout'u Ayarla
  https.setTimeout(_timeout);

  // HTTP Başlatılamadı
  if (!https.begin(Certificate::wifiClient, url)) {
    LOG_ERROR("HTTP begin failed: GET %s", url.c_str());
    return false;
  }

  // İsteği Gönder
  int httpCode = https.GET();
  response.statusCode = httpCode;
  LOG_INFO("HTTP request sent: GET %s", url.c_str());

  // İstek Başarılı, Handler'ı Çağır
  if (httpCode > 0) {
    response.contentLength = https.getSize();
    response.contentType = https.header("Content-Type");
    response.stream = &https.getStream();
    result = handler(response);
  }

  // Bağlantıyı Sonlandır
  https.end();
  return result;
}

bool APIClient::postStream(const String &url, const String &contentType, const String &body, StreamHandler handler) {
  APIResponse response;
  HTTPClient https;
  bool result = false;

  // Parametre Hatası
  if (!handler) {
    LOG_ERROR("Parameter error: Handler cannot be null");
    return false;
  }

  // Timeout'u Ayarla
  https.setTimeout(_timeout);

  // HTTP Başlatılamadı
  if (!https.begin(Certificate::wifiClient, url)) {
    LOG_ERROR("HTTP begin failed: POST %s", url.c_str());
    return false;
  }

  // Header Ekle
  https.addHeader("Content-Type", contentType);

  // İsteği Yap
  int httpCode = https.POST(body);
  response.statusCode = httpCode;
  LOG_INFO("HTTP request sent: POST %s", url.c_str());

  // İstek Başarılı, Handler'ı Çağır
  if (httpCode > 0) {
    response.contentLength = https.getSize();
    response.contentType = https.header("Content-Type");
    response.stream = &https.getStream();
    result = handler(response);
  }

  // Bağlantıyı Sonlandır
  https.end();
  return result;
}
