<?php
// ============================================================================
// File:    DeviceController.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Controller.php");

require_once(HELPER . "readBody.php");

class DeviceController extends Controller
{
	// GET
	public static function GetActiveStudentCode()
	{
		// test
		if (isset($_SERVER['SSL_CLIENT_S_DN_CN'])) {
			$clientCN = $_SERVER['SSL_CLIENT_S_DN_CN'];
			return $clientCN;
		}
		return "00000000000000000000000000000000";
	}

	// GET
	public static function GetMyClasses()
	{
		// test
		if (isset($_SERVER['SSL_CLIENT_S_DN_CN'])) {
			$clientCN = $_SERVER['SSL_CLIENT_S_DN_CN'];
			return $clientCN . ",111111111111111111";
		}
		return "12345678901234567890123456789011,12345678901234567890123456789022";
	}

	// POST
	public static function FinishTask()
	{
		return "";
	}
}
