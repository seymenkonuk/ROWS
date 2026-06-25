<?php
// ============================================================================
// File:    Firmware.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

namespace App\Domain\Models;


class Firmware
{
    public int      $id;
    public string   $version;
    public string   $path;
    public ?string  $next_version;
    public string   $created_at;
    public ?string  $updated_at;
}
