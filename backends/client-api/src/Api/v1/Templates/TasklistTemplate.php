<?php
// ============================================================================
// File:    TasklistTemplate.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(TEMPLATES . "regex.php");
require_once(HELPER . "Validator.php");

class TasklistTemplate
{

	// GET
	public static function Index(/*$tasklist_code*/)
	{
		return [
			"tasklist_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require()
		];
	}

	// PUT
	public static function Change(/*$tasklist_code*/)
	{
		return [
			"tasklist_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
			"title" => Validator::create()->str(TITLE_MIN_LEN, TITLE_MAX_LEN)->insertRegexRule(TITLE_REGEX_ERROR, TITLE_REGEX_RULE)->require(),
			"description" => Validator::create()->str(DESC_MIN_LEN, DESC_MAX_LEN)->insertRegexRule(DESC_REGEX_ERROR, DESC_REGEX_RULE)->require(),
			"is_everyone" => Validator::create()->bool()->require(),
			/*ŞU OLMAYABİLİR*/
			"students" => Validator::create()->array(1)->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->optional(),
			"deadline" => Validator::create()->datetime(new DateTime())->require()
		];
	}

	// DELETE
	public static function Delete(/*$tasklist_code*/)
	{
		return [
			"tasklist_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require()
		];
	}

	// GET
	public static function GetTaskStat(/*$tasklist_code, $task_code*/)
	{
		return [
			"tasklist_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
			"task_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require()
		];
	}
}
