<?php
// ============================================================================
// File:    DeviceController.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Controller.php");

class DeviceController extends Controller
{
    // GET
    public function GetActiveStudentCode()
    {
        // test
        if (isset($_SERVER['SSL_CLIENT_S_DN_CN'])) {
            $clientCN = $_SERVER['SSL_CLIENT_S_DN_CN'];
            return $this->Content($clientCN);
        }
        return $this->Content("00000000000000000000000000000000");
    }

    // GET
    public function GetMyClasses()
    {
        // test
        if (isset($_SERVER['SSL_CLIENT_S_DN_CN'])) {
            $clientCN = $_SERVER['SSL_CLIENT_S_DN_CN'];
            return $this->Content($clientCN . ",11111111111111111111111111111111");
        }
        return $this->Content("12345678901234567890123456789011,12345678901234567890123456789022");
    }

    // POST
    public function FinishTask()
    {
        return $this->Content("");
    }
}
