<?php
// ============================================================================
// File:    ClasslistManager.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(HELPER . "Database.php");
require_once(MODEL . "ClasslistModel.php");

class ClasslistManager
{

	private static function isIPBlocked($ip_address)
	{
		$sql = "SELECT MAX(attempt_time) as result FROM login_log WHERE ip_address = :ip_address and login_status = 'blocked' and attempt_time > CURRENT_TIMESTAMP";
		$pdo = Database::getInstance()->pdo;
		$stmt = $pdo->prepare($sql);
		$stmt->execute([":ip_address" => $ip_address]);

		return ($stmt->fetch(PDO::FETCH_ASSOC)["result"] ?? null);
	}

	private static function isUsernameBlocked($username)
	{
		$sql = "SELECT MAX(attempt_time) as result FROM login_log WHERE username = :username and login_status = 'blocked' and attempt_time > CURRENT_TIMESTAMP";
		$pdo = Database::getInstance()->pdo;
		$stmt = $pdo->prepare($sql);
		$stmt->execute([":username" => $username]);

		return ($stmt->fetch(PDO::FETCH_ASSOC)["result"] ?? null);
	}

	public static function createLog($username, $login_status)
	{
		$sql = "INSERT INTO login_log (username, login_status, ip_address, user_agent) VALUES (:username, :login_status, :ip_address, :user_agent)";
		$pdo = Database::getInstance()->pdo;
		$stmt = $pdo->prepare($sql);
		$stmt->execute([
			":username" => $username,
			":login_status" => $login_status,
			":ip_address" => getUserIP(),
			":user_agent" => getUserAgent(),
		]);
	}

	public static function blockUser($username, $ip_address) {}

	public static function getBlockExpiryTime($username)
	{
		$time1 = self::isIPBlocked(getUserIP());
		$time2 = self::isUsernameBlocked($username);

		if ($time1 == NULL)
			return $time2;
		if ($time2 == NULL)
			return $time1;
		return max($time1, $time2);
	}

	public static function isUserBlocked($username)
	{
		return (self::getBlockExpiryTime($username) != NULL);
	}
}
