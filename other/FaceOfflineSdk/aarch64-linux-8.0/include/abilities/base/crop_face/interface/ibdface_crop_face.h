/***************************************************************************
*
* Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
*
**************************************************************************/

/**
 * @file        ibdface_crop_face.h
 * @author      v_shishuaifeng<v_shishuaifeng@baidu.com>
 * @created     2019-03-04 18:35
 * @brief       抠图接口文件
 */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_framework.h"
#include "abilities/base/align/interface/ibdface_align.h"

#ifndef INTERFACE_IBDFACE_CROP_FACE_H
#define INTERFACE_IBDFACE_CROP_FACE_H
#pragma once

#ifdef __cplusplus
namespace bdface {

extern "C" {
#endif
        /**
         * @brief   抠图参数配置
         */
        struct BDFaceCropFaceConf {
            int is_flat;         // 是否镜像
            int crop_size;       // 抠图大小
            float enlarge_ratio; // 抠图的倍数
        };

        /**
         * @brief   获取默认参数配置
         * @param[in]   struct BDFaceCropFaceConf*    conf    配置对象地址
         * @return      BDFaceStatusCode              状态码
         */
        DLL_API enum BDFaceStatusCode bdface_crop_face_get_default_conf(struct BDFaceCropFaceConf* conf);

        /**
         * @brief       加载抠图能力
         * @param[in]   BDFaceInstance                  face_instance   sdk实例对象地址
         * @param[in]   struct BDFaceCropFaceConf*      conf            配置对象地址
         * @return      enum BDFaceStatusCode           状态码
         */
        DLL_API enum BDFaceStatusCode bdface_load_crop_face(
                BDFaceInstance face_instance,
                struct BDFaceCropFaceConf* conf);

        /**
         * @brief       卸载抠图能力
         * @param[in]   BDFaceInstance          face_instance   sdk实例对象地址
         * @return      enum BDFaceStatusCode   状态码
         */
        DLL_API enum BDFaceStatusCode bdface_unload_crop_face(BDFaceInstance face_instance);

        /**
         * @brief       抠图接口
         * @param[in]   const BDFaceInstance                face_instance   sdk实例对象地址
         * @param[in]   const struct BDFaceImageInstance*   src_img         输入图像句柄
         * @param[in]   const struct BDFaceLandmarkList*    landmark_list   人脸关键点数据地址
         * @param[out]  struct BDFaceImageInstance**        dst_img         输出图像句柄
         * @return      enum BDFaceStatusCode               状态码
         */
        DLL_API enum BDFaceStatusCode bdface_crop_face(
                const BDFaceInstance face_instance,
                const struct BDFaceImageInstance* src_img,
                const struct BDFaceLandmarkList* landmark_list,
                struct BDFaceImageInstance** dst_img);

#ifdef __cplusplus
}

}
#endif

#endif 
