/***************************************************************************
*
* Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
*
**************************************************************************/

/**
 * @file        ibdface_crop_image.h
 * @author      zhangwenming<zhangwenming@baidu.com>
 * @created     2019-03-04 18:35
 * @brief       人脸抠图接口（新版）
 */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_framework.h"
#include "abilities/base/align/interface/ibdface_align.h"
#include "abilities/base/detect/interface/ibdface_detect.h"

#ifndef INTERFACE_IBDFACE_CROP_IMAGE_H
#define INTERFACE_IBDFACE_CROP_IMAGE_H
#pragma once

#ifdef __cplusplus
namespace bdface {

extern "C" {
#endif
        /*
         * 抠图结果是否超出边界, 0:未出边界，other：出边界
         */
        struct BDFaceIsOutBoundary {
            int left;
            int right;
            int top;
            int bottom;
        };

        struct BDFaceCropParam{
            float forehead_extend;      // 额头扩展，大于等于0，0：不进行扩展
            float chin_extend;          // 下巴扩展，大于等于0，0：不进行扩展
            float enlarge_ratio;        // 人脸框与背景比例，大于等于1，1：不进行扩展
            int width;                  // 输出图像宽，设置为有效值(大于0)则对图像进行缩放，否则输出原图抠图结果
            int height;                 // 输出图像宽，设置为有效值(大于0)则对图像进行缩放，否则输出原图抠图结果
        };

        /**
         * 加载扣图能力
         * @param face_instance sdk实例对象地址
         * @return 状态码
         */
        DLL_API enum BDFaceStatusCode bdface_load_crop_image(BDFaceInstance face_instance);

        /**
        * @brief   卸载扣图能力
        * @param[in]   BDFaceInstance          face_instance   sdk实例对象地址
        * @return      enum BDFaceStatusCode   状态码
        */
        DLL_API enum BDFaceStatusCode bdface_unload_crop_image(BDFaceInstance face_instance);

        /**
         * @brief       根据给定的人脸关键点进行扣图
         * @param[in]   const BDFaceInstance                face_instance   sdk实例对象地址
         * @param[in]   const struct BDFaceImageInstance*   src_img         输入图像句柄
         * @param[in]   struct BDFaceLandmark*              landmark        人脸关键点
         * @param[out]  int*                                is_outof_boundary 扣图是否超出图像范围（是否有黑边）
         * @param[out]  struct BDFaceImageInstance**        dst_img         图像扣图结果
         * @param[in]  float                                enlage_ratio    扣图框放大倍数
         * @param[in]  float                                correction      是否进行人脸矫正
         * @return     enum BDFaceStatusCode                                扣图状态
         */
        DLL_API enum BDFaceStatusCode bdface_crop_image_with_landmark(
                const BDFaceInstance face_instance,
                const struct BDFaceImageInstance* src_img,
                struct BDFaceLandmark* landmark,
                struct BDFaceImageInstance** dst_img,
                int* is_outof_boundary,
                float enlage_ratio = 1,
                bool correction = false);

        /**
        * @brief       根据给定的人脸框进行扣图
        * @param[in]   const BDFaceInstance                face_instance   sdk实例对象地址
        * @param[in]   const struct BDFaceImageInstance*   src_img         输入图像句柄
        * @param[in]   struct BDFaceBBox*                  face_box        人脸框
        * @param[out]  int*                                is_outof_boundary 扣图是否超出图像范围（是否有黑边）
        * @param[out]  struct BDFaceImageInstance**        dst_img         图像扣图结果
        * @param[in]  float                                enlage_ratio    扣图框放大倍数
        * @return     enum BDFaceStatusCode                                扣图状态
        */
        DLL_API enum BDFaceStatusCode bdface_crop_image_with_box(
                const BDFaceInstance face_instance,
                const struct BDFaceImageInstance* src_img,
                struct BDFaceBBox* face_box,
                struct BDFaceImageInstance** dst_img,
                int *is_outof_boundary,
                float enlage_ratio = 1);

        /**
        * @brief       将人脸扣图图片进行缩放
        * @param[in]   const struct BDFaceImageInstance*   src_img         输入图像句柄
        * @param[in]   int size                            size            设置压缩图像的大小
        * @param[out]  struct BDFaceImageInstance**        dst_img         图像缩放结果
        * @return     enum BDFaceStatusCode                                扣图状态
        */
        DLL_API enum BDFaceStatusCode bdface_image_resize(
                const struct BDFaceImageInstance* src_img,
                int size,
                struct BDFaceImageInstance** dst_img);

        /**
         * 检查以人脸框抠图，抠图结果是否出边界
         * @param face_instance sdk实例对象地址
         * @param src_img 输入图片
         * @param face_box 人脸框
         * @param crop_param 抠图参数
         * @param is_out_b 输出参数，抠图结果4个边界是否出原图
         * @return 扣图状态
         */
        DLL_API BDFaceStatusCode bdface_crop_box_is_outof_boundary(
                const BDFaceInstance face_instance,
                const struct BDFaceImageInstance* src_img,
                struct BDFaceBBox* face_box,
                const struct BDFaceCropParam* crop_param,
                BDFaceIsOutBoundary* is_out_b
        );

        /**
         * 使用输入人脸框进行抠图，抠图结果自动去除黑边，（去除黑边的情况下，图片不会再进行放缩resize）
         * @param face_instance sdk实例对象地址
         * @param src_img 输入图片
         * @param face_box 人脸框
         * @param crop_param 抠图参数
         * @param dst_img 输出参数 抠图结果
         * @return 扣图状态
         */
        DLL_API BDFaceStatusCode bdface_crop_image_with_box_param(
                const BDFaceInstance face_instance,
                const struct BDFaceImageInstance* src_img,
                struct BDFaceBBox* face_box,
                const struct BDFaceCropParam* crop_param,
                struct BDFaceImageInstance** dst_img
        );

        /**
         * 检查以关键点抠图，抠图结果是否会出边界
         * @param face_instance sdk实例对象地址
         * @param src_img 输入图片
         * @param landmark 人脸关键点
         * @param crop_param 抠图参数
         * @param is_out_b 输出参数，抠图结果4个边界是否出原图
         * @return 扣图状态
         */
        DLL_API BDFaceStatusCode bdface_crop_landmark_is_outof_boundary(
                const BDFaceInstance face_instance,
                const struct BDFaceImageInstance* src_img,
                struct BDFaceLandmark* landmark,
                const struct BDFaceCropParam* crop_param,
                BDFaceIsOutBoundary* is_out_b
        );

        /**
         * 使用关键点进行抠图，抠图结果会自动做人脸矫正，抠图结果不会去除黑边
         * @param face_instance sdk实例对象地址
         * @param src_img 输入图片
         * @param landmark 人脸关键点
         * @param crop_param 抠图参数
         * @param dst_img 输出参数，抠图结果
         * @return 扣图状态
         */
        DLL_API BDFaceStatusCode bdface_crop_image_with_landmark_param(
                const BDFaceInstance face_instance,
                const struct BDFaceImageInstance* src_img,
                struct BDFaceLandmark* landmark,
                const struct BDFaceCropParam* crop_param,
                struct BDFaceImageInstance** dst_img
        );

#ifdef __cplusplus
}

}
#endif

#endif 
