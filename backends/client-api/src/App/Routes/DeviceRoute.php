<?php
// ============================================================================
// File:    DeviceRoute.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Router.php");

class DeviceRoute
{
    public static function register()
    {
        Router::addRoute(
            method: Router::GET_METHOD,
            url: "api/v1/devices/me",
            controller: "Device",
            action: "GetMe"
        );
        Router::addRoute(
            method: Router::PUT_METHOD,
            url: "api/v1/devices/me",
            controller: "Device",
            action: "ChangeMe"
        );
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/devices/change-password",
            controller: "Device",
            action: "ChangeMyPassword"
        );
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/devices/active-student",
            controller: "Device",
            action: "ChangeMyActiveStudent"
        );
        //
        Router::addRoute(
            method: Router::GET_METHOD,
            url: "api/v1/devices/{device_code}/me",
            controller: "Device",
            action: "GetDevice"
        );
        Router::addRoute(
            method: Router::PUT_METHOD,
            url: "api/v1/devices/{device_code}/me",
            controller: "Device",
            action: "ChangeDevice"
        );
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/devices/{device_code}/change-password",
            controller: "Device",
            action: "ChangePassword"
        );
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/devices/{device_code}/active-student",
            controller: "Device",
            action: "ChangeActiveStudent"
        );
    }
}
