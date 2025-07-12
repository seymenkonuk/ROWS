<?php
// ============================================================================
// File:    ClassTemplate.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(TEMPLATES . "regex.php");
require_once(HELPER . "Validator.php");

class ClassTemplate
{

	// GET
	public static function Index(/*$class_code*/)
	{
		return [
			"class_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require()
		];
	}

	// PUT
	public static function ChangeInfo(/*$class_code*/)
	{
		return [
			"class_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
			"title" => Validator::create()->str(TITLE_MIN_LEN, TITLE_MAX_LEN)->insertRegexRule(TITLE_REGEX_ERROR, TITLE_REGEX_RULE)->require(),
			"description" => Validator::create()->str(DESC_MIN_LEN, DESC_MAX_LEN)->insertRegexRule(DESC_REGEX_ERROR, DESC_REGEX_RULE)->require()
		];
	}

	// DELETE
	public static function Delete(/*$class_code*/)
	{
		return [
			"class_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
		];
	}

	// POST
	public static function Join(/*$class_code*/)
	{
		return [
			"class_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require()
		];
	}

	// POST
	public static function Leave(/*$class_code*/)
	{
		return [
			"class_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require()
		];
	}

	// GET [QSA]
	public static function GetStudents(/*$class_code*/)
	{
		return [
			"class_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
			"offset" => Validator::create()->int(0)->optional(),
			"limit" => Validator::create()->int(1)->optional()
		];
	}

	// POST
	public static function AddStudent(/*$class_code*/)
	{
		return [
			"class_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
			"student_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require()
		];
	}

	// DELETE
	public static function RemoveStudent(/*$class_code, $student_code*/)
	{
		return [
			"class_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
			"student_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require()
		];
	}

	// GET [QSA]
	public static function GetLeaderboard(/*$class_code*/)
	{
		return [
			"class_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
			"range" => Validator::create()->str()->insertAllowValue("Daily")->insertAllowValue("Weekly")->insertAllowValue("All Time")->require(),
			"offset" => Validator::create()->int(0)->optional(),
			"limit" => Validator::create()->int(1)->optional()
		];
	}

	// GET [QSA]
	public static function GetTasklists(/*$class_code*/)
	{
		return [
			"class_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
			"offset" => Validator::create()->int(0)->optional(),
			"limit" => Validator::create()->int(1)->optional()
		];
	}

	// POST
	public static function CreateTasklist(/*$class_code*/)
	{
		return [
			"class_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
			"title" => Validator::create()->str(TITLE_MIN_LEN, TITLE_MAX_LEN)->insertRegexRule(TITLE_REGEX_ERROR, TITLE_REGEX_RULE)->require(),
			"description" => Validator::create()->str(DESC_MIN_LEN, DESC_MAX_LEN)->insertRegexRule(DESC_REGEX_ERROR, DESC_REGEX_RULE)->require(),
			"tasks" => Validator::create()->array(1)->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
			"is_everyone" => Validator::create()->bool()->require(),
			"students" => Validator::create()->array(1)->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->optional(),
			"deadline" => Validator::create()->datetime(new DateTime())->require()
		];
	}
}
