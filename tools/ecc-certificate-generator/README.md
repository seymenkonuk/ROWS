# Device Certificate Generator

Bu araç, her bir cihaz için **benzersiz bir Seri Numarası, Parola ve ECC Kriptografik Sertifika** üreterek cihazların kimliklendirme sürecini otomatize eder. 

Ayrıca sistemin güvenli haberleşmesi (**mTLS - Karşılıklı TLS doğrulaması**) için gereken Root CA ve Sunucu (Server) sertifikalarını da üreterek tüm katmanlara (`firmware`, `backends`, `frontends`) otomatik olarak dağıtır.

## 🚀 Özellikler
* **Benzersiz Cihaz Kimliği:** Her çalıştırmada cihaza özel benzersiz bir Seri Numarası ve Parola üretir.
* **mTLS Altyapısı:** Cihazların ve sunucunun birbirini güvenli bir şekilde doğrulaması için gereken sertifika zincirini kurar.
* **Otomatik Dağıtım:** Üretilen kimlik bilgilerini ve sertifikaları ilgili dizinlere yerleştirir:
  * 📟 `firmware/data/` (PlatformIO LittleFS dosya sistemine)
  * 🌐 `backends/` (mTLS doğrulaması yapacak sunucu dizinlerine)
  * 💻 `frontends/` (Gerekli istemci dizinlerine)

## 🛠️ Ön Gereksinimler
Scriptin çalışabilmesi için sisteminizde **OpenSSL** ile **python3** yüklü olmalı ve terminalin scripti çalıştırabilme yetkisi olmalıdır. Yetki vermek için:

```bash
chmod +x generate.sh create_password.sh create_serial_number.sh
```

> 💡 **Not:** Eğer **Windows** kullanıyorsanız, `.sh` betiklerini sorunsuz çalıştırabilmek için **WSL** (Windows Subsystem for Linux) veya **Git Bash** kullanabilirsiniz.

## ⚙️ Yapılandırma
Aracı ilk kez çalıştırmadan önce:
1. `config/server.cnf` dosyasını bir metin editörüyle açın.
2. İlgili alanları (CN, DNS.1, IP.1 bölümlerini) sunucunuzun barındırılacağı **kendi alan adınıza (domain)** göre güncelleyin ve kaydedici kapatın.

## 💻 Kullanım

### 1. Standart Kullanım (Yeni Cihaz Kimliği ve Sertifikası Üretme)
Mevcut Root CA altyapısını koruyarak, sisteme yeni bir cihaz tanımlamak, ona özel Seri No/Parola ve sertifika üretip dağıtmak için:

```bash
./generate.sh
```

### 2. Tam Sıfırlama (Reset & Regenerate)
Root CA, Sunucu (Server) sertifikaları ve config/server.cnf değişikliklerini sıfırdan ele alıp tüm güvenlik altyapısını baştan inşa etmek için:


```bash
./generate.sh reset
```

> ⚠️ **DİKKAT:** reset komutu Kök Sertifikayı (Root CA) sileceğinden, daha önce bu kök sertifika ile imzalanmış eski cihazların sunucu ile olan güvenli bağlantısı kopacaktır.
