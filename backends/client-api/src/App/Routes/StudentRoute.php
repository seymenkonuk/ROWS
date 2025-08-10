<?php
// ============================================================================
// File:    StudentRoute.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Router.php");

class StudentRoute
{
    public static function register()
    {
        Router::addRoute(
            method: Router::GET_METHOD,
            url: "api/v1/students/me",
            controller: "Student",
            action: "GetMe"
        );
        Router::addRoute(
            method: Router::PUT_METHOD,
            url: "api/v1/students/me",
            controller: "Student",
            action: "ChangeMe"
        );
        Router::addRoute(
            method: Router::DELETE_METHOD,
            url: "api/v1/students/me",
            controller: "Student",
            action: "DeleteMe"
        );
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/students/change-password",
            controller: "Student",
            action: "ChangeMyPassword"
        );
        Router::addRoute(
            method: Router::GET_METHOD,
            url: "api/v1/students/classes",
            controller: "Student",
            action: "GetMyClasses"
        );
        // 
        Router::addRoute(
            method: Router::GET_METHOD,
            url: "api/v1/students/{student_code}/me",
            controller: "Student",
            action: "GetStudent"
        );
        Router::addRoute(
            method: Router::PUT_METHOD,
            url: "api/v1/students/{student_code}/me",
            controller: "Student",
            action: "ChangeStudent"
        );
        Router::addRoute(
            method: Router::DELETE_METHOD,
            url: "api/v1/students/{student_code}/me",
            controller: "Student",
            action: "DeleteStudent"
        );
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/students/{student_code}/change-password",
            controller: "Student",
            action: "ChangePassword"
        );
        Router::addRoute(
            method: Router::GET_METHOD,
            url: "api/v1/students/{student_code}/classes",
            controller: "Student",
            action: "GetClasses"
        );
    }
}
