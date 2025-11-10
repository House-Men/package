/***************************************************************************
 *
 * Copyright (c) 2018 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

/**
 * @file    ibdface_emotion.h
 * @author  v_liujialu01<v_liujialu01@baidu.com>
 * @date    2019-02-12 10:40
 * @brief   表情检测接口文件
 */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_framework.h"
#include "nn/interface/ibdface_inference.h"
#include "abilities/base/align/interface/ibdface_align.h"

#ifndef INTERFACE_IBDFACE_EMOTION_H
#define INTERFACE_IBDFACE_EMOTION_H
#pragma once

#ifdef __cplusplus
namespace bdface {
    
extern "C" {
#endif
        /**
         * @brief   人脸情绪类型枚举
         */
        enum BDFaceEmotionType {
            BDFACE_EMOTIONS_TYPE_ANGRY = 0,      // 生气
            BDFACE_EMOTIONS_TYPE_DISGUST = 1,    // 厌恶
            BDFACE_EMOTIONS_TYPE_FEAR = 2,       // 害怕
            BDFACE_EMOTIONS_TYPE_HAPPY = 3,      // 高兴
            BDFACE_EMOTIONS_TYPE_SAD = 4,        // 悲伤
            BDFACE_EMOTIONS_TYPE_SURPRISE = 5,   // 惊奇
            BDFACE_EMOTIONS_TYPE_NEUTRAL = 6,    // 中性
        };

        /**
         * @brief   情绪结构体
         */
        struct BDFaceEmotions {
            enum BDFaceEmotionType expression;    // 情绪
            float expression_conf;                // 对应的置信度
            float* expression_conf_list;          // 所有情绪的置信度
        };

        /**
         * @brief   情绪数据列表
         */
        struct BDFaceEmotionsList {
            int num;                    // 情绪数据个数
            BDFaceEmotions* emotions;   // 情绪数据指针
        };

        /**
         * @brief emotion配置
         */
        struct BDFaceEmotionsConf {
            struct BDFaceInferenceConf infer_conf;  // 预测库配置
        };

        /**
         * @brief   获取emotion配置
         * @param[in]   struct BDFaceDetectConf*    conf    配置对象地址
         * @return      BDFaceStatusCode            状态码
         */
        DLL_API enum BDFaceStatusCode bdface_emotions_get_default_conf(struct BDFaceEmotionsConf* conf);

        /**
         * @brief   加载情绪检测能力
         * @param[in]   BDFaceInstance              face_instance   sdk实例对象地址
         * @param[in]   const long                  model_lengthl   模型长度
         * @param[in]   const char*                 model_memory    模型内存地址
         * @param[in]   struct BDFaceEmotionsConf*  conf            配置对象地址
         * @return      enum BDFaceStatusCode       状态码
         */
        DLL_API enum BDFaceStatusCode bdface_load_emotion(
                BDFaceInstance face_instance,
                const long model_length,
                const char* model_memory,
                struct BDFaceEmotionsConf* conf);

        /**
         * @brief   卸载情绪检测能力
         * @param[in]   BDFaceInstance          face_instance   sdk实例对象地址
         * @return      enum BDFaceStatusCode   状态码
         */
        DLL_API enum BDFaceStatusCode bdface_unload_emotion(BDFaceInstance face_instance);

        /**
         * @brief   情绪检测接口
         * @param[in]   const BDFaceInstance                    face_instance   sdk实例对象地址
         * @param[in]   const struct BDFaceImageInstance*       img_instance    图像句柄
         * @param[in]   const struct BDFaceLandmarkList*        type            人脸特征点
         * @param[out]  struct BDFaceEmotionsList**             emotion_list    情绪数据列表
         * @return      enum BDFaceStatusCode                   状态码
         */
        DLL_API enum  BDFaceStatusCode bdface_emotion(
                const BDFaceInstance face_instance,
                const struct BDFaceImageInstance* img_instance,
                const struct BDFaceLandmarkList* landmark_list,
                struct BDFaceEmotionsList** emotion_list);

#ifdef __cplusplus
}

}
#endif

#endif
