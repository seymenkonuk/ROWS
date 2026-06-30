# Melody Converter

Bu araç, C dizisi (array) formatında tanımlanmış melodileri, cihazın dosya sisteminde (LittleFS) hızlıca okunabilecek ve doğrudan yürütülebilecek özel **`.rmf` (ROWS Melody Format)** dosyalarına paketler.

## 🛠️ Ön Gereksinimler
Aracın derlenebilmesi ve çalışabilmesi için sisteminizde bir C derleyicisi `gcc` ve `make` aracının kurulu olması gerekir.

## 🎵 Melodi Dosyasını Hazırlama (song.c)
Programın melodiyi doğru işleyebilmesi için girdi olarak verilen `.c` dosyasının belirli bir formatta olması gerekir. 

Gerekli struct (yapı) tanımlamaları, nota isimleri ve süre sabitleri **`songs/` klasörü altındaki örnek dosyada** açıkça gösterilmiştir. Yeni bir melodi eklemeden önce mutlaka o dosyayı referans alınız.

## 💻 Kullanım

Düzenlediğiniz `.c` dosyasını `songs/` klasörüne (veya istediğiniz bir konuma) koyduktan sonra `make` komutu ile `.rmf` çıktısını üretebilirsiniz:

```bash
# Melodiyi paketlemek ve çalıştırmak için:
make SONG="songs/song.c" OUTPUT="song.rmf" run

# Oluşan tüm dosyaları temizlemek için:
make clean
```
