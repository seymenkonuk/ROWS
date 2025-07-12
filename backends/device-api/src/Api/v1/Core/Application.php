<?php

class Application
{

	protected $controller = "Home";
	protected $action = "Index";
	protected $parameters = [];

	public function __construct()
	{
		// Parse Get Parameters
		$this->ParseRequest();

		// Controller Not Found
		if (!file_exists(CONTROLLER . $this->controller . ".php")) {
			http_response_code(500);
			exit;
		}

		// Include Controller
		require_once(CONTROLLER . $this->controller . ".php");
		$this->controller = new $this->controller;

		// Action Not Found
		if (!method_exists($this->controller, $this->action)) {
			http_response_code(500);
			exit;
		}

		// Call Action
		echo call_user_func_array([$this->controller, $this->action], $this->parameters);
	}

	protected function ParseRequest()
	{
		// Direct index.php Access
		if (isset($_SERVER["REQUEST_URI"])) {
			$url = $_SERVER["REQUEST_URI"];
			$parsed_url = parse_url($url);
			$clean_url = isset($parsed_url['path']) ? $parsed_url['path'] : $url;
			$script_name = $_SERVER["SCRIPT_NAME"] ?? "/index.php";

			if ($clean_url == $script_name || $clean_url == dirname($script_name) || $clean_url == dirname($script_name) . "/") {
				http_response_code(404);
				exit;
			}
		}

		// Parse; Controller, Action, Parameters
		$params = explode("&", $_SERVER["QUERY_STRING"] ?? "");
		$this->controller = (explode("=", $params[0])[1] ?? $this->controller) . "Controller";
		$this->action = (explode("=", $params[1])[1] ?? $this->action);
		$this->parameters = array_values($_GET["parameters"] ?? $this->parameters);
	}
}
