<?php
// ============================================================================
// File:    AuthController.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Controller.php");
require_once(CORE . "Request.php");

class AuthController extends Controller
{

	// POST
	public function RegisterParent()
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"code" => "",
			"device_code" => "",
			"username" => "",
			"name" => "",
			"surname" => "",
			"created_at" => ""
		]);
	}

	// POST
	public function RegisterTeacher()
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"code" => "",
			"username" => "",
			"name" => "",
			"surname" => "",
			"created_at" => ""
		]);
	}

	// POST
	public function Login()
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"token" => "",
			"type" => "ogrenci|ogretmen|veli",
			"code" => "",
		]);
	}

	// POST
	public function Logout()
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", null);
	}

	// POST
	public function CheckToken()
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"token" => "",
			"type" => "ogrenci|ogretmen|veli",
			"code" => "",
		]);
	}
}
