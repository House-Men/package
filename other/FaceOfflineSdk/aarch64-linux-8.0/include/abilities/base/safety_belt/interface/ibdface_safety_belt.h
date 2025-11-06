/***************************************************************************
*
* Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
*
**************************************************************************/

/**
 * @file    ibdface_safety_belt.h
 * @author  litonghui<litonghui@baidu.com>
 * @date    2020-12-11 17:00
 * @brief
 */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_framework.h"
#include "nn/interface/ibdface_inference.h"

#ifndef FACELIBRARYDEMO_IBDFACE_SAFETY_BELT_H
#define FACELIBRARYDEMO_IBDFACE_SAFETY_BELT_H

#pragma once

#ifdef __cplusplus
namespace bdface {

extern "C" {
#endif

        /**
        * @brief   安全带检测分值列表
        */
        struct BDFaceSafetyBeltList {
            int num;            // 活体分值个数
            float *scores;      // 活体数据地址
        };

        /**
         * @brief   安全带检测配置参数结构体
         */
        struct BDFaceSafetyBeltConf {
            struct BDFaceInferenceConf infer_conf;  // 预测库配置
        };

        /**
         * @brief   获取安全带检测参数配置
         */
        DLL_API enum BDFaceStatusCode bdface_safety_belt_get_default_conf(
                struct BDFaceSafetyBeltConf* conf);

        /**
         * @brief   加载安全带检测能力
         * @param[int]  BDFaceInstance          face_instance   SDK 实例对象地址
         * @param[int]  long                    model_length    模型大小
         * @param[int]  char*                   model_memory    模型内存地址
         * @param[int]  BDFaceSafetyBeltConf*   conf            配置对象地址
         * @return      enum BDFaceStatusCode   状态码
         */
        DLL_API enum BDFaceStatusCode bdface_load_safety_belt(
                BDFaceInstance face_instance,
                const long model_length,
                const char *model_memory,
                struct BDFaceSafetyBeltConf *conf);

        /**
         * @brief   卸载安全带检测能力
         * @param[int]  BDFaceInstance          face_instance   SDK 实例对象地址
         */
        DLL_API enum BDFaceStatusCode bdface_unload_safety_belt(
                BDFaceInstance face_instance);

        /*
         * @brief   安全带检测接口
         * @param[in]   BDFaceInstance                      face_instance       sdk实例对象地址
         * @param[in]   const struct BDFaceImageInstance*   img_instance        图像句柄
         * @param[in]   struct BDFaceLandmarkList*          landmark_list       人脸关键点数据地址
         * @param[in]   struct BDFaceSafetyBeltList**       safety_belt_list    活体检测数据指针地址
         * @return      enum BDFaceStatusCode               状态码
         */
        DLL_API enum BDFaceStatusCode bdface_safety_belt(
                const BDFaceInstance face_instance,
                const struct BDFaceImageInstance *img_instance,
                const struct BDFaceLandmarkList *landmark_list,
                const struct BDFaceSafetyBeltList **safety_belt_list);


#ifdef __cplusplus
}

}
#endif

#endif //FACELIBRARYDEMO_IBDFACE_SAFETY_BELT_H
