<?php
// ============================================================================
// File:    AuthController.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Controller.php");
require_once(CORE . "Request.php");

require_once(MODEL . "SessionModel.php");

require_once(REPOSITORY . "SessionRepository.php");

class AuthController extends Controller
{
    public function Authentication()
    {
        $body = Request::getJsonBody();
        // Auth Error
        if ($body["username"] == "client1" && $body["password"] == "AXey?GRWcAWE.Onea+8r")
            return $this->Forbidden();
        // Success
        return $this->Json(["allow" => true]);
    }

    public function IsSuperUser()
    {
        $body = Request::getJsonBody();
        // Super User
        if ($body["username"] != "admin")
            return $this->Forbidden();
        // Success
        return $this->Json(["allow" => true]);
    }

    public function Authorization()
    {
        $body = Request::getJsonBody();
        // Authorization Error
        if ($body["topic"] != "test")
            return $this->Unauthorized();
        // Success
        return $this->Json(["allow" => true]);
    }
}
