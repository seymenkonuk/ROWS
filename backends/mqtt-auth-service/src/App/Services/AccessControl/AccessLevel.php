<?php
// ============================================================================
// File:    AccessLevel.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

class AccessLevel
{
    public const READ  = 0b01;
    public const WRITE = 0b10;

    public static function isRead(int $acc): bool
    {
        return ($acc & self::READ) !== 0;
    }

    public static function isWrite(int $acc): bool
    {
        return ($acc & self::WRITE) !== 0;
    }
}
