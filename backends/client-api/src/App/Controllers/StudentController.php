<?php
// ============================================================================
// File:    StudentController.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Controller.php");
require_once(CORE . "Request.php");

class StudentController extends Controller
{

	// GET
	public function GetMe()
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
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
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
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
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
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
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
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
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"deleted_at" => "",
		]);
	}

	// DELETE
	public function DeleteStudent($code)
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
	public function GetMyClasses()
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
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
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
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
