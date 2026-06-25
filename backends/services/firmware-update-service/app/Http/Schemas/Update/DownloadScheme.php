<?php
// ============================================================================
// File:    DownloadScheme.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

namespace App\Http\Schemas\Update;


use Config\ValidationConfig;

use Seymenkonuk\Framework\Schema;

use Seymenkonuk\Validator\Validator\ObjectValidator;


class DownloadScheme extends Schema
{
    public function query(): ObjectValidator
    {
        return $this->validator->object()->schema([
            "version" => $this->validator->field()
                ->string()
                ->min(ValidationConfig::VERSION_MIN_LEN)
                ->max(ValidationConfig::VERSION_MIN_LEN)
                ->regex(ValidationConfig::VERSION_REGEX_RULE, ValidationConfig::VERSION_REGEX_ERROR)
                ->required(),
        ]);
    }
}
