/***************************************************************************
 *
 * Copyright (c) 2018 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

 /**
  * @file       ibdface_log.h
  * @author     taotianran<taotianran@baidu.com>
  * @created    2019-01-27 08:58
  * @brief      日志接口
  */

#include "utils/interface/DLL_API.h"
#include "utils/interface/time_tool.h"
#include "framework/interface/ibdface_common.h"

#ifdef __ANDROID__
#include <android/log.h>
#else
#include <stdio.h>
#endif

#ifndef INTERFACE_IBDFACE_LOG_H
#define INTERFACE_IBDFACE_LOG_H
#pragma once

#ifdef __cplusplus
namespace bdface {
    extern "C" {
#endif
        /**
         * @brief   日志类型枚举
         */
        enum BDFaceLogType {
            BDFACE_LOG_TYPE_ERROR = 0,  // 打印错误日志
            BDFACE_LOG_TYPE_VALUE = 1,  // 打印计算值日志
            BDFACE_LOG_TYPE_PERF = 2,   // 打印性能日志
            BDFACE_LOG_TYPE_ALL = 3,    // 打印所有日志
            BDFACE_LOG_TYPE_DEBUG = 4,  // 打印调试日志
        };

        /**
         * @brief   控制日志输出接口
         * @param[in]   const enum BDFaceLogType    type            日志类型
         * @param[in]   const int                   status          日志开启状态
         *                                                          0:关闭; 1:开启
         * @return      enum BDFaceStatusCode       状态码
         */
        DLL_API enum BDFaceStatusCode bdface_manage_log(const enum BDFaceLogType type, const int status);

        /**
         * @brief   获取指定日志类型的开启状态
         * @params[in]  const enum BDFaceLogType    type    日志类型
         * @return      int                         日志开启状态
         *                                          0:关闭; 1:开启
         */
        DLL_API int bdface_get_log_status(const enum BDFaceLogType type);

        /**
         * @brief   执行时间输出类
         */
        struct TimePrinter {
            bdface::TimeTool timer;
            bool is_start;
            int line_num;
            const char* func_name;

            TimePrinter() :
                    is_start(false),
                    line_num(0),
                    func_name(nullptr) {}

            void start(const char* fname, int lnum) {
                func_name = fname;
                line_num = lnum;
                timer.tic();
                is_start = true;
            }

            void stop() {
                if (!is_start) {
                    return;
                }

#ifdef __ANDROID__
                __android_log_print(ANDROID_LOG_INFO, "FaceSDK --perf-- ",
                        "<line %d: %s> %fms \n",
                        line_num, func_name, timer.toc());
#else
                printf("FaceSDK ---perf--- <line %d: %s> %fms \n", line_num,
                        func_name, timer.toc());
#endif
            }

            ~TimePrinter() {
                stop();
            }
        };

#ifdef __ANDROID__
#define LOGVAL(fmt, ...) \
    do { \
        if (bdface::bdface_get_log_status(bdface::BDFaceLogType::BDFACE_LOG_TYPE_VALUE)) \
        { \
            __android_log_print(ANDROID_LOG_INFO, "FaceSDK --value-- ", "<line %d: %s> " \
            fmt, __LINE__, __FUNCTION__, ##__VA_ARGS__); \
        } \
    } while (0)

#define LOGPERF() TimePrinter performance_log##__LINE__;\
    if (bdface::bdface_get_log_status(bdface::BDFaceLogType::BDFACE_LOG_TYPE_PERF)) \
    { \
        performance_log##__LINE__.start(__FUNCTION__, __LINE__); \
    } \

#define LOGERR(fmt, ...) \
    do { \
        if (bdface::bdface_get_log_status(bdface::BDFaceLogType::BDFACE_LOG_TYPE_ERROR)) \
        { \
            __android_log_print(ANDROID_LOG_ERROR, "FaceSDK --error-- ", "<line %d: %s> "\
            fmt, __LINE__, __FUNCTION__, ##__VA_ARGS__); \
        } \
    } while (0)

#define LOGDEBUG(fmt, ...) \
    do { \
        if (bdface::bdface_get_log_status(bdface::BDFaceLogType::BDFACE_LOG_TYPE_DEBUG)) \
        { \
            __android_log_print(ANDROID_LOG_ERROR, "FaceSDK --debug-- ", "<line %d: %s> "\
            fmt, __LINE__, __FUNCTION__, ##__VA_ARGS__); \
        } \
    } while (0)

#else
#define LOGVAL(fmt, ...) \
    do { \
        if (bdface::bdface_get_log_status(bdface::BDFaceLogType::BDFACE_LOG_TYPE_VALUE)) \
        { \
            printf("FaceSDK ---value--- <line %d: %s> " fmt "\n", __LINE__, __FUNCTION__, ##__VA_ARGS__); \
        } \
    } while (0)

#define LOGPERF() TimePrinter performance_log##__LINE__;\
    if (bdface::bdface_get_log_status(bdface::BDFaceLogType::BDFACE_LOG_TYPE_PERF)) \
    { \
        performance_log##__LINE__.start(__FUNCTION__, __LINE__); \
    } \

#define LOGERR(fmt, ...) \
    do { \
        if (bdface::bdface_get_log_status(bdface::BDFaceLogType::BDFACE_LOG_TYPE_ERROR)) \
        { \
            printf("FaceSDK ---error--- <line %d: %s> " fmt "\n", __LINE__, __FUNCTION__,  ##__VA_ARGS__); \
        } \
    } while (0)

#define LOGDEBUG(fmt, ...) \
    do { \
        if (bdface::bdface_get_log_status(bdface::BDFaceLogType::BDFACE_LOG_TYPE_DEBUG)) \
        { \
            printf("FaceSDK ---debug--- <line %d: %s> " fmt "\n", __LINE__, __FUNCTION__,  ##__VA_ARGS__); \
        } \
    } while (0)
#endif

#ifdef __cplusplus
    }
}
#endif

#endif
