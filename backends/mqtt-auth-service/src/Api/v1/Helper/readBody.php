<?php
function getBody()
{
	return file_get_contents("php://input");
}

function getJSONBody()
{
	return json_decode(getBody(), true);
}
