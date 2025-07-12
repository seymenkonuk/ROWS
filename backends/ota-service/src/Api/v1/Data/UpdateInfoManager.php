<?php
// ============================================================================
// File:    UpdateInfoManager.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(HELPER . "Database.php");
require_once(MODEL . "UpdateInfoModel.php");

class UpdateInfoManager
{

    private static function getVersionInfo(string $version)
    {
        $sql = "SELECT * FROM update_info WHERE version = :version";
        $pdo = Database::getInstance()->pdo;
        $stmt = $pdo->prepare($sql);
        $stmt->execute([":version" => $version]);

        return $stmt->fetch(PDO::FETCH_ASSOC) ?: [];
    }

    private static function getVersionId(string $version)
    {
        return self::getVersionInfo($version)["id"] ?? NULL;
    }

    private static function getNextVersionInfo(string $version)
    {
        $versionId = self::getVersionId($version);

        if ($versionId == NULL) {
            return NULL;
        }

        $sql = "SELECT * FROM update_info WHERE id > :id ORDER BY id ASC LIMIT 1";
        $pdo = Database::getInstance()->pdo;
        $stmt = $pdo->prepare($sql);
        $stmt->execute([":id" => $versionId]);

        return $stmt->fetch(PDO::FETCH_ASSOC) ?: [];
    }

    public static function getNextVersion(string $version)
    {
        return self::getNextVersionInfo($version)["version"] ?? NULL;
    }

    public static function getNextVersionId(string $version)
    {
        return self::getNextVersionInfo($version)["id"] ?? NULL;
    }

    public static function getNextVersionPath(string $version)
    {
        return self::getNextVersionInfo($version)["firmware_path"] ?? NULL;
    }
}
