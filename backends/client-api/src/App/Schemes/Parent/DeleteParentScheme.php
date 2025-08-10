<?php
// ============================================================================
// File:    DeleteParentScheme.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Validator.php");

require_once(SCHEME . "regex.php");

class DeleteParentScheme
{
    public static function Body()
    {
        return [];
    }

    public static function Query()
    {
        return [];
    }

    public static function Params()
    {
        return [
            "parent_code" => Validator::create()->str()->min(CODE_MIN_LEN)->max(CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require()
        ];
    }
}
