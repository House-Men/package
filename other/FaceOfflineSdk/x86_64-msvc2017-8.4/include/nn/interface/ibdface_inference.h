/***************************************************************************
*
* Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
*
**************************************************************************/

/**
 * @file        ibdface_inference.h
 * @author      taotianran<taotianran@baidu.com>
 * @created     2019-01-21 11:14
 */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_common.h"

#ifndef INTERFACE_IBDFACE_INFERENCE_H
#define INTERFACE_IBDFACE_INFERENCE_H
#pragma once

#ifdef __cplusplus
namespace bdface {
    extern "C" {
#endif
        /**
         * @brief   预测库类型枚举
         */
        enum BDFaceInferenceType {
            BDFACE_INFERENCE_CAFFE = 0,         // caffe预测库
            BDFACE_INFERENCE_ANAKIN = 1,        // anakin预测库
            BDFACE_INFERENCE_PADDLE = 2,        // paddle预测库
            BDFACE_INFERENCE_PADDLE_LITE = 3,   // paddle lite预测库
            BDFACE_INFERENCE_RKNN356X = 4,      // rknn356x预测库
        };

        /**
         * @brief   使用anakin预测库的运行模式枚举
         */
        enum BDFaceAnakinRunMode {
            BDFACE_ANAKIN_RUN_AT_BIG_CORE = 0,      // 运行在大核
            BDFACE_ANAKIN_RUN_AT_SMALL_CORE = 1,    // 运行在小核
            BDFACE_ANAKIN_RUN_AUTO = 2,             // 自动选择
        };

        /**
         * @brief   使用anakin预测库的配置结构体
         */
        struct BDFaceInferenceAnakinConf {
            enum BDFaceAnakinRunMode mode;      // 运行模式
            int core_num;                       // 运行的核数
        };

        /**
         * @brief   使用paddle预测库的配置结构体
         */
        struct BDFaceInferencePaddleConf {
            bool enable_mkldnn;     // 开启mkldnn加速
            int cpu_thread_num;     // 设置CPU线程数
        };

        /**
         * @brief   使用paddle lite预测库的运行模式枚举, 推荐使用LITE_POWER_NO_BIND模式
         */
        enum BDFacePaddleLitePowerMode{
            LITE_POWER_HIGH = 0,
            LITE_POWER_LOW = 1,
            LITE_POWER_FULL = 2,
            LITE_POWER_NO_BIND = 3,
            LITE_POWER_RAND_HIGH = 4,
            LITE_POWER_RAND_LOW = 5
        };
        /**
         * @brief   使用paddle lite 预测库的配置结构体
         */
        struct BDFaceInferencePaddleLiteConf {
            enum BDFacePaddleLitePowerMode power_mode;      // 运行模式
            int cpu_thread_num;                             // 设置CPU线程数
        };

        /**
         * @brief   预测库的配置结构体
         */
        struct BDFaceInferenceConf {
            enum BDFaceInferenceType infer_type;                    // 使用的预测库类型
            struct BDFaceInferenceAnakinConf anakin_conf;           // anakin预测库配置
            struct BDFaceInferencePaddleConf paddle_conf;           // paddle预测库配置
            struct BDFaceInferencePaddleLiteConf paddlelite_conf;   // paddle预测库配置
        };

        /**
         * @brief   获取预测库默认配置
         * @param[out]  struct BDFaceInferenceConf* conf    指向预测库配置对象的指针
         * @return      BDFaceStatusCode            状态码
         */
        DLL_API enum BDFaceStatusCode bdface_inference_get_default_conf(
                struct BDFaceInferenceConf* conf);

#ifdef __cplusplus
    }
}
#endif

#endif
