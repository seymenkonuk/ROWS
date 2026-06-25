<?php
// ============================================================================
// File:    FirmwareService.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

namespace App\Domain\Services;


use App\Domain\Repositories\FirmwareRepository;

use App\Support\Helpers\PathHelper;


class FirmwareService
{
    public function __construct(
        private FirmwareRepository $firmwareRepository,
    ) {}

    public function getNextVersion(string $version): ?string
    {
        $firmware = $this->firmwareRepository->getFirmware($version);

        // Versiyon Bulunamadı
        if ($firmware === null) {
            return null;
        }

        return $firmware->next_version;
    }

    public function getNextVersionFirmwarePath(string $version): ?string
    {
        $firmware = $this->firmwareRepository->getNextFirmware($version);

        // Versiyon Bulunamadı veya Yeni Versiyon Yok
        if ($firmware === null) {
            return null;
        }

        $filepath = PathHelper::privateStorage() . DIRECTORY_SEPARATOR . $firmware->path;
        return $filepath;
    }
}
