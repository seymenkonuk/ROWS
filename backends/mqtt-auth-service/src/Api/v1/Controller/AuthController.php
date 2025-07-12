<?php
// ============================================================================
// File:    AuthController.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Controller.php");
require_once(HELPER . "Validator.php");
require_once(HELPER . "readBody.php");
require_once(HELPER . "Database.php");

class AuthController extends Controller
{

	// POST
	public function Authentication()
	{
		$bodyData = getJSONBody();
		error_log("Gelen veri: " . json_encode($bodyData, JSON_PRETTY_PRINT | JSON_UNESCAPED_UNICODE));

		if ($bodyData["username"] == "client1" && $bodyData["password"] == "AXey?GRWcAWE.Onea+8r")
			return $this->JSON(["allow" => true]);
		return http_response_code(401);
	}

	// POST
	public function IsSuperUser()
	{
		// $bodyData = getBody();
		// error_log("Gelen veri: " . json_encode($bodyData, JSON_PRETTY_PRINT | JSON_UNESCAPED_UNICODE));

		// if ($bodyData["username"] == "super")
		// 	return $this->JSON(["allow" => true]);
		return http_response_code(403);
	}

	// POST
	public function Authorization()
	{
		$bodyData = getJSONBody();
		error_log("Gelen veri: " . json_encode($bodyData, JSON_PRETTY_PRINT | JSON_UNESCAPED_UNICODE));

		// if ($bodyData["topic"] == "client1/playTask")
		return $this->JSON(["allow" => true]);
		return http_response_code(403);
	}
}
