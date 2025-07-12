<?php
// ============================================================================
// File:    StudentTemplate.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(TEMPLATES . "regex.php");
require_once(HELPER . "Validator.php");

class StudentTemplate
{

	// GET
	public static function GetMe()
	{
		return [];
	}

	// GET
	public static function GetStudent(/*$student_code*/)
	{
		return [
			"student_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require()
		];
	}

	// PUT
	public static function ChangeMe()
	{
		return [
			"name" => Validator::create()->str(NAME_MIN_LEN, NAME_MAX_LEN)->insertRegexRule(NAME_REGEX_ERROR, NAME_REGEX_RULE)->require(),
			"surname" => Validator::create()->str(NAME_MIN_LEN, NAME_MAX_LEN)->insertRegexRule(NAME_REGEX_ERROR, NAME_REGEX_RULE)->require(),
		];
	}

	// PUT
	public static function ChangeStudent(/*$student_code*/)
	{
		return [
			"student_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
			"name" => Validator::create()->str(NAME_MIN_LEN, NAME_MAX_LEN)->insertRegexRule(NAME_REGEX_ERROR, NAME_REGEX_RULE)->require(),
			"surname" => Validator::create()->str(NAME_MIN_LEN, NAME_MAX_LEN)->insertRegexRule(NAME_REGEX_ERROR, NAME_REGEX_RULE)->require(),
		];
	}

	// DELETE
	public static function DeleteMe()
	{
		return [];
	}

	// DELETE
	public static function DeleteStudent(/*$student_code*/)
	{
		return [
			"student_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require()
		];
	}

	// POST
	public static function ChangeMyPassword()
	{
		return [
			"old_password" => Validator::create()->str(PASSWORD_MIN_LEN, PASSWORD_MAX_LEN)->insertRegexRule(PASSWORD_REGEX_ERROR, PASSWORD_REGEX_RULE)->require(),
			"new_password" => Validator::create()->str(PASSWORD_MIN_LEN, PASSWORD_MAX_LEN)->insertRegexRule(PASSWORD_REGEX_ERROR, PASSWORD_REGEX_RULE)->require()
		];
	}

	// POST
	public static function ChangePassword(/*$student_code*/)
	{
		return [
			"student_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
			"old_password" => Validator::create()->str(PASSWORD_MIN_LEN, PASSWORD_MAX_LEN)->insertRegexRule(PASSWORD_REGEX_ERROR, PASSWORD_REGEX_RULE)->require(),
			"new_password" => Validator::create()->str(PASSWORD_MIN_LEN, PASSWORD_MAX_LEN)->insertRegexRule(PASSWORD_REGEX_ERROR, PASSWORD_REGEX_RULE)->require()
		];
	}

	// GET [QSA]
	public static function GetMyClasses()
	{
		return [
			"offset" => Validator::create()->int(0)->optional(),
			"limit" => Validator::create()->int(1)->optional()
		];
	}

	// GET [QSA]
	public static function GetClasses(/*$student_code*/)
	{
		return [
			"student_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
			"offset" => Validator::create()->int(0)->optional(),
			"limit" => Validator::create()->int(1)->optional()
		];
	}
}
