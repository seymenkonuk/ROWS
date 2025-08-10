<?php
// ============================================================================
// File:    TeacherRoute.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Router.php");

class TeacherRoute
{
    public static function register()
    {
        Router::addRoute(
            method: Router::GET_METHOD,
            url: "api/v1/teachers/me",
            controller: "Teacher",
            action: "GetMe"
        );
        Router::addRoute(
            method: Router::PUT_METHOD,
            url: "api/v1/teachers/me",
            controller: "Teacher",
            action: "ChangeMe"
        );
        Router::addRoute(
            method: Router::DELETE_METHOD,
            url: "api/v1/teachers/me",
            controller: "Teacher",
            action: "DeleteMe"
        );
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/teachers/change-password",
            controller: "Teacher",
            action: "ChangeMyPassword"
        );
        Router::addRoute(
            method: Router::GET_METHOD,
            url: "api/v1/teachers/classes",
            controller: "Teacher",
            action: "GetMyClasses"
        );
        // 
        Router::addRoute(
            method: Router::GET_METHOD,
            url: "api/v1/teachers/{teacher_code}/me",
            controller: "Teacher",
            action: "GetTeacher"
        );
        Router::addRoute(
            method: Router::PUT_METHOD,
            url: "api/v1/teachers/{teacher_code}/me",
            controller: "Teacher",
            action: "ChangeTeacher"
        );
        Router::addRoute(
            method: Router::DELETE_METHOD,
            url: "api/v1/teachers/{teacher_code}/me",
            controller: "Teacher",
            action: "DeleteTeacher"
        );
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/teachers/{teacher_code}/change-password",
            controller: "Teacher",
            action: "ChangePassword"
        );
        Router::addRoute(
            method: Router::GET_METHOD,
            url: "api/v1/teachers/{teacher_code}/classes",
            controller: "Teacher",
            action: "GetClasses"
        );
    }
}
