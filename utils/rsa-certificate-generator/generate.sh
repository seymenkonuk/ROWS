#!/bin/bash

# Scriptin bulunduğu dizini al
SCRIPT_DIR=$(dirname "$0")

# Scriptin bulunduğu dizine geç
cd $SCRIPT_DIR

# İstemci Sertifikasına Benzersiz CN Ver
CLIENT_NAME=$(./create_serial_number.sh)
CLIENT_PASS=$(./create_password.sh)
sed -i "s/^CN = .*/CN = $CLIENT_NAME/" cnf/client.cnf

# config/certs dizinindeyim
cd ../../config/certs

# RESET SERTİFİKA: ROOT ve Server Sertifikasını Üret
if [ "$1" = "reset" ]; then
  sudo rm * 2>/dev/null

  # 1. CA Root Sertifikası - Kök Sertifika
  echo "Creating Root CA..."
  openssl genpkey -algorithm RSA -out ca.key
  openssl req -new -x509 -days 3650 -key ca.key -config ../../utils/certificate-generator/cnf/root.cnf -out ca.crt

  # 2. Server Sertifikası
  echo "Creating Server Certificate..."
  openssl genpkey -algorithm RSA -out server.key
  openssl req -new -key server.key -config ../../utils/certificate-generator/cnf/server.cnf -out server.csr
  openssl x509 -req -in server.csr -CA ca.crt -CAkey ca.key -CAcreateserial -extfile ../../utils/certificate-generator/cnf/server.cnf -extensions v3_req -out server.crt -days 3650
  rm server.csr
fi

# 3. Client Sertifikası
echo "Creating Client Certificate..."
openssl genpkey -algorithm RSA -out $CLIENT_NAME.key
openssl req -new -key $CLIENT_NAME.key -config ../../utils/certificate-generator/cnf/client.cnf -out client.csr
openssl x509 -req -in client.csr -CA ca.crt -CAkey ca.key -CAcreateserial -extfile ../../utils/certificate-generator/cnf/client.cnf -extensions v3_client -out $CLIENT_NAME.crt -days 3650
rm client.csr

# 4. Sertifikaları Firmware'in Dosya Sistemine Kopyala
rm ../../frontends/device-firmware/data/certificates/* 2>/dev/null
cp $CLIENT_NAME.crt ../../frontends/device-firmware/data/certificates/client.crt
cp $CLIENT_NAME.key ../../frontends/device-firmware/data/certificates/client.key
cat server.crt > ../../frontends/device-firmware/data/certificates/ca.crt
cat ca.crt >> ../../frontends/device-firmware/data/certificates/ca.crt
echo -n $CLIENT_NAME > ../../frontends/device-firmware/data/certificates/CN
echo -n $CLIENT_PASS > ../../frontends/device-firmware/data/certificates/PASS
echo -n "ROWS-$CLIENT_NAME" > ../../frontends/device-firmware/data/wifi/ap/SSID
echo -n $CLIENT_PASS > ../../frontends/device-firmware/data/wifi/ap/PASS

# 5. Bitti
echo "Certificates created successfully."
