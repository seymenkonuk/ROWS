<?php
// ============================================================================
// File:    TasklistRoute.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Router.php");

class TasklistRoute
{
    public static function register()
    {
        Router::addRoute(
            method: Router::POST_METHOD,
            url: "api/v1/tasklists",
            controller: "Tasklist",
            action: "Create"
        );
        Router::addRoute(
            method: Router::GET_METHOD,
            url: "api/v1/tasklists/{tasklist_code}",
            controller: "Tasklist",
            action: "Index"
        );
        Router::addRoute(
            method: Router::PUT_METHOD,
            url: "api/v1/tasklists/{tasklist_code}",
            controller: "Tasklist",
            action: "Change"
        );
        Router::addRoute(
            method: Router::DELETE_METHOD,
            url: "api/v1/tasklists/{tasklist_code}",
            controller: "Tasklist",
            action: "Delete"
        );
        Router::addRoute(
            method: Router::GET_METHOD,
            url: "api/v1/tasklists/{tasklist_code}/tasks",
            controller: "Tasklist",
            action: "Index"
        );
        Router::addRoute(
            method: Router::GET_METHOD,
            url: "api/v1/tasklists/{tasklist_code}/tasks/{task_code}/stats",
            controller: "Tasklist",
            action: "GetTaskStat"
        );
    }
}
