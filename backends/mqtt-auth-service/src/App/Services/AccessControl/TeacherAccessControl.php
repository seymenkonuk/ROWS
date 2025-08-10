<?php
// ============================================================================
// File:    TeacherAccessControl.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(__DIR__ . DIRECTORY_SEPARATOR . "BaseAccessControl.php");


abstract class TeacherAccessControl extends BaseAccessControl
{
    protected function getReadTemplates(): array
    {
        return [
            'class/{{class_code}}/finishTask',
        ];
    }

    protected function getWriteTemplates(): array
    {
        return [
            'class/{{class_code}}/playTask',
        ];
    }
}
