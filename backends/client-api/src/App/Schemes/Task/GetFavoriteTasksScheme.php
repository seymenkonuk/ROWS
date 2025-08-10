<?php
// ============================================================================
// File:    GetFavoriteTasksScheme.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Validator.php");

require_once(SCHEME . "regex.php");

class GetFavoriteTasksScheme
{
    public static function Body()
    {
        return [];
    }

    public static function Query()
    {
        return [
            "offset" => Validator::create()->int()->min(0)->optional(),
            "limit" => Validator::create()->int()->min(1)->optional()
        ];
    }

    public static function Params()
    {
        return [];
    }
}
