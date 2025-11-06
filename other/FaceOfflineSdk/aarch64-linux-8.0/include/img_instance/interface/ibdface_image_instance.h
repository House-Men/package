
/***************************************************************************
*
* Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
*
**************************************************************************/

/**
 * @file        ibdface_img_instance.h
 * @author      taotianran<taotianran@baidu.com>
 * @created     2019-01-23 11:30
 * @brief       图像实例对象相关接口
 */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_common.h"

#ifndef INTERFACE_IBDFACE_IMG_INSTANCE_H
#define INTERFACE_IBDFACE_IMG_INSTANCE_H
#pragma once

#ifdef __cplusplus
namespace bdface {

extern "C" {
#endif
        /**
         * @brief   图像类型枚举
         */
        enum BDFaceImageType {
            BDFACE_IMAGE_TYPE_RGB = 0,
            BDFACE_IMAGE_TYPE_BGR = 1,
            BDFACE_IMAGE_TYPE_RGBA = 2,
            BDFACE_IMAGE_TYPE_BGRA = 3,
            BDFACE_IMAGE_TYPE_GRAY = 4,
            BDFACE_IMAGE_TYPE_DEPTH = 5,
            BDFACE_IMAGE_TYPE_YUV_NV21 = 6,     //  YYYYVUVU
            BDFACE_IMAGE_TYPE_YUV_NV12 =7,      // YYYYUVUV
            BDFACE_IMAGE_TYPE_YUV_YV12 =8,      // YYYYVVUU
        };

        /**
         * @brief   图像实例结构体
         */
        struct BDFaceImageInstance {
            int rows;                   // 图像行数
            int cols;                   // 图像列数
            enum BDFaceImageType type;  // 图像类型
            unsigned char* data;        // 图像数据指针
        };

        /**
         * @brief   创建图像实例对象
         * @param[in]   int                             rows            行数
         * @param[in]   int                             cols            列数
         * @param[in]   enum BDFaceImageType            type            图片类型
         * @param[out]  struct BDFaceImageInstance**    img_instance    指向图像实例指针的指针
         * @return      enum BDFaceStatusCode           状态码
         */
        DLL_API enum BDFaceStatusCode bdface_create_img_instance(
                int rows,
                int cols,
                enum BDFaceImageType type,
                unsigned char* data,
                struct BDFaceImageInstance** img_instance);

        /**
         * @brief   销毁图像实例对象
         * @param[in]   struct BDFaceImageInstance* img_instance
         * @return      enum BDFaceStatusCode       状态码
         */
        DLL_API enum BDFaceStatusCode bdface_destroy_img_instance(struct BDFaceImageInstance* img_instance);

        /**
         * @brief   图像实例转换
         * @param[in]   struct BDFaceImageInstance*     src_instance    源图像实例指针
         * @param[in]   float                           angle           图像的旋转角度
         *                                                              转换会将图片顺时针
         *                                                              旋转此角度值
         * @param[in]   int                             is_mirror       是否是镜像
         *                                                              是则转换会将图片做镜像处理
         * @param[in]   enum BDFaceImageType            dst_type        要转换的目标类型       
         * @param[out]  struct BDFaceImageInstance**    dst_instance    指向转换结果图像的指针的指针
         */
        DLL_API enum BDFaceStatusCode bdface_convert_img_instance(
                struct BDFaceImageInstance* src_instance,
                float angle,
                int is_mirror,
                enum BDFaceImageType dst_type,
                struct BDFaceImageInstance** dst_instance);

        /**
         * @brief   创建图像实例对象, 支持图像旋转+镜像 目前仅支持YUV_NV21 到 BGR的转换
         * @param[in]   int                             rows            行数
         * @param[in]   int                             cols            列数
         * @param[in]   enum BDFaceImageType            src_type        源图片类型
         * @param[in]   float                           angle           图像的旋转角度(需要是90度的倍数)
         *                                                              转换会将图片顺时针
         *                                                              旋转此角度值
         * @param[in]   int                             is_mirror       是否是镜像
         * @param[in]   enum BDFaceImageType            dst_type        要转换的目标类型
         * @param[out]  struct BDFaceImageInstance**    img_instance    指向图像实例指针的指针
         * @return      enum BDFaceStatusCode           状态码
         */
        DLL_API enum BDFaceStatusCode bdface_create_img_instance_with_convert(
            int rows,
            int cols,
            enum BDFaceImageType src_type,
            unsigned char* data,
            int angle,
            int is_mirror,
            enum BDFaceImageType dst_type,
            struct BDFaceImageInstance** img_instance);

#ifdef __cplusplus
    }
}
#endif

#endif
