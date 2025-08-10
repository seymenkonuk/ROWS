<?php
// ============================================================================
// File:    UpdateInfoRepository.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Repository.php");

require_once(MODEL . "UpdateInfoModel.php");

class UpdateInfoRepository extends Repository
{
    private function getVersionInfo(string $version)
    {
        $sql = "SELECT * FROM update_info WHERE version = :version";
        $stmt = $this->pdo->prepare($sql);
        $stmt->execute([":version" => $version]);

        return $stmt->fetch(PDO::FETCH_ASSOC) ?: [];
    }

    private function getVersionId(string $version)
    {
        return $this->getVersionInfo($version)["id"] ?? NULL;
    }

    private function getNextVersionInfo(string $version)
    {
        $versionId = $this->getVersionId($version);

        if ($versionId == NULL) {
            return NULL;
        }

        $sql = "SELECT * FROM update_info WHERE id > :id ORDER BY id ASC LIMIT 1";
        $stmt = $this->pdo->prepare($sql);
        $stmt->execute([":id" => $versionId]);

        return $stmt->fetch(PDO::FETCH_ASSOC) ?: [];
    }

    public function getNextVersion(string $version)
    {
        return $this->getNextVersionInfo($version)["version"] ?? NULL;
    }

    public function getNextVersionId(string $version)
    {
        return $this->getNextVersionInfo($version)["id"] ?? NULL;
    }

    public function getNextVersionPath(string $version)
    {
        return $this->getNextVersionInfo($version)["firmware_path"] ?? NULL;
    }
}
