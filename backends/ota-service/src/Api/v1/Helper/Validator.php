<?php
// ============================================================================
// File:    Validator.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(HELPER . "isAssociativeArray.php");

// ERROR MESSAGES (TURKISH)
const ERROR_MESSAGES = [
	// Integer errors
	'int_required' => "Bu alan bir tamsayı (int) olmalı!",
	'int_value' => "Değer {number} olmalı!",
	'int_min' => "Değer en az {number} olmalı!",
	'int_max' => "Değer en fazla {number} olmalı!",

	// Double errors
	'double_required' => "Bu alan bir ondalıklı sayı (double) olmalı!",
	'double_value' => "Değer {number} olmalı!",
	'double_min' => "Değer en az {number} olmalı!",
	'double_max' => "Değer en fazla {number} olmalı!",

	// Boolean errors
	'bool_required' => "Bu alan bir boolean (true/false) olmalı!",

	// String errors
	'string_required' => "Bu alan bir metin (string) olmalı!",
	'string_enum' => "Bu alan sadece {enum} değerlerinden birini alabilir.",
	'string_length' => "Bu alan {length} karakter olmalı!",
	'string_min_length' => "Bu alan en az {length} karakter olmalı!",
	'string_max_length' => "Bu alan en fazla {length} karakter olmalı!",

	// DateTime errors
	'datetime_required' => "Bu alan bir datetime (Y-m-d H:i:s) olmalı!",
	'datetime_min' => "Bu alan {datetime} tarihinden sonraki bir tarih olmalı!",

	// Array errors
	'array_required' => "Bu alan bir liste (array) olmalı!",
	'array_count' => "Bu liste {count} eleman içermelidir!",
	'array_min_count' => "Bu liste en az {count} eleman içermelidir!",
	'array_max_count' => "Bu liste en fazla {count} eleman içermelidir!",
	'array_item_validation' => "Bu listedeki her alan belirtilen kurala uymalı: {error_message}",

	// Required field error
	'required' => "Bu alan boş bırakılamaz!",

	// Generic error
	'invalid' => "Bu alan kabul edilmiyor!",
];

// ERROR MESSAGES (ENGLISH)

// const ERROR_MESSAGES = [
// 	// Integer errors
// 	'int_required' => "This field must be an integer!",
// 	'int_value' => "Value must be {number}!",
// 	'int_min' => "Value must be at least {number}!",
// 	'int_max' => "Value must be at most {number}!",

// 	// Double errors
// 	'double_required' => "This field must be a floating point number (double)!",
// 	'double_value' => "Value must be {number}!",
// 	'double_min' => "Value must be at least {number}!",
// 	'double_max' => "Value must be at most {number}!",

// 	// Boolean errors
// 	'bool_required' => "This field must be a boolean (true/false)!",

// 	// String errors
// 	'string_required' => "This field must be a string!",
// 	'string_enum' => "This field can only accept one of the following values: {enum}.",
// 	'string_length' => "This field must be {length} characters long!",
// 	'string_min_length' => "This field must be at least {length} characters long!",
// 	'string_max_length' => "This field must be at most {length} characters long!",

// 	// DateTime errors
// 	'datetime_required' => "This field must be a datetime (Y-m-d H:i:s)!",
// 	'datetime_min' => "This field must be a date after {datetime}!",

// 	// Array errors
// 	'array_required' => "This field must be an array!",
// 	'array_count' => "This list must contain {count} items!",
// 	'array_min_count' => "This list must contain at least {count} items!",
// 	'array_max_count' => "This list must contain at most {count} items!",
// 	'array_item_validation' => "Each item in this list must conform to the rule: {error_message}",

// 	// Required field error
// 	'required' => "This field cannot be empty!",

// 	// Generic error
// 	'invalid' => "This field is not allowed!",
// ];

class IntRule
{
	public $min_value = PHP_INT_MIN;
	public $max_value = PHP_INT_MAX;
}

class DoubleRule
{
	public $min_value = PHP_FLOAT_MIN;
	public $max_value = PHP_FLOAT_MAX;
}

class StrRule
{
	public $min_length = 0;
	public $max_length = 255;
	public $allow_values = [];	// if empty it can take any value
	public $regex_rules = [];	// if empty it can take any value
}

class DateTimeRule
{
	public $referenceDate = null;
}

function isValidDateTime(string $dateTimeString): bool
{
	$date = DateTime::createFromFormat('Y-m-d H:i:s', $dateTimeString);
	$errors = DateTime::getLastErrors();
	return $date && (!$errors || ($errors['warning_count'] === 0 && $errors['error_count'] === 0));
}

function isAfterDate(string $dateTimeString, DateTime $referenceDate): bool
{
	$dateToCheck = DateTime::createFromFormat('Y-m-d H:i:s', $dateTimeString);
	return $dateToCheck > $referenceDate;
}

function formatText(string $text, array $keys, array $values): string
{
	return str_replace($keys, $values, $text);
}

