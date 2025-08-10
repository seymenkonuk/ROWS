<?php
// ============================================================================
// File:    RouteConfig.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Router.php");

require_once(ROUTE . "AuthRoute.php");
require_once(ROUTE . "ClassRoute.php");
require_once(ROUTE . "DeviceRoute.php");
require_once(ROUTE . "ParentRoute.php");
require_once(ROUTE . "StudentRoute.php");
require_once(ROUTE . "TasklistRoute.php");
require_once(ROUTE . "TaskRoute.php");
require_once(ROUTE . "TeacherRoute.php");

require_once(MIDDLEWARE . "RequestValidationMiddleware.php");

class RouteConfig
{
    public static function register()
    {
        // Ortak Middleware'ler
        Router::addMiddleware(new RequestValidationMiddleware());

        // Route'lar
        AuthRoute::register();
        ClassRoute::register();
        DeviceRoute::register();
        ParentRoute::register();
        StudentRoute::register();
        TasklistRoute::register();
        TaskRoute::register();
        TeacherRoute::register();
    }
}
