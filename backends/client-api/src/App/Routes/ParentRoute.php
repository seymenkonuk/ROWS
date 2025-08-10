<?php
// ============================================================================
// File:    ParentRoute.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Router.php");

class ParentRoute
{
    public static function register()
    {
        Router::addRoute(
            method: Router::GET_METHOD,
            url: "api/v1/parents/me",
            controller: "Parent",
            action: "GetMe"
        );
        Router::addRoute(
            method: Router::PUT_METHOD,
            url: "api/v1/parents/me",
            controller: "Parent",
            action: "ChangeMe"
        );
        Router::addRoute(
            method: Router::DELETE_METHOD,
            url: "api/v1/parents/me",
            controller: "Parent",
            action: "DeleteMe"
        );
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/parents/change-password",
            controller: "Parent",
            action: "ChangeMyPassword"
        );
        Router::addRoute(
            method: Router::GET_METHOD,
            url: "api/v1/parents/students",
            controller: "Parent",
            action: "GetMyStudents"
        );
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/parents/students",
            controller: "Parent",
            action: "AddMyStudents"
        );
        // 
        Router::addRoute(
            method: Router::GET_METHOD,
            url: "api/v1/parents/{parent_code}/me",
            controller: "Parent",
            action: "GetParent"
        );
        Router::addRoute(
            method: Router::PUT_METHOD,
            url: "api/v1/parents/{parent_code}/me",
            controller: "Parent",
            action: "ChangeParent"
        );
        Router::addRoute(
            method: Router::DELETE_METHOD,
            url: "api/v1/parents/{parent_code}/me",
            controller: "Parent",
            action: "DeleteParent"
        );
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/parents/{parent_code}/change-password",
            controller: "Parent",
            action: "ChangePassword"
        );
        Router::addRoute(
            method: Router::GET_METHOD,
            url: "api/v1/parents/{parent_code}/students",
            controller: "Parent",
            action: "GetStudents"
        );
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/parents/{parent_code}/students",
            controller: "Parent",
            action: "AddStudents"
        );
    }
}
