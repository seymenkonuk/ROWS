<?php
// ============================================================================
// File:    TaskModel.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

class TaskModel
{
   public int $id;
   public string $code;
   public string $title;
   public string $description;
   public string $map_data;
   public int $teacher_id;
   public bool $is_public;
   public int $version;
   public int $difficulty;
   public $created_at;
   public $updated_at;
   public $deleted_at;
}
