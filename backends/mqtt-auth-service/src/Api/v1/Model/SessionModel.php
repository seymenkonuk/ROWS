<?php
// ============================================================================
// File:    SessionModel.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

class SessionModel
{
   public int $id;
   public string $token;
   public string $user_code;
   public string $user_type;
   public string $ip_address;
   public string $user_agent;
   public string $device_type;
   public timestamp $expiredAt;
   public bool $is_active;
   public timestamp $login_time;
   public timestamp $logout_time;
}
