<?php
// ============================================================================
// File:    TeacherController.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Controller.php");

require_once(HELPER . "Validator.php");
require_once(HELPER . "readBody.php");

require_once(TEMPLATES . "TeacherTemplate.php");

class TeacherController extends Controller
{

	// GET
	public function GetMe()
	{
		// Gelen Verilerin Doğrulaması
		$tempData = TeacherTemplate::GetMe();
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
			"class_count" => "",
			"created_at" => "",
			"updated_at" => "",
		]);
	}

	// GET
	public function GetTeacher($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = TeacherTemplate::GetTeacher();
		$bodyData = getJSONBody();
		$bodyData["teacher_code"] = $bodyData["teacher_code"] ?? $code;
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
			"class_count" => "",
			"created_at" => "",
			"updated_at" => "",
		]);
	}

	// PUT
	public function ChangeMe()
	{
		// Gelen Verilerin Doğrulaması
		$tempData = TeacherTemplate::ChangeMe();
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
			"class_count" => "",
			"created_at" => "",
			"updated_at" => "",
		]);
	}

	// PUT
	public function ChangeTeacher($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = TeacherTemplate::ChangeTeacher();
		$bodyData = getJSONBody();
		$bodyData["teacher_code"] = $bodyData["teacher_code"] ?? $code;
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
			"class_count" => "",
			"created_at" => "",
			"updated_at" => "",
		]);
	}

	// DELETE
	public function DeleteMe()
	{
		// Gelen Verilerin Doğrulaması
		$tempData = TeacherTemplate::DeleteMe();
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
	public function DeleteTeacher($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = TeacherTemplate::DeleteTeacher();
		$bodyData = getJSONBody();
		$bodyData["teacher_code"] = $bodyData["teacher_code"] ?? $code;
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
		$tempData = TeacherTemplate::ChangeMyPassword();
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
		$tempData = TeacherTemplate::ChangePassword();
		$bodyData = getJSONBody();
		$bodyData["teacher_code"] = $bodyData["teacher_code"] ?? $code;
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
		$tempData = TeacherTemplate::GetMyClasses();
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
		$tempData = TeacherTemplate::GetClasses();
		$bodyData = getJSONBody();
		$bodyData["teacher_code"] = $bodyData["teacher_code"] ?? $code;
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

	// POST
	public function AddMyClasses()
	{
		// Gelen Verilerin Doğrulaması
		$tempData = TeacherTemplate::AddMyClasses();
		$bodyData = getJSONBody();
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"code" => "",
			"title" => "",
			"description" => "",
			"created_at" => "",
		]);
	}

	// POST
	public function AddClasses($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = TeacherTemplate::AddClasses();
		$bodyData = getJSONBody();
		$bodyData["teacher_code"] = $bodyData["teacher_code"] ?? $code;
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"code" => "",
			"title" => "",
			"description" => "",
			"created_at" => "",
		]);
	}
}
