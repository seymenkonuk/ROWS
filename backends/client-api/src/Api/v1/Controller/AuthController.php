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

require_once(TEMPLATES . "AuthTemplate.php");

class AuthController extends Controller
{

	// POST
	public function RegisterParent()
	{
		// Gelen Verilerin Doğrulaması
		$tempData = AuthTemplate::RegisterParent();
		$bodyData = getJSONBody();
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
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
		// Gelen Verilerin Doğrulaması
		$tempData = AuthTemplate::RegisterTeacher();
		$bodyData = getJSONBody();
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
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
		// Gelen Verilerin Doğrulaması
		$tempData = AuthTemplate::Login();
		$bodyData = getJSONBody();
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"token" => "",
			"type" => "ogrenci|ogretmen|veli",
			"code" => "",
		]);
	}

	// POST
	public function Logout()
	{
		// Gelen Verilerin Doğrulaması
		$tempData = AuthTemplate::Logout();
		$bodyData = getJSONBody();
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", null);
	}

	// POST
	public function CheckToken()
	{
		// Gelen Verilerin Doğrulaması
		$tempData = AuthTemplate::CheckToken();
		$bodyData = getJSONBody();
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"token" => "",
			"type" => "ogrenci|ogretmen|veli",
			"code" => "",
		]);
	}
}
