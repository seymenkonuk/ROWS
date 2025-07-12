<?php
// ============================================================================
// File:    DeviceModel.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

class DeviceModel
{
   public int $id;
   public string $code;
   public int $owner_id;
   public int $user_id;
   public string $password;
   public string $salt;
   public timestamp $createdAt;
   public timestamp $updatedAt;
   public timestamp $deletedAt;
}
