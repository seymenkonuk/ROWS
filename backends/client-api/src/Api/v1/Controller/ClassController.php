<?php
// ============================================================================
// File:    ClassController.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Controller.php");

require_once(HELPER . "Validator.php");
require_once(HELPER . "readBody.php");

require_once(TEMPLATES . "ClassTemplate.php");

class ClassController extends Controller
{

	// GET
	public function Index($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = ClassTemplate::Index();
		$bodyData = getJSONBody();
		$bodyData["class_code"] = $bodyData["class_code"] ?? $code;
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"code" => "",
			"title" => "",
			"description" => "",
			"teacher" => [
				"code" => "",
				"name" => "",
				"surname" => "",
			],
			"student_count" => "",
			"tasklist_count" => "",
			"created_at" => "",
			"updated_at" => "",
		]);
	}

	// PUT
	public function ChangeInfo($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = ClassTemplate::ChangeInfo();
		$bodyData = getJSONBody();
		$bodyData["class_code"] = $bodyData["class_code"] ?? $code;
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"code" => "",
			"title" => "",
			"description" => "",
			"teacher" => [
				"code" => "",
				"name" => "",
				"surname" => "",
			],
			"student_count" => "",
			"tasklist_count" => "",
			"created_at" => "",
			"updated_at" => "",
		]);
	}

	// DELETE
	public function Delete($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = ClassTemplate::Delete();
		$bodyData = getJSONBody();
		$bodyData["class_code"] = $bodyData["class_code"] ?? $code;
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
	public function Join($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = ClassTemplate::Join();
		$bodyData = getJSONBody();
		$bodyData["class_code"] = $bodyData["class_code"] ?? $code;
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", NULL);
	}

	// POST
	public function Leave($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = ClassTemplate::Leave();
		$bodyData = getJSONBody();
		$bodyData["class_code"] = $bodyData["class_code"] ?? $code;
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", NULL);
	}

	// GET [QSA]
	public function GetStudents($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = ClassTemplate::GetStudents();
		$bodyData = getJSONBody();
		$bodyData["class_code"] = $bodyData["class_code"] ?? $code;
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

	// DELETE
	public function RemoveStudent($class_code, $student_code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = ClassTemplate::RemoveStudent();
		$bodyData = getJSONBody();
		$bodyData["class_code"] = $bodyData["class_code"] ?? $class_code;
		$bodyData["student_code"] = $bodyData["student_code"] ?? $student_code;
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"deleted_at" => ""
		]);
	}

	// GET [QSA]
	public function GetLeaderboard($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = ClassTemplate::GetLeaderboard();
		$bodyData = getJSONBody();
		$bodyData["class_code"] = $bodyData["class_code"] ?? $code;
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			[
				"rank" => "1",
				"code" => "",
				"name" => "",
				"surname" => "",
				"score" => "1000"
			],
			[
				"rank" => "2",
				"code" => "",
				"name" => "",
				"surname" => "",
				"score" => "900"
			],
		]);
	}

	// GET [QSA]
	public function GetTasklists($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = ClassTemplate::GetTasklists();
		$bodyData = getJSONBody();
		$bodyData["class_code"] = $bodyData["class_code"] ?? $code;
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
				"is_everyone" => "",
				"deadline" => "",
				"task_count" => "",
			],
			[
				"code" => "",
				"title" => "",
				"description" => "",
				"is_everyone" => "",
				"deadline" => "",
				"task_count" => "",
			],
		]);
	}

	// POST
	public function CreateTasklist($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = ClassTemplate::CreateTasklist();
		$bodyData = getJSONBody();
		$bodyData["class_code"] = $bodyData["class_code"] ?? $code;
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"code" => "",
			"title" => "",
			"description" => "",
			"is_everyone" => "",
			"deadline" => "",
			"created_at" => "",
		]);
	}
}
