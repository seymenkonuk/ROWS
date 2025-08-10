<?php
// ============================================================================
// File:    DeviceAccessControl.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(__DIR__ . DIRECTORY_SEPARATOR . "BaseAccessControl.php");


abstract class DeviceAccessControl extends BaseAccessControl
{
    protected function getReadTemplates(): array
    {
        return [
            'device/{{device_code}}/changedStudent',
            'student/{{student_code}}/playTask',
            'class/{{class_code}}/playTask'
        ];
    }

    protected function getWriteTemplates(): array
    {
        return [
            'student/{{student_code}}/finishTask',
            'class/{{class_code}}/finishTask',
        ];
    }
}
