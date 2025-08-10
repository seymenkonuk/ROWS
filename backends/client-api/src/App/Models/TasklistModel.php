<?php
// ============================================================================
// File:    TasklistModel.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

class TasklistModel
{
   public int $id;
   public string $code;
   public int $teacher_id;
   public int $class_id;
   public string $title;
   public string $description;
   public bool $is_everyone;
   public $deadline;
   public $created_at;
   public $updated_at;
   public $deleted_at;
}
