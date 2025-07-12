<?php
// ============================================================================
// File:    DeviceController.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Controller.php");

require_once(HELPER . "Validator.php");
require_once(HELPER . "readBody.php");

require_once(TEMPLATES . "DeviceTemplate.php");

class DeviceController extends Controller
{

	// GET
	public function GetMe()
	{
		// Gelen Verilerin Doğrulaması
		$tempData = DeviceTemplate::GetMe();
		$bodyData = getJSONBody();
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"code" => "",
			"parent" => [
				"code" => "",
				"name" => "",
				"surname" => "",
			],
			"active_student" => [
				"code" => "",
				"name" => "",
				"surname" => "",
			],
			"created_at" => "",
			"updated_at" => "",
		]);
	}

	// GET
	public function GetDevice($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = DeviceTemplate::GetDevice();
		$bodyData = getJSONBody();
		$bodyData["device_code"] = $bodyData["device_code"] ?? $code;
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"code" => "",
			"parent" => [
				"code" => "",
				"name" => "",
				"surname" => "",
			],
			"active_student" => [
				"code" => "",
				"name" => "",
				"surname" => "",
			],
			"created_at" => "",
			"updated_at" => "",
		]);
	}

	// PUT
	public function ChangeMe()
	{
		// Gelen Verilerin Doğrulaması
		$tempData = DeviceTemplate::ChangeMe();
		$bodyData = getJSONBody();
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"code" => "",
			"parent" => [
				"code" => "",
				"name" => "",
				"surname" => "",
			],
			"active_student" => [
				"code" => "",
				"name" => "",
				"surname" => "",
			],
			"created_at" => "",
			"updated_at" => "",
		]);
	}

	// PUT
	public function ChangeDevice($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = DeviceTemplate::ChangeDevice();
		$bodyData = getJSONBody();
		$bodyData["device_code"] = $bodyData["device_code"] ?? $code;
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"code" => "",
			"parent" => [
				"code" => "",
				"name" => "",
				"surname" => "",
			],
			"active_student" => [
				"code" => "",
				"name" => "",
				"surname" => "",
			],
			"created_at" => "",
			"updated_at" => "",
		]);
	}

	// POST
	public function ChangeMyPassword()
	{
		// Gelen Verilerin Doğrulaması
		$tempData = DeviceTemplate::ChangeMyPassword();
		$bodyData = getJSONBody();
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"updated_at" => "",
		]);
	}

	// POST
	public function ChangePassword($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = DeviceTemplate::ChangePassword();
		$bodyData = getJSONBody();
		$bodyData["device_code"] = $bodyData["device_code"] ?? $code;
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"updated_at" => "",
		]);
	}

	// POST
	public function ChangeMyActiveStudent()
	{
		// Gelen Verilerin Doğrulaması
		$tempData = DeviceTemplate::ChangeMyActiveStudent();
		$bodyData = getJSONBody();
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"updated_at" => "",
		]);
	}

	// POST
	public function ChangeActiveStudent($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = DeviceTemplate::ChangeActiveStudent();
		$bodyData = getJSONBody();
		$bodyData["device_code"] = $bodyData["device_code"] ?? $code;
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"updated_at" => "",
		]);
	}
}
