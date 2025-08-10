<?php
// ============================================================================
// File:    regex.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

// 0-9 İçerebilir
// En Az 5, En Fazla 20 Karakter
const VERSION_REGEX_ERROR = "Bu alan yazılım versiyonu formatında (x.y.z) olmalı!";
const VERSION_REGEX_RULE = "/^\d+\.\d+\.\d+$/";
const VERSION_MIN_LEN = 5;
const VERSION_MAX_LEN = 20;
