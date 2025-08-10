<?php
// ============================================================================
// File:    IsSuperUserScheme.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Validator.php");

class IsSuperUserScheme
{
    public static function Body()
    {
        return [
            "username" => Validator::create()->str()->require(),
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
