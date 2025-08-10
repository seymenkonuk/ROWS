<?php
// ============================================================================
// File:    RegisterTeacherScheme.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Validator.php");

require_once(SCHEME . "regex.php");

class RegisterTeacherScheme
{
    public static function Body()
    {
        return [
            "username" => Validator::create()->str()->min(NAME_MIN_LEN)->max(NAME_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
            "password" => Validator::create()->str()->min(PASSWORD_MIN_LEN)->max(PASSWORD_MAX_LEN)->insertRegexRule(PASSWORD_REGEX_ERROR, PASSWORD_REGEX_RULE)->require(),
            "name" => Validator::create()->str()->min(NAME_MIN_LEN)->max(NAME_MAX_LEN)->insertRegexRule(NAME_REGEX_ERROR, NAME_REGEX_RULE)->require(),
            "surname" => Validator::create()->str()->min(NAME_MIN_LEN)->max(NAME_MAX_LEN)->insertRegexRule(NAME_REGEX_ERROR, NAME_REGEX_RULE)->require(),
        ];
    }

    public static function Query()
    {
        return [];
    }

    public static function Params()
    {
        return [];
    }
}
