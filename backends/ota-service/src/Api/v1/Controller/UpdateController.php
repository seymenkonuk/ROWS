<?php
// ============================================================================
// File:    UpdateController.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(CORE . "Controller.php");

require_once(HELPER . "readBody.php");

require_once(DATA . "UpdateInfoManager.php");

class UpdateController extends Controller
{

	// POST
	public function GetLatestVersion()
	{
		$version = getBody();
		$nextVersion = UpdateInfoManager::getNextVersion($version) ?? "";
		header("Content-Type: plain/text");
		return $nextVersion;
	}

	// POST
	public function Download()
	{
		$version = getBody();
		$filepath = UpdateInfoManager::getNextVersionPath($version) ?? "";
		// Already Up to Date!
		if ($filepath == "") {
			return "";
		}
		$filepath = ROOT . ".." . DIRECTORY_SEPARATOR . "firmwares" . DIRECTORY_SEPARATOR .  $filepath;
		header('Content-Type: application/octet-stream');
		header('Content-Length: ' . filesize($filepath));
		header('Content-Disposition: attachment; filename="firmware.bin"');
		// return readfile($filepath);
		return file_get_contents($filepath);
	}
}
