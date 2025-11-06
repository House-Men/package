/***************************************************************************
 *
 * Copyright (c) 2018 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

 /**
  * @file       ibdface_detect.h
  * @author     taotianran<taotianran@baidu.com>
  * @date       2019-01-07 10:15
  * @brief      人脸检测接口文件
  */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_framework.h"
#include "nn/interface/ibdface_inference.h"

#ifndef INTERFACE_IBDFACE_DETECT_H
#define INTERFACE_IBDFACE_DETECT_H
#pragma once

#ifdef __cplusplus
namespace bdface {

extern "C" {
#endif
        /**
         * @brief   人脸检测类型枚举
         */
        enum BDFaceDetectType {
            BDFACE_DETECT_TYPE_RGB = 0,     // rgb照片人脸检测
            BDFACE_DETECT_TYPE_NIR = 1,     // 近红外照片人脸检测
        };

        /**
         * @brief   人脸包围盒结构体
         */
        struct BDFaceBBox {
            int index;          // 人脸索引值
            float center_x;     // 人脸中心点x坐标
            float center_y;     // 人脸中心点y坐标
            float width;        // 人脸宽度
            float height;       // 人脸高度
            float angle;        // 人脸角度
            float score;        // 人脸置信度
        };

        /**
         * @brief   人脸包围盒列表
         */
        struct BDFaceBBoxList {
            int num;            // 人脸框个数
            BDFaceBBox* boxes;  // 人脸框数据指针
        };

        /**
         * @brief   人脸检测配置参数
         */
        struct BDFaceDetectConf {
            int max_detect_num;                     // 需要检测的最大人脸数目
            float min_face_size;                    // 需要检测的最小人脸大小
            float not_face_threshold;               // 过滤非人脸的阈值
            float scale_ratio;                      // 输入图像的缩放系数
                                                    //（检测分值大于该阈值认为是人脸）
            struct BDFaceInferenceConf infer_conf;  // 预测库配置
        };

        /**
         * @brief   获取检测参数配置
         * @param[in]   enum BDFaceDetectType       type    人脸检测类型
         * @param[in]   struct BDFaceDetectConf*    conf    配置对象地址
         * @return      enum BDFaceStatusCode       状态码
         */
        DLL_API enum BDFaceStatusCode bdface_detect_get_default_conf(
                enum BDFaceDetectType type,
                struct BDFaceDetectConf* conf);

        /**
         * @brief   加载人脸检测能力
         * @param[in]   BDFaceInstance              face_instance   sdk实例对象地址
         * @param[in]   enum BDFaceDetectType       type            人脸检测类型
         * @param[in]   const long                  model_length    模型长度
         * @param[in]   const char*                 model_memory    模型内存地址
         * @param[in]   struct BDFaceDetectConf*    conf            配置对象地址
         * @return      enum BDFaceStatusCode       状态码
         */
        DLL_API enum BDFaceStatusCode bdface_load_detect(
                BDFaceInstance face_instance,
                enum BDFaceDetectType type,
                const long model_length,
                const char* model_memory,
                struct BDFaceDetectConf* conf);

        /**
         * @brief   卸载人脸检测能力
         * @param[in]   BDFaceInstance          face_instance   sdk实例对象地址
         * @param[in]   enum BDFaceDetectType   type            人脸检测类型
         * @return      enum BDFaceStatusCode   状态码
         */
        DLL_API enum BDFaceStatusCode bdface_unload_detect(
                BDFaceInstance face_instance,
                enum BDFaceDetectType type);

        /**
         * @brief   人脸检测接口
         * @param[in]   const BDFaceInstance                face_instance   sdk实例对象地址
         * @param[in]   const struct BDFaceImageInstance    img_instance    图像句柄
         * @param[in]   enum BDFaceDetectType               type            人脸检测类型
         * @param[out]  struct BDFaceBBoxList**             box_list        人脸框数据指针地址
         * @return      enum BDFaceStatusCode               状态码
         */
        DLL_API enum BDFaceStatusCode bdface_detect(
                const BDFaceInstance face_instance,
                const struct BDFaceImageInstance* img_instance,
                enum BDFaceDetectType type,
                struct BDFaceBBoxList** box_list);

#ifdef __cplusplus
}

}
#endif

#endif
