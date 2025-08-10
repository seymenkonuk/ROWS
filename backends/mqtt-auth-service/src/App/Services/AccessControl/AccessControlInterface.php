<?php
// ============================================================================
// File:    AccessControlInterface.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

interface AccessControlInterface
{
    public function hasAccess(string $username, string $topic, int $acc): bool;
}
