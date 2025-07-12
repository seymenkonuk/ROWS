<?php
// ============================================================================
// File:    TaskstatusModel.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

class TaskstatusModel
{
   public int $tasklist_content_id;
   public int $student_id;
   public string $response;
   public string $status;
   public timestamp $completion_time;
   public timestamp $createdAt;
   public timestamp $updatedAt;
   public timestamp $deletedAt;
}
