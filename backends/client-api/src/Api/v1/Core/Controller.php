<?php

require_once(CORE . "View.php");

class Controller
{
	protected $view;

	public function View($view_name)
	{
		$this->view = new View($view_name);
		return $this->view->Render();
	}

	public function JSON($json_data)
	{
		ob_get_clean();
		ob_start();
		header('Content-Type: application/json');
		echo json_encode($json_data, JSON_UNESCAPED_UNICODE);
		return ob_get_clean();
	}

	public function SendBadRequestError($errorArray = [], $errorMessage = "Bad Request!")
	{
		header("HTTP/1.1 400 Bad Request");
		return $this->JSON([
			"success" => false,
			"message" => $errorMessage,
			"error" => $errorArray
		]);
	}

	public function SendNotImplementedError()
	{
		header("HTTP/1.1 500 Internal Server Error");
		return $this->JSON([
			"success" => false,
			"message" => "Bu endpoint henüz uygulanmadı!",
			"error" => []
		]);
	}

	public function SendAuthenticationRequiredError()
	{
		header("HTTP/1.1 401 Unauthorized");
		return $this->JSON([
			"success" => false,
			"message" => "Kimlik doğrulaması gerekli!",
			"error" => []
		]);
	}

	public function SendAuthorizationRequiredError()
	{
		header("HTTP/1.1 403 Forbidden");
		return $this->JSON([
			"success" => false,
			"message" => "Bu işlemi gerçekleştirme yetkiniz yok!",
			"error" => []
		]);
	}

	public function SendSuccessData($message, $data)
	{
		$result = [
			"success" => true,
			"message" => $message,
		];
		if ($data != NULL) {
			$result["data"] = $data;
		}
		return $this->JSON($result);
	}

	public function Redirect($path)
	{
		header("Location: " . $path);
		exit;
	}
}
