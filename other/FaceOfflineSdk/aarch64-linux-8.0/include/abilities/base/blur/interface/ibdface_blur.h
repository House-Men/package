/***************************************************************************
 *
 * Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

 /**
  * @file    ibdface_blur.h
  * @author  zhangjifeng<zhangjifeng@baidu.com>
  * @date    2019-02-11 16:20
  * @brief   人脸模糊度检测接口文件
  */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_framework.h"
#include "nn/interface/ibdface_inference.h"
#include "../../align/interface/ibdface_align.h"

#ifndef INTERFACE_IBDFACE_BLUR_H
#define INTERFACE_IBDFACE_BLUR_H
#pragma once

#ifdef __cplusplus
namespace bdface {

extern "C" {
#endif
        /**
         * @brief   人脸模糊度参数配置结构体
         */
        struct BDFaceBlurConf {
            struct BDFaceInferenceConf infer_conf; // 预测库相关配置
        };

        /**
         * @brief   人脸模糊度数据列表
         */
        struct BDFaceBlurList {
            int num;        // 模糊度分值个数
            float* scores;  // 模糊度分值数据指针
        };

        /**
         * @brief   获取默认参数配置
         * @param[in]   struct BDBDFaceBlurConf*    conf    配置对象地址
         * @return      BDFaceStatusCode            状态码
         */
        DLL_API enum BDFaceStatusCode bdface_blur_get_default_conf(struct BDFaceBlurConf* conf);

        /**
         * @brief   加载人脸模糊检测能力
         * @param[in]   BDFaceInstance              face_instance   sdk实例对象地址
         * @param[in]   const long                  model_length    模型内存长度
         * @param[in]   const char*                 model_memory    模型内存地址
         * @param[in]   struct BDFaceBlurConf*      conf            配置对象地址
         * @return      enum BDFaceStatusCode       状态码
         */
        DLL_API enum BDFaceStatusCode bdface_load_blur(
                BDFaceInstance face_instance,
                const long model_length,
                const char* model_memory,
                struct BDFaceBlurConf* conf);

        /**
         * @brief   卸载人脸模糊度检测能力
         * @param[in]   BDFaceInstance          face_instance   sdk实例对象地址
         * @return      enum BDFaceStatusCode   状态码
         */
        DLL_API enum BDFaceStatusCode bdface_unload_blur(BDFaceInstance face_instance);

        /**
         * @brief   人脸模糊度检测接口
         * @param[in]   const BDFaceInstance                face_instance   sdk实例对象地址
         * @param[in]   const struct BDFaceImageInstance    img_instance     图像句柄
         * @param[in]   const struct BDFaceLandmarkList*    landmark_list   人脸关键点数据地址
         * @param[out]  struct BDFaceBlurList**             blur_list       模糊度数据列表地址
         * @return      enum BDFaceStatusCode               状态码
         */
        DLL_API enum BDFaceStatusCode bdface_blur(
                const BDFaceInstance face_instance,
                const struct BDFaceImageInstance* img_instance,
                const struct BDFaceBBoxList* bbox_list,
		struct BDFaceBlurList** blur_list);

#ifdef __cplusplus
}

}
#endif

#endif
