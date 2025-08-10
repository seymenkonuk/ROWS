<?php
// ============================================================================
// File:    CheckTokenScheme.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Validator.php");

require_once(SCHEME . "regex.php");

class CheckTokenScheme
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
        return [];
    }
}
