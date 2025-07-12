<?php
// ============================================================================
// File:    Database.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

class Database
{
	public $pdo = NULL;
	public $private_salt;
	private static $instance = NULL;

	private function __construct()
	{
		$host = getenv('MYSQL_HOST');
		$port = getenv('MYSQL_PORT');
		$db   = getenv('MYSQL_DATABASE');
		$user = getenv('MYSQL_USER');
		$pass = getenv('MYSQL_PASSWORD');
		$this->private_salt = getenv('PRIVATE_SALT');

		try {
			$this->pdo = new PDO("mysql:dbname=$db;host=$host;port:$port;charset=utf8mb4", $user, $pass);
			$this->pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_SILENT);
		} catch (PDOException $e) {
			http_response_code(500);
			exit;
		}
	}

	function __destruct()
	{
		$this->pdo = null;
	}

	public static function getInstance()
	{
		if (self::$instance === NULL) {
			self::$instance = new Database();
		}

		return self::$instance;
	}
}