class Validator
{
	private string $type;			// int, double, str, bool, datetime, special
	private bool $is_require;		// require field, optional field

	private bool $is_arr;			// array<$type>
	private int $array_min_length;
	private int $array_max_length;

	private IntRule $intRule;
	private DoubleRule $doubleRule;
	private StrRule $strRule;
	private DateTimeRule $dateTimeRule;

	private $special_checker;	// is a function -> ($value) => { return "error_message"; }

	// Static Factory method
	public static function create()
	{
		return new self();
	}

	// Constructor
	private function __construct()
	{
		$this->is_arr = false;
		$this->array_min_length = 0;
		$this->array_max_length = 0;
		$this->intRule = new IntRule();
		$this->doubleRule = new DoubleRule();
		$this->strRule = new StrRule();
		$this->dateTimeRule = new DateTimeRule();
		$this->special_checker = function ($value) {
			return "";
		};
		$this->str()->optional();
	}

	// Types
	public function int($min = PHP_INT_MIN, $max = PHP_INT_MAX)
	{
		$this->type = "int";
		$this->intRule->min_value = $min;
		$this->intRule->max_value = $max;
		return $this;
	}
	public function double($min = PHP_FLOAT_MIN, $max = PHP_FLOAT_MAX)
	{
		$this->type = "double";
		$this->doubleRule->min_value = $min;
		$this->doubleRule->max_value = $max;
		return $this;
	}
	public function str($min = 0, $max = 255)
	{
		$this->type = "str";
		$this->strRule->min_length = $min;
		$this->strRule->max_length = $max;
		return $this;
	}
	public function bool()
	{
		$this->type = "bool";
		return $this;
	}
	public function special()
	{
		$this->type = "special";
		return $this;
	}
	public function datetime(DateTime $referenceDate = null)
	{
		$this->type = "datetime";
		if ($referenceDate === null) {
			$referenceDate = new DateTime('@0');
		}
		$this->dateTimeRule->referenceDate = $referenceDate;
		return $this;
	}

	public function array($min = 0, $max = 0)
	{
		$this->is_arr = true;
		$this->array_min_length = $min;
		$this->array_max_length = $max;
		return $this;
	}

	// Require / Optional
	public function require()
	{
		$this->is_require = true;
		return $this;
	}
	public function optional()
	{
		$this->is_require = false;
		return $this;
	}

	// Insert Allow Value
	// if array is empty then text can be anything
	public function insertAllowValue($value)
	{
		$this->strRule->allow_values[] = $value;
		return $this;
	}

	// Insert Regex Rule
	// if array is empty then text can be anything
	public function insertRegexRule($rule_error, $regex)
	{
		$this->strRule->regex_rules[] = [
			"error" => $rule_error,
			"regex" => $regex
		];
		return $this;
	}

	// Special Checker
	public function editSpecialChecker($special_checker)
	{
		$this->special_checker = $special_checker;
		return $this;
	}

	// Check Value
	private function check_int($value)
	{
		if (!is_int($value))
			return formatText(ERROR_MESSAGES["int_required"], [], []);
		if ($this->intRule->min_value == $this->intRule->max_value && $value != $this->intRule->min_value)
			return formatText(ERROR_MESSAGES["int_value"], ["{number}"], [$this->intRule->min_value]);
		if ($value < $this->intRule->min_value)
			return formatText(ERROR_MESSAGES["int_min"], ["{number}"], [$this->intRule->min_value]);
		if ($value > $this->intRule->max_value)
			return formatText(ERROR_MESSAGES["int_max"], ["{number}"], [$this->intRule->max_value]);
		return ($this->special_checker)($value);
	}

	private function check_double($value)
	{
		if (!is_double($value))
			return formatText(ERROR_MESSAGES["double_required"], [], []);
		if ($this->doubleRule->min_value == $this->doubleRule->max_value && $value != $this->doubleRule->min_value)
			return formatText(ERROR_MESSAGES["double_value"], ["{number}"], [$this->doubleRule->min_value]);
		if ($value < $this->doubleRule->min_value)
			return formatText(ERROR_MESSAGES["double_min"], ["{number}"], [$this->doubleRule->min_value]);
		if ($value > $this->doubleRule->max_value)
			return formatText(ERROR_MESSAGES["double_max"], ["{number}"], [$this->doubleRule->max_value]);
		return ($this->special_checker)($value);
	}

	private function check_bool($value)
	{
		if (!is_bool($value))
			return formatText(ERROR_MESSAGES["bool_required"], [], []);
		return ($this->special_checker)($value);
	}

