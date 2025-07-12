<?php
// ============================================================================
// File:    ParentController.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Controller.php");

require_once(HELPER . "Validator.php");
require_once(HELPER . "readBody.php");

require_once(TEMPLATES . "ParentTemplate.php");

class ParentController extends Controller
{

	// GET
	public function GetMe()
	{
		// Gelen Verilerin Doğrulaması
		$tempData = ParentTemplate::GetMe();
		$bodyData = getJSONBody();
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"code" => "",
			"device" => [
				"code" => "",
				"active_student" => "",
			],
			"username" => "",
			"name" => "",
			"surname" => "",
			"student_count" => "",
			"created_at" => "",
			"updated_at" => "",
		]);
	}

	// GET
	public function GetParent($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = ParentTemplate::GetParent();
		$bodyData = getJSONBody();
		$bodyData["parent_code"] = $bodyData["parent_code"] ?? $code;
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"code" => "",
			"device" => [
				"code" => "",
				"active_student" => "",
			],
			"username" => "",
			"name" => "",
			"surname" => "",
			"student_count" => "",
			"created_at" => "",
			"updated_at" => "",
		]);
	}

	// PUT
	public function ChangeMe()
	{
		// Gelen Verilerin Doğrulaması
		$tempData = ParentTemplate::ChangeMe();
		$bodyData = getJSONBody();
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"code" => "",
			"device" => [
				"code" => "",
				"active_student" => "",
			],
			"username" => "",
			"name" => "",
			"surname" => "",
			"student_count" => "",
			"created_at" => "",
			"updated_at" => "",
		]);
	}

	// PUT
	public function ChangeParent($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = ParentTemplate::ChangeParent();
		$bodyData = getJSONBody();
		$bodyData["parent_code"] = $bodyData["parent_code"] ?? $code;
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"code" => "",
			"device" => [
				"code" => "",
				"active_student" => "",
			],
			"username" => "",
			"name" => "",
			"surname" => "",
			"student_count" => "",
			"created_at" => "",
			"updated_at" => "",
		]);
	}

	// DELETE
	public function DeleteMe()
	{
		// Gelen Verilerin Doğrulaması
		$tempData = ParentTemplate::DeleteMe();
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
	public function DeleteParent($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = ParentTemplate::DeleteParent();
		$bodyData = getJSONBody();
		$bodyData["parent_code"] = $bodyData["parent_code"] ?? $code;
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
		$tempData = ParentTemplate::ChangeMyPassword();
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
		$tempData = ParentTemplate::ChangePassword();
		$bodyData = getJSONBody();
		$bodyData["parent_code"] = $bodyData["parent_code"] ?? $code;
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
	public function GetMyStudents()
	{
		// Gelen Verilerin Doğrulaması
		$tempData = ParentTemplate::GetMyStudents();
		$bodyData = getJSONBody();
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			[
				"code" => "",
				"name" => "",
				"surname" => "",
			],
			[
				"code" => "",
				"name" => "",
				"surname" => "",
			],
		]);
	}

	// GET [QSA]
	public function GetStudents($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = ParentTemplate::GetStudents();
		$bodyData = getJSONBody();
		$bodyData["parent_code"] = $bodyData["parent_code"] ?? $code;
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			[
				"code" => "",
				"name" => "",
				"surname" => "",
			],
			[
				"code" => "",
				"name" => "",
				"surname" => "",
			],
		]);
	}

	// POST
	public function AddMyStudents()
	{
		// Gelen Verilerin Doğrulaması
		$tempData = ParentTemplate::AddMyStudents();
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
			"created_at" => "",
		]);
	}

	// POST
	public function AddStudents($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = ParentTemplate::AddStudents();
		$bodyData = getJSONBody();
		$bodyData["parent_code"] = $bodyData["parent_code"] ?? $code;
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
			"created_at" => "",
		]);
	}
}
