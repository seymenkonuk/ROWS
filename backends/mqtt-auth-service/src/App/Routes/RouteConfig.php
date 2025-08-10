<?php
// ============================================================================
// File:    RouteConfig.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Router.php");

require_once(MIDDLEWARE . "RequestValidationMiddleware.php");

class RouteConfig
{
    public static function register()
    {
        // Ortak Middleware'ler
        Router::addMiddleware(new RequestValidationMiddleware());

        // Route'lar
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/auth/user",
            controller: "Auth",
            action: "Authentication"
        );
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/auth/superuser",
            controller: "Auth",
            action: "IsSuperUser"
        );
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/auth/acl",
            controller: "Auth",
            action: "Authorization"
        );
    }
}
