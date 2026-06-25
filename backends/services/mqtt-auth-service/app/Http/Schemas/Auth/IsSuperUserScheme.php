<?php
// ============================================================================
// File:    IsSuperUserScheme.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

namespace App\Http\Schemas\Auth;


use Seymenkonuk\Framework\Schema;

use Seymenkonuk\Validator\Validator\ObjectValidator;


class IsSuperUserScheme extends Schema
{
    public function body(): ObjectValidator
    {
        return $this->validator->object()->schema([
            "username" => $this->validator->field()
                ->string()
                ->required(),
        ]);
    }
}
