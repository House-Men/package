/***************************************************************************
 *
 * Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

/**
 * @file        ibdface_mouth_mask.h
 * @author      taotianran<taotianran@baidu.com>
 * @created     2020-02-17 09:58
 * @brief       人脸口罩检测接口文件
 */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_framework.h"
#include "nn/interface/ibdface_inference.h"
#include "../../align/interface/ibdface_align.h"

#ifndef INTERFACE_IBDFACE_MOUTH_MASK_H
#define INTERFACE_IBDFACE_MOUTH_MASK_H
#pragma once

#ifdef __cplusplus
namespace bdface {
extern "C" {
#endif

/**
 * @brief   口罩检测参数配置
 */
struct BDFaceMouthMaskConf {
    struct BDFaceInferenceConf infer_conf; // 预测库配置
};

/**
 * @brief   口罩数据列表
 */
struct BDFaceMouthMaskList {
    int num;          // 数据个数
    float* scores;    // 数据地址
};

/**
 * @brief       获取默认参数配置
 * @param[in]   struct BDFaceMouthMaskConf*     conf    配置对象地址
 * @return      BDFaceStatusCode                状态码
 */
DLL_API enum BDFaceStatusCode bdface_mouth_mask_get_default_conf(struct BDFaceMouthMaskConf* conf);

/**
 * @brief       加载口罩检测能力
 * @param[in]   BDFaceInstance                face_instance     sdk实例对象地址
 * @param[in]   const long                    model_length      模型内存长度
 * @param[in]   const char*                   model_memory      模型内存地址
 * @param[in]   struct BDFaceMouthMaskConf*   conf              配置对象地址
 * @return      enum BDFaceStatusCode         状态码
 */
DLL_API enum BDFaceStatusCode bdface_load_mouth_mask(
        BDFaceInstance face_instance,
        const long model_length,
        const char* model_memory,
        struct BDFaceMouthMaskConf* conf);

/**
 * @brief       卸载口罩检测能力
 * @param[in]   BDFaceInstance          face_instance   sdk实例对象地址
 * @return      enum BDFaceStatusCode   状态码
 */
DLL_API enum BDFaceStatusCode bdface_unload_mouth_mask(BDFaceInstance face_instance);

/**
 * @brief       人脸口罩检测接口
 * @param[in]   const BDFaceInstance                face_instance       sdk实例对象地址
 * @param[in]   const struct BDFaceImageInstance    img_instance        图像句柄
 * @param[in]   const strut BDFaceBBoxList*         box_list            人脸框数据地址
 * @param[out]  struct BDFaceMouthMaskList**        mouth_mask_list     口罩检测数据指针地址
 * @return      enum BDFaceStatusCode       状态码
 */
DLL_API BDFaceStatusCode bdface_mouth_mask(
        const BDFaceInstance face_instance,
        const struct BDFaceImageInstance* img_instance,
        const struct BDFaceLandmarkList* landmark_list,
        struct BDFaceMouthMaskList** mouth_mask_list);

#ifdef __cplusplus
}
}
#endif

#endif
