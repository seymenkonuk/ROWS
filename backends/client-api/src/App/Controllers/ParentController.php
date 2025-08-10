<?php
// ============================================================================
// File:    ParentController.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Controller.php");
require_once(CORE . "Request.php");

class ParentController extends Controller
{

	// GET
	public function GetMe()
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
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
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
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
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
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
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
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
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"deleted_at" => "",
		]);
	}

	// DELETE
	public function DeleteParent($code)
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"deleted_at" => "",
		]);
	}

	// POST
	public function ChangeMyPassword()
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"updated_at" => "",
		]);
	}

	// POST
	public function ChangePassword($code)
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"updated_at" => "",
		]);
	}

	// GET [QSA]
	public function GetMyStudents()
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
	public function AddMyStudents()
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
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
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"code" => "",
			"username" => "",
			"name" => "",
			"surname" => "",
			"created_at" => "",
		]);
	}
}
