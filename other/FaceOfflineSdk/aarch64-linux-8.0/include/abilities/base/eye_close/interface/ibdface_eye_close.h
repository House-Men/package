/***************************************************************************
 *
 * Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

/**
 * @file        ibdface_eye_close.h
 * @author      zhangqiang<zhangqiang25@baidu.com>
 * @created     2019-03-07 10:08
 * @brief       人眼闭合状态检测接口文件
 */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_framework.h"
#include "nn/interface/ibdface_inference.h"
#include "../../align/interface/ibdface_align.h"

#ifndef FACE_IBDFACE_EYE_CLOSE_H
#define FACE_IBDFACE_EYE_CLOSE_H
#pragma once

#ifdef __cplusplus
namespace bdface {

extern "C" {
#endif
        /**
         * @brief   人眼闭合状态结构体
         */
        struct BDFaceEyeClose {
            float left_eye_close_conf;      // 左眼闭合的置信度
            float right_eye_close_conf;     // 右眼闭合的置信度
        };

        /**
         * @brief   人眼闭合状态数据列表
         */
        struct BDFaceEyeCloseList {
            int num;                // 人眼闭合状态数据个数
            BDFaceEyeClose* eyes;   // 人眼闭合状态数据指针
        };

        /**
         * @brief   人眼闭合状态检测参数配置结构体
         */
        struct BDFaceEyeCloseConf {
            struct BDFaceInferenceConf infer_conf; // 预测库配置
        };

        /**
         * @brief       获取默认参数配置
         * @param[in]   struct BDFaceEyeCloseConf*    conf    配置对象地址
         * @return      BDFaceStatusCode              状态码
         */
        DLL_API enum BDFaceStatusCode bdface_eye_close_get_default_conf(struct BDFaceEyeCloseConf* conf);

        /**
         * @brief       加载人脸闭眼检测能力
         * @param[in]   BDFaceInstance              face_instance   sdk实例对象地址
         * @param[in]   const long                  model_length    模型内存长度
         * @param[in]   const char*                 model_memory    模型内存地址
         * @param[in]   struct BDFaceEyeCloseConf*  conf            配置对象地址
         * @return      enum BDFaceStatusCode       状态码
         */
        DLL_API enum BDFaceStatusCode bdface_load_eye_close(
                BDFaceInstance face_instance,
                const long model_length,
                const char* model_memory,
                struct BDFaceEyeCloseConf* conf);

        /**
         * @brief       卸载人脸闭眼检测能力
         * @param[in]   BDFaceInstance          face_instance   sdk实例对象地址
         * @return      enum BDFaceStatusCode   状态码
         */
        DLL_API enum BDFaceStatusCode bdface_unload_eye_close(BDFaceInstance face_instance);

        /**
         * @brief       人脸闭眼检测接口
         * @param[in]   const BDFaceInstance                face_instance   sdk实例对象地址
         * @param[in]   const struct BDFaceImageInstance*   img_instance    图像句柄
         * @param[in]   const struct BDFaceLandmarkList*    landmark_list   人脸关键点数据地址
         * @param[out]  struct BDFaceEyeCloseList**         eye_list        人眼闭合数据列表
         * @return      enum BDFaceStatusCode               状态码
         */
        DLL_API BDFaceStatusCode bdface_eye_close(
                const BDFaceInstance face_instance,
                const struct BDFaceImageInstance* img_instance,
                const struct BDFaceLandmarkList* landmark_list,
                struct BDFaceEyeCloseList** eye_list);
#ifdef __cplusplus
}

}
#endif

#endif
