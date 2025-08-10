<?php
// ============================================================================
// File:    GetMyClassesScheme.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Validator.php");

require_once(SCHEME . "regex.php");

class GetMyClassesScheme
{
    public static function Body()
    {
        return [
            "offset" => Validator::create()->int()->min(0)->optional(),
            "limit" => Validator::create()->int()->min(1)->optional()
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
