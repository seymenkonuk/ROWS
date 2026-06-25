<?php
// ============================================================================
// File:    index.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(__DIR__ . DIRECTORY_SEPARATOR . ".." . DIRECTORY_SEPARATOR .  "vendor" . DIRECTORY_SEPARATOR . "autoload.php");


use Routes\RouteConfig;

use Seymenkonuk\Framework\Application;
use Seymenkonuk\Framework\Response;


Application::configure(dirname(__DIR__) . DIRECTORY_SEPARATOR . "app")
    ->withRouting(RouteConfig::class)
    ->withDbConfig(
        getenv("DB_HOST"),
        getenv("DB_PORT"),
        getenv("DB_DATABASE"),
        getenv("DB_CHARSET"),
        getenv("DB_USERNAME"),
        getenv("DB_PASSWORD"),
    )
    ->withException(function (Throwable $exception, Response $response) {
        return $response->badRequest();
    })
    ->run();
