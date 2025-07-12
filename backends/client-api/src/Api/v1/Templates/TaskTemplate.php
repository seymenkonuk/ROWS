<?php
// ============================================================================
// File:    TaskTemplate.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(TEMPLATES . "regex.php");
require_once(HELPER . "Validator.php");

class TaskTemplate
{
	// POST
	public static function Create()
	{
		return [
			"title" => Validator::create()->str(TITLE_MIN_LEN, TITLE_MAX_LEN)->insertRegexRule(TITLE_REGEX_ERROR, TITLE_REGEX_RULE)->require(),
			"description" => Validator::create()->str(DESC_MIN_LEN, DESC_MAX_LEN)->insertRegexRule(DESC_REGEX_ERROR, DESC_REGEX_RULE)->require(),
			"map_data" => Validator::create()->str()->require(),
			"is_public" => Validator::create()->bool()->require(),
			"difficulty" => Validator::create()->str()->insertAllowValue("Easy")->insertAllowValue("Medium")->insertAllowValue("Hard")->require(),
		];
	}

	// GET
	public static function GetTask(/*$task_code*/)
	{
		return [
			"task_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
		];
	}

	// PUT
	public static function ChangeTask(/*$task_code*/)
	{
		return [
			"task_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
			"title" => Validator::create()->str(TITLE_MIN_LEN, TITLE_MAX_LEN)->insertRegexRule(TITLE_REGEX_ERROR, TITLE_REGEX_RULE)->require(),
			"description" => Validator::create()->str(DESC_MIN_LEN, DESC_MAX_LEN)->insertRegexRule(DESC_REGEX_ERROR, DESC_REGEX_RULE)->require(),
			"is_public" => Validator::create()->bool()->require(),
			"difficulty" => Validator::create()->str()->insertAllowValue("Easy")->insertAllowValue("Medium")->insertAllowValue("Hard")->require(),
		];
	}

	// DELETE
	public static function DeleteTask(/*$task_code*/)
	{
		return [
			"task_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require()
		];
	}

	// POST
	public static function LikeTask(/*$task_code*/)
	{
		return [
			"task_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require()
		];
	}

	// POST
	public static function UnlikeTask(/*$task_code*/)
	{
		return [
			"task_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require()
		];
	}

	// GET [QSA]
	public static function GetFavoriteTasks()
	{
		return [
			"offset" => Validator::create()->int(0)->optional(),
			"limit" => Validator::create()->int(1)->optional()
		];
	}
}
