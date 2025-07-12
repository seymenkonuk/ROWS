<?php

class View
{
	protected $view_file;


	public function __construct($view_file)
	{
		$this->view_file = $view_file;
	}

	public function Render()
	{
		if (file_exists(VIEW . $this->view_file . ".php")) {
			global $ViewData;
			ob_get_clean();
			ob_start();
			include_once(VIEW . $this->view_file . ".php");
			return ob_get_clean();
		} else {
			http_response_code(500);
		}
	}
}
