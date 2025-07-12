// ============================================================================
// File:    rows_api.h
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

#ifndef ROWS_API_H
#define ROWS_API_H

// DEFINES
#define SERVER_DOMAIN "<your-domain>"

#define API_PROTOCOL "https://"
#define API_HOST SERVER_DOMAIN
#define API_PORT "3001"

#define API_BASE_URL API_PROTOCOL API_HOST ":" API_PORT "/api/v1"

#define API_GET_ACTIVE_STUDENT_CODE_PATH "/device/getActiveStudentCode"
#define API_GET_MY_CLASSES_PATH "/device/getMyClasses"
#define API_POST_FINISH_TASK_PATH "/device/finishTask"

#define API_GET_ACTIVE_STUDENT_CODE_URL API_BASE_URL API_GET_ACTIVE_STUDENT_CODE_PATH
#define API_GET_MY_CLASSES_URL API_BASE_URL API_GET_MY_CLASSES_PATH
#define API_POST_FINISH_TASK_URL API_BASE_URL API_POST_FINISH_TASK_PATH

#endif // ROWS_API_H
