<?php
// ============================================================================
// File:    PathHelper.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

namespace App\Support\Helpers;


class PathHelper
{
    public static function storage(): string
    {
        return dirname(__DIR__, 3) . DIRECTORY_SEPARATOR . "storage";
    }

    public static function appStorage(): string
    {
        return self::storage() . DIRECTORY_SEPARATOR . "app";
    }

    public static function publicStorage(): string
    {
        return self::appStorage() . DIRECTORY_SEPARATOR . "public";
    }

    public static function privateStorage(): string
    {
        return self::appStorage() . DIRECTORY_SEPARATOR . "private";
    }
}
