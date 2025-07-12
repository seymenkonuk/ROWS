<?php
// ============================================================================
// File:    SessionManager.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(HELPER . "Database.php");
require_once(MODEL . "SessionModel.php");

class SessionManager
{
	private static function createUniqueCode()
	{
		do {
			$code = generateToken(32);
		} while (self::hasSession($code));

		return $code;
	}

	public static function getSession($code)
	{
		$sql = "SELECT * FROM session WHERE code = :code";
		$pdo = Database::getInstance()->pdo;
		$stmt = $pdo->prepare($sql);
		$stmt->execute([":code" => $code]);

		return $stmt->fetch(PDO::FETCH_ASSOC);
	}

	public static function hasSession($code)
	{
		return (self::getSession($code) != NULL);
	}

	public static function createSession($account_id)
	{
		$sql = "INSERT INTO session (code, account_id) VALUES (:code, :account_id)";
		$pdo = Database::getInstance()->pdo;
		$stmt = $pdo->prepare($sql);
		$stmt->execute([
			":code" => createUniqueCode(),
			":account_id" => $account_id
		]);
	}

	public static function deleteSession($code)
	{
		$sql = "DELETE FROM session WHERE code = :code";
		$pdo = Database::getInstance()->pdo;
		$stmt = $pdo->prepare($sql);
		$stmt->execute([":code" => $code]);

		return ($stmt->rowCount() > 0);
	}

	public static function deleteMySessions($account_id, $code)
	{
		$sql = "DELETE FROM session WHERE account_id = :account_id and code != :code";
		$pdo = Database::getInstance()->pdo;
		$stmt = $pdo->prepare($sql);
		$stmt->execute([":account_id" => $account_id, ":code" => $code]);

		return ($stmt->rowCount());
	}

	public static function getMySessions($account_id)
	{
		$sql = "SELECT * FROM session WHERE account_id = :account_id";
		$pdo = Database::getInstance()->pdo;
		$stmt = $pdo->prepare($sql);
		$stmt->execute([":account_id" => $account_id]);

		while ($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
			yield $row;
		}
	}
}