	private function check_str($value)
	{
		if (!is_string($value))
			return formatText(ERROR_MESSAGES["string_required"], [], []);
		if (!empty($this->strRule->allow_values) && !in_array($value, $this->strRule->allow_values))
			return formatText(ERROR_MESSAGES["string_enum"], ["{enum}"], [json_encode($this->strRule->allow_values, JSON_UNESCAPED_UNICODE)]);
		foreach ($this->strRule->regex_rules as $regex_rule) {
			if (preg_match($regex_rule["regex"], $value) !== 1) {
				return $regex_rule["error"];
			}
		}
		if ($this->strRule->min_length == $this->strRule->max_length && mb_strlen($value) != $this->strRule->min_length)
			return formatText(ERROR_MESSAGES["string_length"], ["{length}"], [$this->strRule->min_length]);
		if (mb_strlen($value) < $this->strRule->min_length)
			return formatText(ERROR_MESSAGES["string_min_length"], ["{length}"], [$this->strRule->min_length]);
		if (mb_strlen($value) > $this->strRule->max_length)
			return formatText(ERROR_MESSAGES["string_max_length"], ["{length}"], [$this->strRule->max_length]);
		return ($this->special_checker)($value);
	}

	private function check_datetime($value)
	{
		if (!isValidDateTime($value))
			return formatText(ERROR_MESSAGES["datetime_required"], [], []);
		if (!isAfterDate($value, $this->dateTimeRule->referenceDate))
			return formatText(ERROR_MESSAGES["datetime_min"], ["{datetime}"], [$this->dateTimeRule->referenceDate->format('Y-m-d H:i:s')]);
		return ($this->special_checker)($value);
	}

	private function check_list($value)
	{
		if (!is_array($value))
			return formatText(ERROR_MESSAGES["array_required"], [], []);
		if (isAssociativeArray($value))
			return formatText(ERROR_MESSAGES["array_required"], [], []);
		if ($this->array_min_length == $this->array_max_length && count($value) != $this->array_min_length)
			return formatText(ERROR_MESSAGES["array_count"], ["{count}"], [$this->array_min_length]);
		if (count($value) < $this->array_min_length)
			return formatText(ERROR_MESSAGES["array_min_count"], ["{count}"], [$this->array_min_length]);
		if (count($value) > $this->array_max_length && $this->array_max_length != 0)
			return formatText(ERROR_MESSAGES["array_max_count"], ["{count}"], [$this->array_max_length]);
		foreach ($value as $val) {
			$errorMessage = $this->check_value($val);
			if ($errorMessage != "") {
				return formatText(ERROR_MESSAGES["array_item_validation"], ["{error_message}"], [$errorMessage]);
			}
		}
	}

	private function check_value($value)
	{
		if ($this->type === "int") {
			return $this->check_int($value);
		}
		if ($this->type === "double") {
			return $this->check_double($value);
		}
		if ($this->type === "bool") {
			return $this->check_bool($value);
		}
		if ($this->type === "str") {
			return $this->check_str($value);
		}
		if ($this->type === "datetime") {
			return $this->check_datetime($value);
		}
		return ($this->special_checker)($value);
	}

	public function check($value)
	{
		if ($value === NULL) {
			if ($this->is_require) {
				return formatText(ERROR_MESSAGES["required"], [], []);
			}
			return "";
		}
		if ($this->is_arr) {
			return $this->check_list($value);
		}
		return $this->check_value($value);
	}

	private static function setErrorMessage(&$errorArray, $errorKeys, $errorMessage)
	{
		$tempArray = &$errorArray;
		foreach ($errorKeys as $value) {
			if (!isset($tempArray[$value])) {
				$tempArray[$value] = [];
			}
			$tempArray = &$tempArray[$value];
		}
		$tempArray = $errorMessage;
	}

	private static function validateDataWithError($tempData, $data, &$errorArray, $errorKeys)
	{
		if ($tempData instanceof Validator) {
			$errorMessage = $tempData->check($data);
			if ($errorMessage != "")
				self::setErrorMessage($errorArray, $errorKeys, $errorMessage);
			return;
		}
		// tempData geçerli formatta değil!
		if (!is_array($tempData)) {
			header("HTTP/1.1 500 Internal Server Error");
			exit;
		}
		// Datada Olup, Şablonda Olmayan Varsa Hatalıdır!
		if (is_array($data)) {
			foreach ($data as $key => $value) {
				if (!isset($tempData[$key])) {
					$errorKeys[] = $key;
					self::setErrorMessage($errorArray, $errorKeys, ERROR_MESSAGES["invalid"]);
					array_pop($errorKeys);
				}
			}
		}
		// Şablonda Olup, Datada Olmayan Varsa Hatalıdır
		foreach ($tempData as $key => $value) {
			$errorKeys[] = $key;
			self::validateDataWithError($value, $data[$key] ?? NULL, $errorArray, $errorKeys);
			array_pop($errorKeys);
		}
	}

	public static function validateData($tempData, $data)
	{
		$errorArray = [];
		$tempData = $tempData ?? [];
		$data = $data ?? [];
		self::validateDataWithError($tempData, $data, $errorArray, []);
		return $errorArray;
	}
}
