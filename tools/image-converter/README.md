# Image Converter

Bu araç, PiskelApp gibi platformlardan **C Array (dizi)** formatında export edilen görsel verilerini, cihazın dosya sisteminde (LittleFS) hızlıca okunabilecek özel **`.rif` (ROWS Image Format)** dosyalarına paketler.

## 🛠️ Ön Gereksinimler
Aracın derlenebilmesi ve çalışabilmesi için sisteminizde bir C derleyicisi `gcc` ve `make` aracının kurulu olması gerekir.

## 🎨 Görseli C Array Formatına Getirme (PiskelApp)
Programın işleyebileceği kaynak `image.c` dosyasını oluşturmak için:
1. [piskelapp.com](https://www.piskelapp.com) adresine gidin ve görselinizi yükleyin/çizin.
2. **Export -> Others -> Download C file** adımlarını izleyerek dosyanızı C array formatında dışarı aktarınız.
3. İndirdiğiniz `.c` dosyasını araca vermeden önce formatını düzenlemeniz gerekir.
4. Programın çalışması için gereken değişken isimleri, dizi boyutları ve format kuralları **`images/` klasörü altındaki örnek dosyada** açıkça gösterilmiştir. Yeni bir görsel eklemeden önce mutlaka o dosyayı referans alınız.

> ⚠️ **Önemli Kurallar:**
> * Genişlik ve yükseklik değerleri `#define` yerine `imageWidth` ve `imageHeight` değişkenleri olarak tanımlanmalıdır.
> * Piksel dizisinin adı kesinlikle `imageData` olmalı ve çift boyutlu `[1][X]` yerine tek boyutlu `[X]` formatına getirilmelidir.

## 💻 Kullanım

Düzenlediğiniz `.c` dosyasını `images/` klasörüne (veya istediğiniz bir konuma) koyduktan sonra `make` komutu ile `.rif` çıktısını üretebilirsiniz:

```bash
# Görseli paketlemek ve çalıştırmak için:
make IMAGE="images/image.c" OUTPUT="image.rif" run

# Oluşan tüm dosyalarını temizlemek için:
make clean
```
