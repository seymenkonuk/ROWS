<?php
// ============================================================================
// File:    UpdateController.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Controller.php");
require_once(CORE . "Request.php");

require_once(REPOSITORY . "UpdateInfoRepository.php");

const FIRMWARE_PATH = ROOT . ".." . DIRECTORY_SEPARATOR . "Firmwares" . DIRECTORY_SEPARATOR;

class UpdateController extends Controller
{

    public function GetLatestVersion()
    {
        $version = Request::getBody();
        $updateInfoRepository = new UpdateInfoRepository();
        $nextVersion = $updateInfoRepository->getNextVersion($version) ?? "";
        return $this->Content($nextVersion);
    }

    public function Download()
    {
        $version = Request::getBody();
        $updateInfoRepository = new UpdateInfoRepository();
        // Already Up to Date!
        $filepath = $updateInfoRepository->getNextVersionPath($version);
        if ($filepath === NULL) {
            return "";
        }
        // Send Update File
        $filepath = FIRMWARE_PATH . $filepath;
        return $this->StreamFile($filepath, "application/octet-stream");
    }
}
