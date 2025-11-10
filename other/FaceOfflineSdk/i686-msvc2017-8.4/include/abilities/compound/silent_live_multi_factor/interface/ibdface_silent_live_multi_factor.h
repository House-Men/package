/***************************************************************************
*
* Copyright (c) 2021 Baidu.com, Inc. All Rights Reserved
*
**************************************************************************/

/**
 * @file    ibdface_silent_live_multi_factor.h
 * @author  huweidong01<huweidong01@baidu.com>
 * @date    2021-08-23 16:02
 * @brief
 */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_framework.h"
#include "nn/interface/ibdface_inference.h"
#include "abilities/base/align/interface/ibdface_align.h"
// #include "abilities/compound/silent_live_multi_factor/src/face_ability_silent_live_multi_factor.h"
#include "abilities/base/silent_live/interface/ibdface_silent_live.h"

#if !defined(INTERFACE_IBDFACE_SILENT_LIVE_MULTI_FACTOR_H)
#define INTERFACE_IBDFACE_SILENT_LIVE_MULTI_FACTOR_H
#pragma once
 
namespace bdface
{

     /**
         * @brief   加载静默活体检测能力
         * @param[in]   BDFaceInstance                  face_instance   sdk实例对象地址
         * @param[in]   enum BDFaceSilentLiveType       type            静默活体类型
         * @param[in]   long                            model_length    模型大小
         * @param[in]   char*                           model_memory    模型内存地址
         * @param[in]   struct BDFaceSilentLiveConf*    conf            配置对象地址
         * @return      enum BDFaceStatusCode           状态码
         */
     DLL_API enum BDFaceStatusCode bdface_load_silent_live_multi_factor(
         const long model_liveness_length,
         const char *model_liveness_memory,
         const long model_2dmask_length,
         const char *model_2dmask_memory,
         const long model_hand_length,
         const char *model_hand_memory,
         const long model_reflection_length,
         const char *model_reflection_memory,
         struct BDFaceSilentLiveConf *conf);

     /**
         * @brief 卸载静默活体检测能力
         * @param[in]   BDFaceInstance              face_instance   sdk实例对象地址
         * @param[in]   enum BDFaceSilentLiveType   type            静默活体类型
         * @return      enum BDFaceStatusCode       状态码
         */
     DLL_API enum BDFaceStatusCode bdface_unload_silent_live_multi_factor();

     /**
         * @brief   静默活体检测接口
         * @param[in]   BDFaceInstance                      face_instance       sdk实例对象地址
         * @param[in]   const struct BDFaceImageInstance*   img_instance        图像句柄
         * @param[in]   enum BDFaceSilentLiveType           type                静默活体类型
         * @param[in]   struct BDFaceLandmarkList*          landmark_list       人脸关键点数据地址
         * @param[in]   struct BDFaceSilentLiveList**       silent_live_list    活体检测数据指针地址
         * @return      enum BDFaceStatusCode               状态码
         */
     DLL_API enum BDFaceStatusCode bdface_silent_live_multi_factor(
         const struct BDFaceImageInstance *img_instance,
         const struct BDFaceLandmarkList *landmark_list,
         struct BDFaceSilentLiveList **silent_live_list);

} // namespace bdface

#endif // INTERFACE_IBDFACE_SILENT_LIVE_MULTI_FACTOR_H
