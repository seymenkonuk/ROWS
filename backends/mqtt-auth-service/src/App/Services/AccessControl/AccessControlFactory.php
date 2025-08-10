<?php
// ============================================================================
// File:    AccessControlFactory.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(__DIR__ . DIRECTORY_SEPARATOR . "DeviceAccessControl.php");
require_once(__DIR__ . DIRECTORY_SEPARATOR . "ParentAccessControl.php");
require_once(__DIR__ . DIRECTORY_SEPARATOR . "StudentAccessControl.php");
require_once(__DIR__ . DIRECTORY_SEPARATOR . "TeacherAccessControl.php");


class AccessControlFactory
{
    public static function create(string $role): AccessControlInterface
    {
        return match (strtolower($role)) {
            'device' => new DeviceAccessControl(),
            'parent' => new ParentAccessControl(),
            'student' => new StudentAccessControl(),
            'teacher' => new TeacherAccessControl(),
            default => throw new InvalidArgumentException("Unknown role: $role"),
        };
    }
}
