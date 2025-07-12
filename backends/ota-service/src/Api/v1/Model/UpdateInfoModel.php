<?php
// ============================================================================
// File:    UpdateInfoModel.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

class UpdateInfoModel
{
   public int $id;
   public string $version;
   public string $firmware_path;
   public timestamp $createdAt;
   public timestamp $updatedAt;
   public timestamp $deletedAt;
}
