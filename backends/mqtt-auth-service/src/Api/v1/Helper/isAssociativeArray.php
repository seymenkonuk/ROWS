<?php
function isAssociativeArray($array)
{
	if (empty($array))
		return false;
	return array_keys($array) !== range(0, count($array) - 1);
}
