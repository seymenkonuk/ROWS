<?php
// ============================================================================
// File:    TasklistController.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Controller.php");
require_once(CORE . "Request.php");

class TasklistController extends Controller
{
	// POST
	public function Create()
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"code" => "",
			"title" => "",
			"description" => "",
			"is_everyone" => "",
			"deadline" => "",
			"created_at" => "",
		]);
	}

	// GET
	public function Index($code)
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
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
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
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
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"deleted_at" => "",
		]);
	}

	// GET
	public function GetTaskStat($tasklist_code, $task_code)
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
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
