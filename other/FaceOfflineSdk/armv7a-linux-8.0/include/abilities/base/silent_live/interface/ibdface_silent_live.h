/***************************************************************************
*
* Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
*
**************************************************************************/

/**
 * @file    ibdface_silent_live.h
 * @author  litonghui<litonghui@baidu.com>
 * @date    2019-02-20 16:22
 * @brief
 */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_framework.h"
#include "nn/interface/ibdface_inference.h"
#include "../../align/interface/ibdface_align.h"

#ifndef INTERFACE_IBDFACE_LIVENESS_H
#define INTERFACE_IBDFACE_LIVENESS_H
#pragma once

#ifdef __cplusplus
namespace bdface {
    
extern "C" {
#endif
        /**
         * @brief  静默活体类型枚举
         */
        enum BDFaceSilentLiveType {
            BDFACE_SILENT_LIVE_TYPE_RGB = 0,
            BDFACE_SILENT_LIVE_TYPE_NIR = 1,
            BDFACE_SILENT_LIVE_TYPE_DEPTH = 2,
        };

        /**
         * @brief   静默活体分值列表
         */
        struct BDFaceSilentLiveList {
            int num;            // 活体分值个数
            float* scores;      // 活体数据地址
        };

        /**
         * @brief 静默活体检测配置参数结构体
         */
        struct BDFaceSilentLiveConf {
            struct BDFaceInferenceConf infer_conf;  // 预测库配置
        };

        /**
         * @brie   获取检测参数配置
         * @param[in]   enum BDFaceSilentLiveType       type    活体类型
         * @param[in]   struct BDFaceSilentLiveConf*    conf    配置对象地址
         * @return      enum BDFaceStatusCode           状态码
         */
        DLL_API enum BDFaceStatusCode bdface_silent_live_get_default_conf(
                enum BDFaceSilentLiveType type,
                struct BDFaceSilentLiveConf* conf);

        /**
         * @brief   加载静默活体检测能力
         * @param[in]   BDFaceInstance                  face_instance   sdk实例对象地址
         * @param[in]   enum BDFaceSilentLiveType       type            静默活体类型
         * @param[in]   long                            model_length    模型大小
         * @param[in]   char*                           model_memory    模型内存地址
         * @param[in]   struct BDFaceSilentLiveConf*    conf            配置对象地址
         * @return      enum BDFaceStatusCode           状态码
         */
        DLL_API enum BDFaceStatusCode bdface_load_silent_live(
                BDFaceInstance face_instance,
                enum BDFaceSilentLiveType type,
                const long model_length,
                const char *model_memory,
                struct BDFaceSilentLiveConf *conf);

        /**
         * @brief 卸载静默活体检测能力
         * @param[in]   BDFaceInstance              face_instance   sdk实例对象地址
         * @param[in]   enum BDFaceSilentLiveType   type            静默活体类型
         * @return      enum BDFaceStatusCode       状态码
         */
        DLL_API enum BDFaceStatusCode bdface_unload_silent_live(
                BDFaceInstance face_instance,
                enum BDFaceSilentLiveType type);

        /**
         * @brief   静默活体检测接口
         * @param[in]   BDFaceInstance                      face_instance       sdk实例对象地址
         * @param[in]   const struct BDFaceImageInstance*   img_instance        图像句柄
         * @param[in]   enum BDFaceSilentLiveType           type                静默活体类型
         * @param[in]   struct BDFaceLandmarkList*          landmark_list       人脸关键点数据地址
         * @param[in]   struct BDFaceSilentLiveList**       silent_live_list    活体检测数据指针地址
         * @return      enum BDFaceStatusCode               状态码
         */
        DLL_API enum BDFaceStatusCode bdface_silent_live(
                const BDFaceInstance face_instance,
                const struct BDFaceImageInstance *img_instance,
                const enum BDFaceSilentLiveType type,
                const struct BDFaceLandmarkList *landmark_list,
                struct BDFaceSilentLiveList **silent_live_list);

#ifdef __cplusplus
}

}
#endif

#endif
