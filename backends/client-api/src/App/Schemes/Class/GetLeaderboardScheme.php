<?php
// ============================================================================
// File:    GetLeaderboardScheme.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Validator.php");

require_once(SCHEME . "regex.php");

class GetLeaderboardScheme
{
    public static function Body()
    {
        return [];
    }

    public static function Query()
    {
        return [
            "range" => Validator::create()->str()->insertAllowValue("Daily")->insertAllowValue("Weekly")->insertAllowValue("All Time")->require(),
            "offset" => Validator::create()->int()->min(0)->optional(),
            "limit" => Validator::create()->int()->min(1)->optional()
        ];
    }

    public static function Params()
    {
        return [
            "class_code" => Validator::create()->str()->min(CODE_MIN_LEN)->max(CODE_MAX_LEN)->insertRegexRule(CODE_REGEX_ERROR, CODE_REGEX_RULE)->require()
        ];
    }
}
