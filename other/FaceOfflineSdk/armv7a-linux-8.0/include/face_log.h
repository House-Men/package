/***************************************************************************
 *
 * Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

/**
 * @file    face_log.h
 * @author  taotianran<taotianran@baidu.com>
 * @date    2020-05-26 15:05
 * @brief   日志打印宏定义
 */

#ifndef INCLUDE_FACE_LOG_H
#define INCLUDE_FACE_LOG_H
#pragma once

#include <stdio.h>

#define LOGI(fmt, ...) \
    do { \
        printf("face-demo ---info--- " fmt "\n", ##__VA_ARGS__); \
    } while (0)

#define LOGE(fmt, ...) \
    do { \
        printf("face-demo ---error--- " fmt "\n", ##__VA_ARGS__); \
    } while (0)

#endif
