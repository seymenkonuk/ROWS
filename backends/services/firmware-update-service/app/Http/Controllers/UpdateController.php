<?php
// ============================================================================
// File:    UpdateController.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

namespace App\Http\Controllers;


use App\Domain\Services\FirmwareService;

use App\Http\Schemas\Update\DownloadScheme;
use App\Http\Schemas\Update\GetNewVersionScheme;

use Seymenkonuk\Framework\Controller;
use Seymenkonuk\Framework\Response;
use Seymenkonuk\Framework\Request;

use Seymenkonuk\Framework\Attribute\Prefix;
use Seymenkonuk\Framework\Attribute\Schema;

use Seymenkonuk\Framework\Attribute\Route\Get;


#[Prefix("/api/v1/update")]
class UpdateController extends Controller
{
    public function __construct(
        public Request $request,
        public Response $response,
        public FirmwareService $service,
    ) {}

    #[Get("version")]
    #[Schema(GetNewVersionScheme::class)]
    public function GetNewVersion(): Response
    {
        /** @var string $version */
        $version = $this->request->query("version");
        $nextVersion = $this->service->getNextVersion($version);

        // Yeni Güncelleme Yok
        if ($nextVersion === null) {
            return $this->response->notFound();
        }

        return $this->response->text($nextVersion);
    }

    #[Get("download")]
    #[Schema(DownloadScheme::class)]
    public function Download(): Response
    {
        /** @var string $version */
        $version = $this->request->query("version");
        $filepath = $this->service->getNextVersionFirmwarePath($version);

        // Yeni Güncelleme Yok
        if ($filepath === null) {
            return $this->response->notFound();
        }

        return $this->response->file($filepath, "application/octet-stream");
    }
}
