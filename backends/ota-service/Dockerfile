FROM php:8.2-apache

# PDO ve MySQL modüllerini yükleyelim
RUN docker-php-ext-install pdo pdo_mysql

# SSL modülünü ve gerekli sertifikaları ekle
RUN a2enmod ssl && a2enmod rewrite

COPY apache/default-ssl.conf /etc/apache2/sites-available/default-ssl.conf

# SSL site'ını aktif et
RUN a2ensite default-ssl.conf

# PHP için önerilen ayarlar
RUN echo "ServerName localhost" >> /etc/apache2/apache2.conf

EXPOSE 443
