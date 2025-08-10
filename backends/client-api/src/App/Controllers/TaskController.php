<?php
// ============================================================================
// File:    TaskController.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Controller.php");
require_once(CORE . "Request.php");

class TaskController extends Controller
{
	// POST
	public function Create()
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
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
	public function Index($code)
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
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
	public function Change($code)
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
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
	public function Delete($code)
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
			"deleted_at" => "",
		]);
	}

	// POST
	public function Like($code)
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", NULL);
	}

	// GET [QSA]
	public function GetFavoriteTasks()
	{
		return $this->JsonSuccess("Daha bitmedi, test amaçlı! Ama bu formatta dönecek!", [
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
