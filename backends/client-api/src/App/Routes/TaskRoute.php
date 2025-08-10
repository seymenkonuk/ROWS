<?php
// ============================================================================
// File:    TaskRoute.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Router.php");

class TaskRoute
{
    public static function register()
    {
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/tasks",
            controller: "Task",
            action: "Create"
        );
        Router::addRoute(
            method: Router::GET_METHOD,
            url: "api/v1/tasks/{task_code}",
            controller: "Task",
            action: "Index"
        );
        Router::addRoute(
            method: Router::PUT_METHOD,
            url: "api/v1/tasks/{task_code}",
            controller: "Task",
            action: "Change"
        );
        Router::addRoute(
            method: Router::DELETE_METHOD,
            url: "api/v1/tasks/{task_code}",
            controller: "Task",
            action: "Delete"
        );
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/tasks/{task_code}/like",
            controller: "Task",
            action: "Like"
        );
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/tasks/favorite",
            controller: "Task",
            action: "GetFavoriteTasks"
        );
    }
}
