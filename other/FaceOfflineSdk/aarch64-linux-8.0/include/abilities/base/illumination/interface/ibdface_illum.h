/***************************************************************************
 *
 * Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

 /**
  * @file    ibdface_illum.h
  * @author  zhangjifeng<zhangjifeng@baidu.com>
  * @date    2019-02-20 10:20
  * @brief   人脸光照强度检测接口文件
  */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_framework.h"
#include "nn/interface/ibdface_inference.h"
#include "../../align/interface/ibdface_align.h"

#ifndef INTERFACE_IBDFACE_ILLUM_H
#define INTERFACE_IBDFACE_ILLUM_H
#pragma once

#ifdef __cplusplus
namespace bdface {

extern "C" {
#endif

    /**
     * @brief   人脸光照数据列表
     */
    struct BDFaceIlluminationList {
        int num;        // 人脸光照强度个数
        int* scores;    // 光照强度数据指针
    };

    /**
     * @brief   加载人脸光照强度检测能力
     * @param[in]   BDFaceInstance              face_instance   sdk实例对象地址
     * @return      enum BDFaceStatusCode       状态码
     */
    DLL_API enum BDFaceStatusCode bdface_load_illumination(BDFaceInstance face_instance);

    /**
     * @brief   卸载人脸光照强度检测能力
     * @param[in]   BDFaceInstance          face_instance   sdk实例对象地址
     * @return      enum BDFaceStatusCode   状态码
     */
    DLL_API enum BDFaceStatusCode bdface_unload_illumination(BDFaceInstance face_instance);

    /**
     * @brief   人脸光照强度检测接口
     * @param[in]   const BDFaceInstance                face_instance   sdk实例对象地址
     * @param[in]   const struct BDFaceImageInstance*   img_instance    图像句柄
     * @param[in]   const strcut BDFaceLandmarkList*    landmark_list   人脸关键点数据地址
     * @param[out]  struct BDFaceIlluminationList**     illum_list      人脸光照强度数据指针地址
     * @return      enum BDFaceStatusCode               状态码
     */
    DLL_API enum BDFaceStatusCode bdface_illumination(
            const BDFaceInstance face_instance,
            const struct BDFaceImageInstance* img_instance,
            const struct BDFaceLandmarkList* landmark_list,
            struct BDFaceIlluminationList** illum_list);
#ifdef __cplusplus
}

}
#endif

#endif
