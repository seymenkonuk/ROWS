<?php
// ============================================================================
// File:    ParentModel.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

class ParentModel
{
   public int $id;
   public string $code;
   public string $username;
   public string $password;
   public string $salt;
   public string $name;
   public string $surname;
   public timestamp $createdAt;
   public timestamp $updatedAt;
   public timestamp $deletedAt;
}
