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
            method: Router::GET_METHOD,
            url: "api/v1/device/getActiveStudentCode",
            controller: "Device",
            action: "GetActiveStudentCode"
        );
        Router::addRoute(
            method: Router::GET_METHOD,
            url: "api/v1/device/getMyClasses",
            controller: "Device",
            action: "GetMyClasses"
        );
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/device/finishTask",
            controller: "Device",
            action: "FinishTask"
        );
    }
}
