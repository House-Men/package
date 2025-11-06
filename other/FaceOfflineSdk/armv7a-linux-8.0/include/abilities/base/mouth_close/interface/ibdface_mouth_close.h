/***************************************************************************
 *
 * Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

/**
 * @file        ibdface_mouth_close
 * @author      zhangqiang<zhangqiang25@baidu.com>
 * @created     2019/3/7 上午10:08
 * @brief       外部调用的接口文件：人脸闭嘴检测接口的头文件
 */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_framework.h"
#include "nn/interface/ibdface_inference.h"
#include "../../align/interface/ibdface_align.h"

#ifndef FACE_IBDFACE_MOUTH_CLOSE_H
#define FACE_IBDFACE_MOUTH_CLOSE_H
#pragma once

#ifdef __cplusplus
namespace bdface {

extern "C" {
#endif
        /**
         * @brief   嘴巴闭合状态检测参数配置
         */
        struct BDFaceMouthCloseConf {
            struct BDFaceInferenceConf infer_conf; // 预测库配置
        };

        /**
         * @brief   嘴巴闭合状态数据列表
         */
        struct BDFaceMouthCloseList {
            int num;            // 数据个数
            float* scores;      // 数据地址
        };

        /**
         * @brief       获取默认参数配置
         * @param[in]   struct BDFaceMouthCloseConf*    conf    配置对象地址
         * @return      BDFaceStatusCode                状态码
         */
        DLL_API enum BDFaceStatusCode bdface_mouth_close_get_default_conf(struct BDFaceMouthCloseConf* conf);

        /**
         * @brief       加载嘴巴闭合状态检测能力
         * @param[in]   BDFaceInstance                face_instance     sdk实例对象地址
         * @param[in]   const long                    model_length      模型内存长度
         * @param[in]   const char*                   model_memory      模型内存地址
         * @param[in]   struct BDFaceMouthCloseConf*  conf              配置对象地址
         * @return      enum BDFaceStatusCode         状态码
         */
        DLL_API enum BDFaceStatusCode bdface_load_mouth_close(
                BDFaceInstance face_instance,
                const long model_length,
                const char* model_memory,
                struct BDFaceMouthCloseConf* conf);

        /**
         * @brief       卸载嘴巴闭合状态检测能力
         * @param[in]   BDFaceInstance          face_instance   sdk实例对象地址
         * @return      enum BDFaceStatusCode   状态码
         */
        DLL_API enum BDFaceStatusCode bdface_unload_mouth_close(BDFaceInstance face_instance);

        /**
         * @brief       人脸闭嘴检测接口
         * @param[in]   const BDFaceInstance                face_instance       sdk实例对象地址
         * @param[in]   const struct BDFaceImageInstance    img_instance        图像句柄
         * @param[in]   const strut BDFaceLandmarkList*     landmark_list       人脸关键点数据地址
         * @param[out]  struct BDFaceMouthCloseList**       mouth_list          嘴巴闭合数据指针地址
         * @return      enum BDFaceStatusCode       状态码
         */
        DLL_API BDFaceStatusCode bdface_mouth_close(
                const BDFaceInstance face_instance,
                const struct BDFaceImageInstance* img_instance,
                const struct BDFaceLandmarkList* landmark_list,
                struct BDFaceMouthCloseList** mouth_list);

#ifdef __cplusplus
}

}
#endif

#endif //FACE_IBDFACE_MOUTH_CLOSE_H
