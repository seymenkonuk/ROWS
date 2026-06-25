<?php
// ============================================================================
// File:    index.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

namespace Routes;


use App\Http\Controllers\AuthController;

use Seymenkonuk\Framework\Router;


class RouteConfig
{
    public function register(Router $router)
    {
        $router->registerController(AuthController::class);
    }
}
