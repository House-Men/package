/***************************************************************************
*
* Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
*
**************************************************************************/

/**
 * @file    ibdface_dark_enhance.h
 * @author  litonghui<litonghui@baidu.com>
 * @date    2020-12-21 14:30
 * @brief   暗光恢复
 */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_framework.h"
#include "nn/interface/ibdface_inference.h"

#ifndef FACELIBRARYDEMO_IBDFACE_DARK_ENHANCE_H
#define FACELIBRARYDEMO_IBDFACE_DARK_ENHANCE_H

#pragma once

#ifdef __cplusplus
namespace bdface {

extern "C" {
#endif

/**
 * @brief   暗光恢复配置参数结构体
 */
struct BDFaceDarkEnhanceConf {
    struct BDFaceInferenceConf infer_conf;  // 预测库配置
};

/**
 * @brief   获取暗光恢复默认参数配置
 */
DLL_API enum BDFaceStatusCode bdface_dark_enhance_get_default_conf(
        struct BDFaceDarkEnhanceConf* conf);

/**
 * @brief   加载暗光恢复能力
 * @param[int]  BDFaceInstance          face_instance   SDK 实例对象地址
 * @param[int]  long                    model_length    模型大小
 * @param[int]  char*                   model_memory    模型内存地址
 * @param[int]  BDFaceDarkEnhanceConf*  conf            配置对象地址
 * @return      enum BDFaceStatusCode   状态码
 */
DLL_API enum BDFaceStatusCode bdface_load_dark_enhance(
        BDFaceInstance face_instance,
        const long model_length,
        const char *model_memory,
        struct BDFaceDarkEnhanceConf *conf);

/**
 * @brief   卸载暗光恢复能力
 * @param[int]  BDFaceInstance          face_instance   SDK 实例对象地址
 */
DLL_API enum BDFaceStatusCode bdface_unload_dark_enhance(
        BDFaceInstance face_instance);

/*
 * @brief   暗光恢复接口
 * @param[in]   BDFaceInstance                      face_instance       sdk实例对象地址
 * @param[in]   const struct BDFaceImageInstance*   img_instance        图像句柄
 * @param[out]  struct BDFaceImageInstance**        out_img_instance    图像句柄
 * @return      enum BDFaceStatusCode               状态码
 */
DLL_API enum BDFaceStatusCode bdface_dark_enhance(
        const BDFaceInstance face_instance,
        const struct BDFaceImageInstance *img_instance,
        struct BDFaceImageInstance **out_img_instance);

#ifdef __cplusplus
}

}
#endif

#endif
