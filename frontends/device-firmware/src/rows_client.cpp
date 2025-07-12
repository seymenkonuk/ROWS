// ============================================================================
// File:    rows_client.cpp
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#include "rows_client.h"

WiFiClientSecure wifiClient;

static String caCert, clientCert, clientKey;

bool setupClient() {
  // Sertifikaları Oku
  caCert = readFile("/certificates/ca.crt");
  clientCert = readFile("/certificates/client.crt");
  clientKey = readFile("/certificates/client.key");
  // Yapılandır
  wifiClient.setCACert(caCert.c_str());
  wifiClient.setCertificate(clientCert.c_str());
  wifiClient.setPrivateKey(clientKey.c_str());
  return true;
}

String getHTTP(String serverName) {
  String result = "";
  HTTPClient https;

  https.begin(wifiClient, serverName);
  int httpCode = https.GET();

  if (httpCode > 0) {
    result = https.getString();
  }

  https.end();
  return result;
}

String postHTTP(String serverName, String contentType, String postData) {
  String result = "";
  HTTPClient https;

  https.begin(wifiClient, serverName);
  https.addHeader("Content-Type", contentType);
  int httpCode = https.POST(postData);

  if (httpCode > 0) {
    result = https.getString();
  }

  https.end();
  return result;
}
