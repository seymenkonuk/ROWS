<?php
function getUserIP()
{
	if (!empty($_SERVER['HTTP_X_FORWARDED_FOR'])) {
		$ip_list = explode(',', $_SERVER['HTTP_X_FORWARDED_FOR']);
		$ip_address = trim($ip_list[0]);
	} elseif (!empty($_SERVER['HTTP_CLIENT_IP'])) {
		$ip_address = $_SERVER['HTTP_CLIENT_IP'];
	} elseif (!empty($_SERVER['REMOTE_ADDR'])) {
		$ip_address = $_SERVER['REMOTE_ADDR'];
	} else {
		$ip_address = null;
	}

	return filter_var($ip_address, FILTER_VALIDATE_IP) ? $ip_address : null;
}
