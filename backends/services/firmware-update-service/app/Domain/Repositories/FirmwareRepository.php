<?php
// ============================================================================
// File:    FirmwareRepository.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

namespace App\Domain\Repositories;


use App\Domain\Models\Firmware;

use Seymenkonuk\Framework\Repository;


class FirmwareRepository extends Repository
{
    protected string $table = "firmware";
    protected string $primaryKey = "version";
    protected string $model = Firmware::class;

    public function getFirmware(string $version): ?Firmware
    {
        /** @var ?Firmware $firmware */
        $firmware = $this->find($version) ?: null;
        return $firmware;
    }

    public function getNextFirmware(string $version): ?Firmware
    {
        $firmware = $this->getFirmware($version);

        // Versiyon Bulunamadı
        if ($firmware === null) {
            return null;
        }

        // Yeni Versiyon Mevcut Değil
        if ($firmware->next_version === null) {
            return null;
        }

        return $this->getFirmware($firmware->next_version);
    }
}
