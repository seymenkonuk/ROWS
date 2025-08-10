<?php
// ============================================================================
// File:    DeviceController.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Controller.php");
require_once(CORE . "Request.php");

class DeviceController extends Controller
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
			"active_student" => [
				"code" => "",
				"name" => "",
				"surname" => "",
			],
			"created_at" => "",
			"updated_at" => "",
		]);
	}

	// GET
	public function GetDevice($code)
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"code" => "",
			"parent" => [
				"code" => "",
				"name" => "",
				"surname" => "",
			],
			"active_student" => [
				"code" => "",
				"name" => "",
				"surname" => "",
			],
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
			"active_student" => [
				"code" => "",
				"name" => "",
				"surname" => "",
			],
			"created_at" => "",
			"updated_at" => "",
		]);
	}

	// PUT
	public function ChangeDevice($code)
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"code" => "",
			"parent" => [
				"code" => "",
				"name" => "",
				"surname" => "",
			],
			"active_student" => [
				"code" => "",
				"name" => "",
				"surname" => "",
			],
			"created_at" => "",
			"updated_at" => "",
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

	// POST
	public function ChangeMyActiveStudent()
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"updated_at" => "",
		]);
	}

	// POST
	public function ChangeActiveStudent($code)
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"updated_at" => "",
		]);
	}
}
