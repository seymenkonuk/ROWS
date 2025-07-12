<?php
// ============================================================================
// File:    TaskController.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Controller.php");

require_once(HELPER . "Validator.php");
require_once(HELPER . "readBody.php");

require_once(TEMPLATES . "TaskTemplate.php");

class TaskController extends Controller
{
	// POST
	public function Create()
	{
		// Gelen Verilerin Doğrulaması
		$tempData = TaskTemplate::Create();
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
			"map_data" => "",
			"is_public" => "",
			"version" => "",
			"difficult" => "",
			"created_at" => "",
		]);
	}

	// GET
	public function GetTask($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = TaskTemplate::GetTask();
		$bodyData = getJSONBody();
		$bodyData["task_code"] = $bodyData["task_code"] ?? $code;
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"code" => "",
			"title" => "",
			"description" => "",
			"map_data" => "",
			"teacher" => [
				"code" => "",
				"name" => "",
				"surname" => "",
			],
			"best_student" => [
				"code" => "",
				"name" => "",
				"surname" => "",
				"score" => "",
			],
			"is_public" => "",
			"version" => "",
			"difficult" => "",
			"created_at" => "",
			"updated_at" => "",
		]);
	}

	// PUT
	public function ChangeTask($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = TaskTemplate::ChangeTask();
		$bodyData = getJSONBody();
		$bodyData["task_code"] = $bodyData["task_code"] ?? $code;
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"code" => "",
			"title" => "",
			"description" => "",
			"map_data" => "",
			"teacher" => [
				"code" => "",
				"name" => "",
				"surname" => "",
			],
			"is_public" => "",
			"version" => "",
			"difficult" => "",
			"created_at" => "",
			"updated_at" => "",
		]);
	}

	// DELETE
	public function DeleteTask($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = TaskTemplate::DeleteTask();
		$bodyData = getJSONBody();
		$bodyData["task_code"] = $bodyData["task_code"] ?? $code;
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
	public function LikeTask($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = TaskTemplate::LikeTask();
		$bodyData = getJSONBody();
		$bodyData["task_code"] = $bodyData["task_code"] ?? $code;
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", NULL);
	}

	// POST
	public function UnlikeTask($code)
	{
		// Gelen Verilerin Doğrulaması
		$tempData = TaskTemplate::UnlikeTask();
		$bodyData = getJSONBody();
		$bodyData["task_code"] = $bodyData["task_code"] ?? $code;
		$errorArray = Validator::validateData($tempData, $bodyData);
		if ($errorArray) {
			return $this->SendBadRequestError($errorArray);
		}
		// 
		return $this->SendSuccessData("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", NULL);
	}

	// GET [QSA]
	public function GetFavoriteTasks()
	{
		// Gelen Verilerin Doğrulaması
		$tempData = TaskTemplate::GetFavoriteTasks();
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
			],
			[
				"code" => "",
				"title" => "",
				"description" => "",
			],
		]);
	}
}
