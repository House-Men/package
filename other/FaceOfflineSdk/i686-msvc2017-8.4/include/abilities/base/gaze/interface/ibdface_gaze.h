/***************************************************************************
 *
 * Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

/**
 * @file        ibdface_gaze.h
 * @author      v_shishuaifeng<v_shishuaifeng@baidu.com>
 * @created     2019-01-31 15:33
 */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_framework.h"
#include "nn/interface/ibdface_inference.h"
#include "abilities/base/align/interface/ibdface_align.h"

#ifndef INTERFACE_IBDFACE_GAZE_H
#define INTERFACE_IBDFACE_GAZE_H
#pragma once

#ifdef __cplusplus
namespace bdface {

extern "C" {
#endif

/**
 * @brief   双眼注意力信息
 */
enum BDFaceGazeDirection {
    BDFACE_GAZE_DIRECTION_UP = 0,           // 向上看
    BDFACE_GAZE_DIRECTION_DOWN = 1,         // 向下看
    BDFACE_GAZE_DIRECTION_RIGHT = 2,        // 向右看
    BDFACE_GAZE_DIRECTION_LEFT = 3,         // 向左看
    BDFACE_GAZE_DIRECTION_FRONT = 4,        // 向前看
    BDFACE_GAZE_DIRECTION_EYE_CLOSE = 5,    // 闭眼
};

/**
 * @brief   注意力参数配置
 */
struct BDFaceGazeConf {
    BDFaceInferenceConf infer_conf;         // 预测库配置
};

/**
 * @brief 注意力信息
 */
struct BDFaceGaze {
    BDFaceGazeDirection direction;      // 凝视方向
    float confidence;                   // 置信度
};

/**
 * @brief   双眼注意力信息
 */
struct BDFaceGazeInfo {
    BDFaceGaze left_eye;    // 左眼注意力信息
    BDFaceGaze right_eye;   // 右眼注意力信息
    BDFaceGaze softmax_eye;   // 右眼注意力信息
};

/**
 * @brief   双眼注意力信息列表
 */
struct BDFaceGazeInfoList {
    int num;                        // 注意力信息个数
    struct BDFaceGazeInfo* gazes;   // 注意力数据指针
};

/**
 * @brief   获取默认参数配置
 * @param[in]   struct BDBDFaceGazeConf*    conf    配置对象地址
 * @return      enum BDFaceStatusCode       状态码
 */
DLL_API BDFaceStatusCode bdface_gaze_get_default_conf(struct BDFaceGazeConf* conf);

/**
 * @brief   加载注意力检测能力
 * @param[in]   BDFaceInstance              face_instance   sdk实例对象地址
 * @param[in]   const long                  model_length    模型内存长度
 * @param[in]   const char*                 model_memory    模型内存地址
 * @param[in]   struct BDFaceGazeConf*      conf            配置对象地址
 * @return      enum BDFaceStatusCode       状态码
 */
DLL_API BDFaceStatusCode bdface_load_gaze(
        BDFaceInstance face_instance,
        const long model_length,
        const char* model_memory,
        struct BDFaceGazeConf* conf);

/**
 * @brief   卸载注意力检测能力
 * @param[in]   const BDFaceInstance    face_instance   sdk实例对象地址
 * @return      enum BDFaceStatusCode   状态码
 */
DLL_API BDFaceStatusCode bdface_unload_gaze(BDFaceInstance face_instance);

/**
 * @brief   注意力检测接口
 * @param[in]   const BDFaceInstance                face_instance   sdk实例对象地址
 * @param[in]   const struct BDFaceImageInstance*   img_instance    图像句柄
 * @param[in]   const struct BDFaceLandmarkList*    landmark_list   人脸关键点数据地址
 * @param[out]  struct BDFaceGazeInfoList**         gaze_list       注意力数据指针地址
 * @return      enum BDFaceStatusCode               状态码
 */
DLL_API BDFaceStatusCode bdface_gaze(
        const BDFaceInstance face_instance,
        const struct BDFaceImageInstance* image,
        const struct BDFaceLandmarkList* landmark_list,
        struct BDFaceGazeInfoList** gaze_list);

#ifdef __cplusplus
}

}
#endif

#endif
