# PHP'nin Apache sürümünü temel alıyoruz
FROM php:8.2-apache

# PDO ve MySQL modüllerini yükleyelim
RUN docker-php-ext-install pdo pdo_mysql

# Apache'yi yeniden başlatmak için gerekli ayar
RUN a2enmod rewrite
