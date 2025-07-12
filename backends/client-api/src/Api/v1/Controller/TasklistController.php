<?php
// ============================================================================
// File:    TasklistController.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Controller.php");

require_once(HELPER . "Validator.php");
require_once(HELPER . "readBody.php");

require_once(TEMPLATES . "TasklistTemplate.php");

class TasklistController extends Controller
{

	// GET
	public function Index($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = TasklistTemplate::Index();
		$bodyData = getJSONBody();
		$bodyData["tasklist_code"] = $bodyData["tasklist_code"] ?? $code;
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
			"is_everyone" => "",
			"tasks" => [
				"code1",
				"code2",
			],
			"deadline" => "",
			"created_at" => "",
			"updated_at" => "",
		]);
	}

	// PUT
	public function Change($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = TasklistTemplate::Change();
		$bodyData = getJSONBody();
		$bodyData["tasklist_code"] = $bodyData["tasklist_code"] ?? $code;
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
			"is_everyone" => "",
			"tasks" => [
				"code1",
				"code2",
			],
			"deadline" => "",
			"created_at" => "",
			"updated_at" => "",
		]);
	}

	// DELETE
	public function Delete($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = TasklistTemplate::Delete();
		$bodyData = getJSONBody();
		$bodyData["tasklist_code"] = $bodyData["tasklist_code"] ?? $code;
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"deleted_at" => "",
		]);
	}

	// GET
	public function GetTaskStat($tasklist_code, $task_code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = TasklistTemplate::GetTaskStat();
		$bodyData = getJSONBody();
		$bodyData["tasklist_code"] = $bodyData["tasklist_code"] ?? $tasklist_code;
		$bodyData["task_code"] = $bodyData["task_code"] ?? $task_code;
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"successful_student" => [
				[
					"rank" => "",
					"code" => "ogrenci1",
					"score" => "",
					"timestamp" => "",
				],
				[
					"rank" => "",
					"code" => "ogrenci1",
					"score" => "",
					"timestamp" => "",
				],
			],
			"failed_student" => [
				[
					"code" => "ogrenci1",
					"score" => "",
					"timestamp" => "",
				],
				[
					"code" => "ogrenci1",
					"score" => "",
					"timestamp" => "",
				],
			],
			"pending_student" => [
				"code1",
				"code2",
			],
		]);
	}
}
