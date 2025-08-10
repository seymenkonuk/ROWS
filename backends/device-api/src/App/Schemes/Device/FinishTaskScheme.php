<?php
// ============================================================================
// File:    FinishTaskScheme.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Validator.php");

class FinishTaskScheme
{
    public static function Body()
    {
        return [
            "tasklist_id" => Validator::create()->int()->require(),
            "task_id" => Validator::create()->int()->require(),
            "response" => Validator::create()->str()->require(),
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
