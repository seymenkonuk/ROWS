<?php
// ============================================================================
// File:    ChangeMeScheme.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Validator.php");

require_once(SCHEME . "regex.php");

class ChangeMeScheme
{
    public static function Body()
    {
        return [
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
