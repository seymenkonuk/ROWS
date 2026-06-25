# -------------------------
# 1. COMPOSER STAGE
# -------------------------
FROM composer:2 AS vendor

WORKDIR /app

# sadece dependency dosyaları (cache için)
COPY composer.json composer.lock ./

# production dependency install
RUN composer install \
    --no-dev \
    --no-interaction \
    --prefer-dist \
    --optimize-autoloader

# -------------------------
# 2. PHP RUNTIME STAGE
# -------------------------
FROM php:8.3-fpm-alpine

WORKDIR /var/www/ota

# sistem paketleri
RUN apk add --no-cache \
    bash \
    icu-dev \
    oniguruma-dev \
    libzip-dev \
    zip \
    unzip \
    $PHPIZE_DEPS

# php extension'lar
RUN docker-php-ext-install \
    pdo \
    pdo_mysql \
    intl \
    zip \
    opcache

# vendor klasörünü composer stage'den al
COPY --from=vendor /app/vendor ./vendor

# Ayar Dosyasını Al
COPY uploads.ini /usr/local/etc/php/conf.d/uploads.ini

# izinler
RUN chown -R www-data:www-data /var/www/ota

ENTRYPOINT ["php-fpm"]
