<?php
// ============================================================================
// File:    AuthRoute.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Router.php");

class AuthRoute
{
    public static function register()
    {
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/auth/register/parent",
            controller: "Auth",
            action: "RegisterParent"
        );
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/auth/register/teacher",
            controller: "Auth",
            action: "RegisterTeacher"
        );
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/auth/login",
            controller: "Auth",
            action: "Login"
        );
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/auth/logout",
            controller: "Auth",
            action: "Logout"
        );
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/auth/token",
            controller: "Auth",
            action: "CheckToken"
        );
    }
}
