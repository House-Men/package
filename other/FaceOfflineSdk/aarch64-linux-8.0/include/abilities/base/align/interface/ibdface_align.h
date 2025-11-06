/***************************************************************************
*
* Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
*
**************************************************************************/

/**
 * @file        ibdface_align.h
 * @author      lushuang<lushuang@baidu.com>
 * @created     2019-02-02 12:20
 * @brief       人脸关键点提取接口文件
 */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_framework.h"
#include "nn/interface/ibdface_inference.h"

#ifndef INTERFACE_IBDFACE_ALIGN_H
#define INTERFACE_IBDFACE_ALIGN_H
#pragma once

#ifdef __cplusplus
namespace bdface {

extern "C" {
#endif
    /**
     * @brief   人脸关键点枚举类型
     */
    enum BDFaceAlignType {
        BDFACE_ALIGN_TYPE_RGB_ACCURATE = 0,     // rgb高精度关键点
        BDFACE_ALIGN_TYPE_RGB_FAST = 1,         // rgb快速关键点
        BDFACE_ALIGN_TYPE_NIR_ACCURATE = 2,     // nir高精度关键点
        BDFACE_ALIGN_TYPE_150_RGB_ACCURATE = 3, // rgb 150高精度关键点
    };

    /**
     * @brief   人脸关键点数据结构体
     */
    struct BDFaceLandmark {
        int index;      // landmark索引
        int size;       // landmark大小
        float* data;    // landermark数据指针
        float score;    // 人脸置信度
    };

    /**
     * @brief   人脸关键点列表
     */
    struct BDFaceLandmarkList {
        int num;                            // 人脸关键点数量
        struct BDFaceLandmark* landmarks;   // 人脸关键点数据指针
    };

    /* 人脸关键点提取参数配置 */
    struct BDFaceAlignConf {
        float threshold;                            // 过滤非人脸的阈值（分值大于该阈值认为是人脸）
        struct BDFaceInferenceConf infer_conf;      // 预测库配置
    };

    /**
     * @brief   获取关键点参数配置
     * @param[in]   struct BDFaceAlignConf*     conf    配置对象地址
     * @param[in]   enum BDFaceAlignType        type    关键点类型
     * @return      enum BDFaceStatusCode       状态码
     */
    DLL_API enum BDFaceStatusCode bdface_align_get_default_conf(
            enum BDFaceAlignType type,
            struct BDFaceAlignConf* conf);

    /**
     * @brief   加载人脸关键点检测能力
     * @param[in]   BDFaceInstance              face_instance   sdk实例对象地址
     * @param[in]   enum BDFaceAlignType        type            关键点类型
     * @param[in]   const long                  model_length    模型长度
     * @param[in]   const char*                 model_memory    模型内存地址
     * @param[in]   struct BDFaceAlignConf*     conf            配置对象地址
     * @return      enum BDFaceStatusCode       状态码
     */
    DLL_API enum BDFaceStatusCode bdface_load_align(
            BDFaceInstance face_instance,
            enum BDFaceAlignType type,
            const long model_length,
            const char* model_memory,
            struct BDFaceAlignConf* conf);

    /**
     * @brief   卸载人脸关键点检测能力
     * @param[in]   const BDFaceInstance    face_instance   sdk实例对象地址
     * @param[in]   enum BDFaceAlignType    type            关键点类型
     * @return      enum BDFaceStatusCode   状态码
     */
    DLL_API enum BDFaceStatusCode bdface_unload_align(
            BDFaceInstance face_instance,
            enum BDFaceAlignType type);

    /**
     * @brief   检测人脸关键点
     * @param[in]   const BDFaceInstance                face_instance   sdk实例对象地址
     * @param[in]   enum BDFaceAlignType                type            关键点类型
     * @param[in]   const struct BDFaceImageInstance*   img_instance    图像句柄
     * @param[in]   const struct BDFaceBBoxList*        box_list        人脸框数据地址
     * @param[out]  struct BDFaceLandmarList**          landmarks_list  人脸关键点数据指针地址
     * @return      enum BDFaceStatusCode       状态码
     */
    DLL_API enum BDFaceStatusCode bdface_align(
            const BDFaceInstance face_instance,
            enum BDFaceAlignType type,
            const struct BDFaceImageInstance* img_instance,
            const struct BDFaceBBoxList* box_list,
            struct BDFaceLandmarkList** landmarks_list);

#ifdef __cplusplus
}

}
#endif

#endif
