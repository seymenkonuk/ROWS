<?php
// ============================================================================
// File:    ClassModel.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

class ClassModel
{
   public int $id;
   public string $code;
   public string $title;
   public string $description;
   public int $teacher_id;
   public timestamp $createdAt;
   public timestamp $updatedAt;
   public timestamp $deletedAt;
}
