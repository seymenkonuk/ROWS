<?php
// ============================================================================
// File:    ScoreboardModel.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

class ScoreboardModel
{
   public int $id;
   public int $tasklist_content_id;
   public int $student_id;
   public int $result;
   public timestamp $createdAt;
   public timestamp $updatedAt;
   public timestamp $deletedAt;
}
