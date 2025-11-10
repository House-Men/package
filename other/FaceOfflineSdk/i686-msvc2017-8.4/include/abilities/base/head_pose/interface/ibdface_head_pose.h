/***************************************************************************
*
* Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
*
**************************************************************************/

/**
 * @file    ibdface_head_pose.h
 * @author  litonghui<litonghui@baidu.com>
 * @date    2019-02-20 16:22
 * @brief   人脸姿态角检测接口文件
 */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_framework.h"
#include "nn/interface/ibdface_inference.h"

#ifndef INTERFACE_IBDFACE_HEAD_POSE_H
#define INTERFACE_IBDFACE_HEAD_POSE_H
#pragma once

#ifdef __cplusplus
namespace bdface {

extern "C" {
#endif

/**
 * @brief   姿态角
 */
struct BDFaceHeadPose {
    float yaw;        // 左右偏转角
    float roll;       // 与人脸平行平面内的头部旋转角
    float pitch;      // 上下偏转角
};

/**
 * @brief   姿态角数据列表
 */
struct BDFaceHeadPoseList {
    int num;                // 姿态角个数
    BDFaceHeadPose* poses;  // 姿态角数据指针
};

/**
 * @brief   加载人脸姿态角检测能力
 * @param[in]   BDFaceInstance      face_instance   sdk实例对象地址
 * @return      BDFaceStatusCode    状态码
 */
DLL_API enum BDFaceStatusCode bdface_load_head_pose(BDFaceInstance face_instance);

/**
 * @brief   卸载人脸姿态角检测能力
 * @param[in]   BDFaceInstance          face_instance   sdk实例对象地址
 * @return      enum BDFaceStatusCode   状态码
 */
DLL_API enum BDFaceStatusCode bdface_unload_head_pose(BDFaceInstance face_instance);

/**
 * @brief   人脸姿态角检测
 * @param[in]   const BDFaceInstance                face_instance   sdk实例对象地址
 * @param[in]   const struct BDFaceLandmarkList*    landmark_list   关键点数据地址
 * @param[out]  struct BDFaceHeadPose**             head_pose       姿态角数据指针地址
 * @return      enum BDFaceStatusCode               状态码
 */
DLL_API enum BDFaceStatusCode bdface_head_pose(
        const BDFaceInstance face_instance,
        const struct BDFaceLandmarkList *landmark_list,
        struct BDFaceHeadPoseList** head_pose_list);

#ifdef __cplusplus
}

}
#endif

#endif
