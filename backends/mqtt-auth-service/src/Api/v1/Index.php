<?php

require_once("Globals.init.php");
require_once(CORE . "Application.php");

$ViewData = [];
ob_start();
new Application();
