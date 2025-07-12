<?php
// ============================================================================
// File:    StudentController.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Controller.php");

require_once(HELPER . "Validator.php");
require_once(HELPER . "readBody.php");

require_once(TEMPLATES . "StudentTemplate.php");

class StudentController extends Controller
{

	// GET
	public function GetMe()
	{
		// Gelen Verilerin Doğrulaması
		$tempData = StudentTemplate::GetMe();
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
			"username" => "",
			"name" => "",
			"surname" => "",
			"class_count" => "",
			"created_at" => "",
			"updated_at" => "",
		]);
	}

	// GET
	public function GetStudent($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = StudentTemplate::GetStudent();
		$bodyData = getJSONBody();
		$bodyData["student_code"] = $bodyData["student_code"] ?? $code;
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
			"username" => "",
			"name" => "",
			"surname" => "",
			"class_count" => "",
			"created_at" => "",
			"updated_at" => "",
		]);
	}

	// PUT
	public function ChangeMe()
	{
		// Gelen Verilerin Doğrulaması
		$tempData = StudentTemplate::ChangeMe();
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
			"username" => "",
			"name" => "",
			"surname" => "",
			"class_count" => "",
			"created_at" => "",
			"updated_at" => "",
		]);
	}

	// PUT
	public function ChangeStudent($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = StudentTemplate::ChangeStudent();
		$bodyData = getJSONBody();
		$bodyData["student_code"] = $bodyData["student_code"] ?? $code;
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
			"username" => "",
			"name" => "",
			"surname" => "",
			"class_count" => "",
			"created_at" => "",
			"updated_at" => "",
		]);
	}

	// DELETE
	public function DeleteMe()
	{
		// Gelen Verilerin Doğrulaması
		$tempData = StudentTemplate::DeleteMe();
		$bodyData = getJSONBody();
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"deleted_at" => "",
		]);
	}

	// DELETE
	public function DeleteStudent($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = StudentTemplate::DeleteStudent();
		$bodyData = getJSONBody();
		$bodyData["student_code"] = $bodyData["student_code"] ?? $code;
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"deleted_at" => "",
		]);
	}

	// POST
	public function ChangeMyPassword()
	{
		// Gelen Verilerin Doğrulaması
		$tempData = StudentTemplate::ChangeMyPassword();
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
		$tempData = StudentTemplate::ChangePassword();
		$bodyData = getJSONBody();
		$bodyData["student_code"] = $bodyData["student_code"] ?? $code;
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"updated_at" => "",
		]);
	}

	// GET [QSA]
	public function GetMyClasses()
	{
		// Gelen Verilerin Doğrulaması
		$tempData = StudentTemplate::GetMyClasses();
		$bodyData = getJSONBody();
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			[
				"code" => "",
				"title" => "",
				"description" => "",
				"teacher" => [
					"code" => "",
					"name" => "",
					"surname" => "",
				],
			],
			[
				"code" => "",
				"title" => "",
				"description" => "",
				"teacher" => [
					"code" => "",
					"name" => "",
					"surname" => "",
				],
			],
		]);
	}

	// GET [QSA]
	public function GetClasses($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = StudentTemplate::GetClasses();
		$bodyData = getJSONBody();
		$bodyData["student_code"] = $bodyData["student_code"] ?? $code;
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			[
				"code" => "",
				"title" => "",
				"description" => "",
				"teacher" => [
					"code" => "",
					"name" => "",
					"surname" => "",
				],
			],
			[
				"code" => "",
				"title" => "",
				"description" => "",
				"teacher" => [
					"code" => "",
					"name" => "",
					"surname" => "",
				],
			],
		]);
	}
}
