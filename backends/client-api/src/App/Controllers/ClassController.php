<?php
// ============================================================================
// File:    ClassController.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Controller.php");
require_once(CORE . "Request.php");

class ClassController extends Controller
{

	// POST
	public function Create()
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"code" => "",
			"title" => "",
			"description" => "",
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
			"student_count" => "",
			"tasklist_count" => "",
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
			"student_count" => "",
			"tasklist_count" => "",
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

	// POST
	public function Join($code)
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", NULL);
	}

	// POST
	public function Leave($code)
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", NULL);
	}

	// GET [QSA]
	public function GetStudents($code)
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
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
	public function AddStudent($class_code)
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"created_at" => ""
		]);
	}

	// DELETE
	public function RemoveStudent($class_code, $student_code)
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"deleted_at" => ""
		]);
	}

	// GET [QSA]
	public function GetLeaderboard($code)
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
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
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
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
}
