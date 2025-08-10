<?php
// ============================================================================
// File:    ChangeScheme.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Validator.php");

require_once(SCHEME . "regex.php");

class ChangeScheme
{
    public static function Body()
    {
        return [
            "title" => Validator::create()->str()->min(TITLE_MIN_LEN)->max(TITLE_MAX_LEN)->insertRegexRule(TITLE_REGEX_ERROR, TITLE_REGEX_RULE)->require(),
            "description" => Validator::create()->str()->min(DESC_MIN_LEN)->max(DESC_MAX_LEN)->insertRegexRule(DESC_REGEX_ERROR, DESC_REGEX_RULE)->require()
        ];
    }

    public static function Query()
    {
        return [];
    }

    public static function Params()
    {
        return [
            "class_code" => Validator::create()->str()->min(CODE_MIN_LEN)->max(CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require(),
        ];
    }
}
