<?php
// ============================================================================
// File:    GetLatestVersionScheme.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Validator.php");

require_once(SCHEME . "regex.php");

class GetLatestVersionScheme
{
    public static function Body()
    {
        return Validator::create()->str()->min(VERSION_MIN_LEN)->max(VERSION_MAX_LEN)->insertRegexRule(VERSION_REGEX_ERROR, VERSION_REGEX_RULE)->require();
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
