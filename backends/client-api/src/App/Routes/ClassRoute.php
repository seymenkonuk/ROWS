<?php
// ============================================================================
// File:    ClassRoute.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Router.php");

class ClassRoute
{
    public static function register()
    {
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/classes",
            controller: "Class",
            action: "Create"
        );
        Router::addRoute(
            method: Router::GET_METHOD,
            url: "api/v1/classes/{class_code}",
            controller: "Class",
            action: "Index"
        );
        Router::addRoute(
            method: Router::PUT_METHOD,
            url: "api/v1/classes/{class_code}",
            controller: "Class",
            action: "Change"
        );
        Router::addRoute(
            method: Router::DELETE_METHOD,
            url: "api/v1/classes/{class_code}",
            controller: "Class",
            action: "Delete"
        );
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/classes/{class_code}/join",
            controller: "Class",
            action: "Join"
        );
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/classes/{class_code}/leave",
            controller: "Class",
            action: "Leave"
        );
        Router::addRoute(
            method: Router::GET_METHOD,
            url: "api/v1/classes/{class_code}/students",
            controller: "Class",
            action: "GetStudents"
        );
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/classes/{class_code}/students",
            controller: "Class",
            action: "AddStudent"
        );
        Router::addRoute(
            method: Router::DELETE_METHOD,
            url: "api/v1/classes/{class_code}/students/{student_code}",
            controller: "Class",
            action: "RemoveStudent"
        );
        Router::addRoute(
            method: Router::GET_METHOD,
            url: "api/v1/classes/{class_code}/leaderboard",
            controller: "Class",
            action: "GetLeaderboard"
        );
        Router::addRoute(
            method: Router::GET_METHOD,
            url: "api/v1/classes/{class_code}/tasklists",
            controller: "Class",
            action: "GetTasklists"
        );
    }
}
