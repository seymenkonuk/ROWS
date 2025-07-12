<?php
// ============================================================================
// File:    TeacherTemplate.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(TEMPLATES . "regex.php");
require_once(HELPER . "Validator.php");

class TeacherTemplate
{

	// GET
	public static function GetMe()
	{
		return [];
	}

	// GET
	public static function GetTeacher(/*$teacher_code*/)
	{
		return [
			"teacher_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require()
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
	public static function ChangeTeacher(/*$teacher_code*/)
	{
		return [
			"teacher_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
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
	public static function DeleteTeacher(/*$teacher_code*/)
	{
		return [
			"teacher_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require()
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
	public static function ChangePassword(/*$teacher_code*/)
	{
		return [
			"teacher_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
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
	public static function GetClasses(/*$teacher_code*/)
	{
		return [
			"teacher_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
			"offset" => Validator::create()->int(0)->optional(),
			"limit" => Validator::create()->int(1)->optional()
		];
	}

	// POST
	public static function AddMyClasses()
	{
		return [
			"title" => Validator::create()->str(TITLE_MIN_LEN, TITLE_MAX_LEN)->insertRegexRule(TITLE_REGEX_ERROR, TITLE_REGEX_RULE)->require(),
			"description" => Validator::create()->str(DESC_MIN_LEN, DESC_MAX_LEN)->insertRegexRule(DESC_REGEX_ERROR, DESC_REGEX_RULE)->require()
		];
	}

	// POST
	public static function AddClasses(/*$teacher_code*/)
	{
		return [
			"teacher_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
			"title" => Validator::create()->str(TITLE_MIN_LEN, TITLE_MAX_LEN)->insertRegexRule(TITLE_REGEX_ERROR, TITLE_REGEX_RULE)->require(),
			"description" => Validator::create()->str(DESC_MIN_LEN, DESC_MAX_LEN)->insertRegexRule(DESC_REGEX_ERROR, DESC_REGEX_RULE)->require()
		];
	}
}
