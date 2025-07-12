<?php
// ============================================================================
// File:    TasklistContentModel.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

class TasklistContentModel
{
   public int $id;
   public int $priority;
   public int $tasklist_id;
   public int $task_id;
   public timestamp $createdAt;
   public timestamp $updatedAt;
   public timestamp $deletedAt;
}
