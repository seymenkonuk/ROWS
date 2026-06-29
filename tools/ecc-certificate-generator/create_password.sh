#!/bin/bash

# En az 1 küçük, 1 büyük, 1 özel karakter seç
lc=$(tr -dc 'a-z' </dev/urandom | head -c1)
uc=$(tr -dc 'A-Z' </dev/urandom | head -c1)
sc=$(tr -dc '!@#$%^&*()_\-+=' </dev/urandom | head -c1)

# Geri kalan 15 karakter, küçük, büyük, rakam ve yeni özel karakterler
rest=$(tr -dc 'a-zA-Z0-9!@#$%^&*()_\-+=' </dev/urandom | head -c15)

# Karakterleri birleştir
password="$lc$uc$sc$rest"

# Karakterleri karıştıran fonksiyon
shuffle() {
  echo "$1" | fold -w1 | shuf | tr -d '\n'
}

password=$(shuffle "$password")

echo "$password"
