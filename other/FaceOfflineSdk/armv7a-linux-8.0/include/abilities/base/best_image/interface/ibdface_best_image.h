/***************************************************************************
 *
 * Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/
/**
 * @file    ibdface_best_image.h
 * @author  v_shishuaifeng<v_shishuaifeng@baidu.com>
 * @date    2020-06-09
 * @brief   最优人脸检测接口文件
 */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_framework.h"
#include "nn/interface/ibdface_inference.h"

#ifndef INTERFACE_IBDFACE_BEST_IMAGE_H
#define INTERFACE_IBDFACE_BEST_IMAGE_H
#pragma once

#ifdef __cplusplus

namespace bdface {
extern "C" {
#endif

    /**
     * @brief  最优人脸配置参数结构体
     */
    struct BDFaceBestImageConf {
        struct BDFaceInferenceConf infer_conf;
    };

    /**
     * @brief 最优人脸数据列表
     */
    struct BDFaceBestImageList {
        int num;     // 人脸个数
        float* scores; // 数据指针
    };

    /**
     * @brief 最优人脸的枚举类型
     */
    enum BDFaceBestImageType{
        BDFACE_BEST_IMAGE_RGB = 0, // RGB
    };

    /**
     * @brief 获取默认配置参数
     * @param[in]   enum BDFaceBestImageType    type  最优人脸检测类型
     * @param[out]  struct BDFaceBestImageConf  conf  配置对象地址
     * @return      enum BDFaceStatusCode       状态码
     */
    DLL_API enum BDFaceStatusCode bdface_best_image_get_default_conf(
            enum BDFaceBestImageType type,
            struct BDFaceBestImageConf* conf);

    /**
     * @brief 加载最优人脸检测能力
     * @param[in] BDFaceInstance               face_instance  sdk 实例对象地址
     * @param[in] enum BDFaceBestImageType     type           最优人脸检测类型
     * @param[in] const long model_length      model_length   模型长度
     * @param[in] const char* model_memory     model_memory   模型内存地址
     * @param[in] struct BDFaceBestImageConf   conf           配置对象地址
     * @return    enum BDFaceStatusCode        状态码
     */
    DLL_API enum BDFaceStatusCode bdface_load_best_image(
            BDFaceInstance face_instance,
            enum BDFaceBestImageType type,
            const long model_length,
            const char* model_memory,
            struct BDFaceBestImageConf* conf);

    /**
     * @brief 卸载最优人脸检测能力
     * @param[in] BDFaceInstance               face_instance  sdk 实例对象地址
     * @param[in] enum BDFaceBestImageType     type           最优人脸检测类型
     * @return    enum BDFaceStatusCode        状态码
     */
    DLL_API enum BDFaceStatusCode bdface_unload_best_image(
            BDFaceInstance face_instance,
            enum BDFaceBestImageType type);

    /**
     * @brief  最优人脸检测接口
     * @param[in]  BDFaceInstance                       face_instance  sdk 实例对象地址
     * @param[in]  enum BDFaceBestImageType             type           最优人脸检测类型
     * @param[in]  const struct BDFaceImageInstance     img_instance   图像句柄
     * @param[in]  const struct BDFaceLandmarkList      landmark_list  人脸关键点数据地址
     * @param[out] struct BDFaceBestImageList           best_img_list  最优人脸数据指针地址
    * @return      enum BDFaceStatusCode                状态码
     */
    DLL_API enum BDFaceStatusCode bdface_best_image(
            const BDFaceInstance face_instance,
            enum BDFaceBestImageType type,
            const struct BDFaceImageInstance* img_instance,
            const struct BDFaceBBoxList* bbox_list,
	    struct BDFaceBestImageList** best_img_list);


#ifdef __cplusplus
}

}
#endif

#endif
