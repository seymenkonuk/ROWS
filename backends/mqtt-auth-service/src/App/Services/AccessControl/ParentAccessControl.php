<?php
// ============================================================================
// File:    ParentAccessControl.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(__DIR__ . DIRECTORY_SEPARATOR . "BaseAccessControl.php");


abstract class ParentAccessControl extends BaseAccessControl
{
    protected function getReadTemplates(): array
    {
        return [
            'student/{{student_code}}/finishTask',
            'class/{{class_code}}/finishTask',
        ];
    }

    protected function getWriteTemplates(): array
    {
        return [
            'device/{{device_code}}/changedStudent',
        ];
    }
}
