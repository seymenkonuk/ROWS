<?php
// ============================================================================
// File:    AuthTemplate.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(TEMPLATES . "regex.php");
require_once(HELPER . "Validator.php");

class AuthTemplate
{
	// POST
	public static function RegisterParent()
	{
		return [
			"device_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
			"device_pass" => Validator::create()->str(PASSWORD_MIN_LEN, PASSWORD_MAX_LEN)->insertRegexRule(PASSWORD_REGEX_ERROR, PASSWORD_REGEX_RULE)->require(),
			"username" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
			"password" => Validator::create()->str(PASSWORD_MIN_LEN, PASSWORD_MAX_LEN)->insertRegexRule(PASSWORD_REGEX_ERROR, PASSWORD_REGEX_RULE)->require(),
			"name" => Validator::create()->str(NAME_MIN_LEN, NAME_MAX_LEN)->insertRegexRule(NAME_REGEX_ERROR, NAME_REGEX_RULE)->require(),
			"surname" => Validator::create()->str(NAME_MIN_LEN, NAME_MAX_LEN)->insertRegexRule(NAME_REGEX_ERROR, NAME_REGEX_RULE)->require(),
		];
	}

	// POST
	public static function RegisterTeacher()
	{
		return [
			"username" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
			"password" => Validator::create()->str(PASSWORD_MIN_LEN, PASSWORD_MAX_LEN)->insertRegexRule(PASSWORD_REGEX_ERROR, PASSWORD_REGEX_RULE)->require(),
			"name" => Validator::create()->str(NAME_MIN_LEN, NAME_MAX_LEN)->insertRegexRule(NAME_REGEX_ERROR, NAME_REGEX_RULE)->require(),
			"surname" => Validator::create()->str(NAME_MIN_LEN, NAME_MAX_LEN)->insertRegexRule(NAME_REGEX_ERROR, NAME_REGEX_RULE)->require(),
		];
	}

	// POST
	public static function Login()
	{
		return [
			"username" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
			"password" => Validator::create()->str(PASSWORD_MIN_LEN, PASSWORD_MAX_LEN)->insertRegexRule(PASSWORD_REGEX_ERROR, PASSWORD_REGEX_RULE)->require(),
		];
	}

	// POST
	public static function Logout()
	{
		return [];
	}

	// POST
	public static function CheckToken()
	{
		return [];
	}
}
