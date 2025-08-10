<?php
// ============================================================================
// File:    ChangePasswordScheme.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Validator.php");

require_once(SCHEME . "regex.php");

class ChangePasswordScheme
{
    public static function Body()
    {
        return [
            "old_password" => Validator::create()->str()->min(PASSWORD_MIN_LEN)->max(PASSWORD_MAX_LEN)->insertRegexRule(PASSWORD_REGEX_ERROR, PASSWORD_REGEX_RULE)->require(),
            "new_password" => Validator::create()->str()->min(PASSWORD_MIN_LEN)->max(PASSWORD_MAX_LEN)->insertRegexRule(PASSWORD_REGEX_ERROR, PASSWORD_REGEX_RULE)->require()
        ];
    }

    public static function Query()
    {
        return [];
    }

    public static function Params()
    {
        return [
            "device_code" => Validator::create()->str()->min(CODE_MIN_LEN)->max(CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require()
        ];
    }
}
