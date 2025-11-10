/***************************************************************************
 *
 * Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

 /**
  * @file    ibdface_occlusion.h
  * @author  zhangjifeng<zhangjifeng@baidu.com>
  * @date    2019-02-19 10:15
  * @brief   人脸遮挡度检测接口文件
  */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_framework.h"
#include "nn/interface/ibdface_inference.h"
#include "../../align/interface/ibdface_align.h"

#include "../../detect/interface/ibdface_detect.h"

#ifndef INTERFACE_IBDFACE_OCCLUSION_H
#define INTERFACE_IBDFACE_OCCLUSION_H
#pragma once

#ifdef __cplusplus
namespace bdface {
extern "C" {
#endif

/**
 * @brief   人脸遮挡信息结构体
 */
struct BDFaceOcclusion {
    float left_eye;    // 左眼遮挡置信度
    float right_eye;   // 右眼遮挡置信度
    float nose;        // 鼻子遮挡置信度
    float mouth;       // 嘴巴遮挡置信度
    float left_cheek;  // 左脸遮挡置信度
    float right_cheek; // 右脸遮挡置信度
    float chin;        // 下巴遮挡置信度
};

/**
 * @brief   人脸遮挡数据列表
 */
struct BDFaceOcclusionList {
    int num;                        // 遮挡数据个数 
    struct BDFaceOcclusion* occlus; // 遮挡数据指针
};

/**
 * @brief   人脸遮挡参数配置
 */
struct BDFaceOcclusionConf {
    struct BDFaceInferenceConf infer_conf; // 预测库配置
};

/**
 * @brief   获取默认参数配置
 * @param[in]   struct BDFaceOcclusionConf*     conf    默认配置对象地址
 * @return      enum BDFaceStatusCode           状态码
 */
DLL_API enum BDFaceStatusCode bdface_occlusion_get_default_conf(struct BDFaceOcclusionConf* conf);

/**
 * @brief   加载人脸遮挡检测能力
 * @param[in]   BDFaceInstance              face_instance   sdk实例对象地址
 * @param[in]   const long                  model_length    模型内存长度
 * @param[in]   const char*                 model_memory    模型内存地址
 * @param[in]   struct BDFaceOcclusionConf* conf            配置对象地址
 * @return      enum BDFaceStatusCode       状态码
 */
DLL_API enum BDFaceStatusCode bdface_load_occlusion(
        BDFaceInstance face_instance,
        const long model_length,
        const char* model_memory,
        struct BDFaceOcclusionConf* conf);

/**
 * @brief   卸载人脸遮挡检测能力
 * @param[in]   BDFaceInstance          face_instance   sdk实例对象地址
 * @return      enum BDFaceStatusCode   状态码
 */
DLL_API enum BDFaceStatusCode bdface_unload_occlusion(BDFaceInstance face_instance);

/**
 * @brief   人脸遮挡检测接口
 * @param[in]   const BDFaceInstance                face_instance   sdk实例对象地址
 * @param[in]   const struct BDFaceImageInstance*   img_instance    图像句柄
 * @param[in]   const struct BDFaceBBoxList*        bbox_list       人脸框数据
 * @param[out]  struct BDFaceOcclusionList**        occlu_list      人脸遮挡数据指针地址
 * @return      enum BDFaceStatusCode               状态码
 */
DLL_API enum BDFaceStatusCode bdface_occlusion(
        const BDFaceInstance face_instance,
        const struct BDFaceImageInstance* img_instance,
        const struct BDFaceBBoxList* bbox_list,
        struct BDFaceOcclusionList** occlu_list);

#ifdef __cplusplus
}
}
#endif

#endif
