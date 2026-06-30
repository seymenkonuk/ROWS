#!/bin/bash

# Scriptin bulunduğu dizine geç
cd $(dirname "$0")

# İstemci için Benzersiz İsim Ve Parola Üret
CLIENT_NAME=$(./create_serial_number.sh)
CLIENT_PASS=$(./create_password.sh)

# CA.CRT Dosyasının Kopyalanacağı Dizinler
CA_CRT_TARGETS=(
  "../../../backends/docker/mosquitto/certs/ca.crt"
  "../../../backends/docker/nginx/certs/ca.crt"
)

# CA.KEY Dosyasının Kopyalanacağı Dizinler
CA_KEY_TARGETS=(
)

# SERVER.CRT Dosyasının Kopyalanacağı Dizinler
SERVER_CRT_TARGETS=(
  "../../../backends/docker/mosquitto/certs/server.crt"
  "../../../backends/docker/nginx/certs/server.crt"
)

# SERVER.KEY Dosyasının Kopyalanacağı Dizinler
SERVER_KEY_TARGETS=(
  "../../../backends/docker/mosquitto/certs/server.key"
  "../../../backends/docker/nginx/certs/server.key"
)

# CLIENT.CRT Dosyasının Kopyalanacağı Dizinler
CLIENT_CRT_TARGETS=(
  "../../../firmware/data/certificates/client.crt"
)

# CLIENT.KEY Dosyasının Kopyalanacağı Dizinler
CLIENT_KEY_TARGETS=(
  "../../../firmware/data/certificates/client.key"
)

# CLIENT_NAME Değerinin Yazılacağı Dosyalar
CLIENT_NAME_TARGETS=(
  "../../../firmware/data/certificates/CN"
)

# CLIENT_PASS Değerinin Yazılacağı Dosyalar
CLIENT_PASS_TARGETS=(
  "../../../firmware/data/certificates/PASS"
  "../../../firmware/data/network/ap/PASS"
)

# ROWS-$CLIENT_NAME Değerinin Yazılacağı Dosyalar
ROWS_CLIENT_NAME_TARGETS=(
  "../../../firmware/data/network/ap/SSID"
)

# Sertifika Zincirinin Yazılacağı Dosyalar
CERTIFICATE_CHAIN_TARGETS=(
  "../../../firmware/data/certificates/ca.crt"
)

# Sertifikalar Dizinine Git
cd certs

# İlk Kez Sertifika Üretilecekse veya Resetlenecekse
# Root ve Server Sertifikalarını Üret
if [ "$1" = "reset" ] || [ ! -f "ca.crt" ] || [ ! -f "ca.key" ] || [ ! -f "server.crt" ] || [ ! -f "server.key" ]; then
  # Dizindeki Her Şeyi Sil
  sudo rm * 2>/dev/null

  # 1. CA Root Sertifikası - Kök Sertifika Üret
  echo "Creating Root CA..."
  openssl ecparam -name prime256v1 -genkey -noout -out ca.key
  openssl req -new -x509 -days 3650 -key ca.key -config ../config/root.cnf -out ca.crt

  # 2. Server Sertifikası Üret
  echo "Creating Server Certificate..."
  openssl ecparam -name prime256v1 -genkey -noout -out server.key
  openssl req -new -key server.key -config ../config/server.cnf -out server.csr
  openssl x509 -req -in server.csr -CA ca.crt -CAkey ca.key -CAcreateserial -extfile ../config/server.cnf -extensions v3_req -out server.crt -days 3650
  rm server.csr
fi

# 3. Client Sertifikasının Config Dosyasını CLIENT_NAME'e Göre Düzenle
cp -f "../config/client.cnf" "../config/client.bak"
sed -i "s/<DO_NOT_MODIFY>/$CLIENT_NAME/g" "../config/client.cnf"

# 3. Client Sertifikasını Üret
echo "Creating Client Certificate..."
openssl ecparam -name prime256v1 -genkey -noout -out $CLIENT_NAME.key
openssl req -new -key $CLIENT_NAME.key -config ../config/client.cnf -out client.csr
openssl x509 -req -in client.csr -CA ca.crt -CAkey ca.key -CAcreateserial -extfile ../config/client.cnf -extensions v3_client -out $CLIENT_NAME.crt -days 3650
rm client.csr

# 5. Client Sertifikasının Config Dosyasını Eski Haline Getir
mv "../config/client.bak" "../config/client.cnf"

# 6. Üretilen Dosyaları Gerekli Her Yere Kopyala / Yaz
# CA.CRT Sertifikasını Gerekli Yerlere Kopyala
for target in "${CA_CRT_TARGETS[@]}"; do
  echo "Copying: ca.crt -> $target"
  cp -f "ca.crt" "$target"
done

# CA.KEY Sertifikasını Gerekli Yerlere Kopyala
for target in "${CA_KEY_TARGETS[@]}"; do
  echo "Copying: ca.key -> $target"
  cp -f "ca.key" "$target"
done

# SERVER.CRT Sertifikasını Gerekli Yerlere Kopyala
for target in "${SERVER_CRT_TARGETS[@]}"; do
  echo "Copying: server.crt -> $target"
  cp -f "server.crt" "$target"
done

# SERVER.KEY Sertifikasını Gerekli Yerlere Kopyala
for target in "${SERVER_KEY_TARGETS[@]}"; do
  echo "Copying: server.key -> $target"
  cp -f "server.key" "$target"
done

# CLIENT.CRT Sertifikasını Gerekli Yerlere Kopyala
for target in "${CLIENT_CRT_TARGETS[@]}"; do
  echo "Copying: $CLIENT_NAME.crt -> $target"
  cp -f "$CLIENT_NAME.crt" "$target"
done

# CLIENT.KEY Sertifikasını Gerekli Yerlere Kopyala
for target in "${CLIENT_KEY_TARGETS[@]}"; do
  echo "Copying: $CLIENT_NAME.key -> $target"
  cp -f "$CLIENT_NAME.key" "$target"
done

# ROWS-CLIENT_NAME Değerini Gerekli Dosyalara Yaz
for target in "${ROWS_CLIENT_NAME_TARGETS[@]}"; do
  echo "Yazılıyor: ROWS-$CLIENT_NAME -> $target"
  echo -n "ROWS-$CLIENT_NAME" > "$target"
done

# CLIENT_NAME Değerini Gerekli Dosyalara Yaz
for target in "${CLIENT_NAME_TARGETS[@]}"; do
  echo "Yazılıyor: $CLIENT_NAME -> $target"
  echo -n "$CLIENT_NAME" > "$target"
done

# CLIENT_PASS Değerini Gerekli Dosyalara Yaz
for target in "${CLIENT_PASS_TARGETS[@]}"; do
  echo "Yazılıyor: $CLIENT_PASS -> $target"
  echo -n "$CLIENT_PASS" > "$target"
done

# Sertifika Zincirini Gerekli Dosyalara Yaz
for target in "${CERTIFICATE_CHAIN_TARGETS[@]}"; do
  echo "Sertifika Zinciri Yazılıyor -> $target"
  cat server.crt > "$target"
  cat ca.crt >> "$target"
done

# 7. Bitti
echo "Certificates created successfully."
