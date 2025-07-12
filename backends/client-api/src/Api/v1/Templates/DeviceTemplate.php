<?php
// ============================================================================
// File:    DeviceTemplate.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(TEMPLATES . "regex.php");
require_once(HELPER . "Validator.php");

class DeviceTemplate
{

	// GET
	public static function GetMe()
	{
		return [];
	}

	// GET
	public static function GetDevice(/*$device_code*/)
	{
		return [
			"device_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require()
		];
	}

	// PUT
	public static function ChangeMe()
	{
		return [
			/* DEĞİŞTİRİLECEK VERİ YOK (BELKİ DE ŞİMDİLİK) */];
	}

	// PUT
	public static function ChangeDevice(/*$device_code*/)
	{
		return [
			"device_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require()
			/* DEĞİŞTİRİLECEK VERİ YOK (BELKİ DE ŞİMDİLİK) */
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
	public static function ChangePassword(/*$device_code*/)
	{
		return [
			"device_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
			"old_password" => Validator::create()->str(PASSWORD_MIN_LEN, PASSWORD_MAX_LEN)->insertRegexRule(PASSWORD_REGEX_ERROR, PASSWORD_REGEX_RULE)->require(),
			"new_password" => Validator::create()->str(PASSWORD_MIN_LEN, PASSWORD_MAX_LEN)->insertRegexRule(PASSWORD_REGEX_ERROR, PASSWORD_REGEX_RULE)->require()
		];
	}

	// POST
	public static function ChangeMyActiveStudent()
	{
		return [
			"student_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require()
		];
	}

	// POST
	public static function ChangeActiveStudent(/*$device_code*/)
	{
		return [
			"device_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
			"student_code" => Validator::create()->str(CODE_MIN_LEN, CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require()
		];
	}
}
