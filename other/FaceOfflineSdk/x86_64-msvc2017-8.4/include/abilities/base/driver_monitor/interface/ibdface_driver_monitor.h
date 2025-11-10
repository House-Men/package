/***************************************************************************
 *
 * Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

 /**
  * @file    ibdface_driver_monitor.h
  * @author  zhangwenming<zhangwenming@baidu.com>
  * @date    2019-02-11 16:20
  * @brief   人脸驾驶行为检测接口文件
  */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_framework.h"
#include "nn/interface/ibdface_inference.h"
#include "../../detect/interface/ibdface_detect.h"

#ifndef INTERFACE_IBDFACE_DRIVER_MONITOR_H
#define INTERFACE_IBDFACE_DRIVER_MONITOR_H
#pragma once

#ifdef __cplusplus
namespace bdface {

extern "C" {
#endif

/**
 * @brief   驾驶行为检测参数配置结构体
 */
struct BDFaceDriverMonitorConf {
    struct BDFaceInferenceConf infer_conf; // 预测库相关配置
};

// 驾驶行为信息
struct BDFaceDriverMonitorInfo {
    float normal = 0;    // 行为正常
    float calling = 0;   // 打电话
    float drinking = 0;  // 喝水
    float eating = 0;    // 吃东西
    float smoking = 0;   // 抽烟
};

/**
 * @brief   驾驶行为信息列表
 */
struct BDFaceDriverMonitorList {
    int num;                                // 驾驶行为信息个数
    BDFaceDriverMonitorInfo* driver_infos;  // 驾驶行为信息数据指针
};

/**
 * @brief   获取默认参数配置
 * @param[in]   struct BDBDFaceDriverMonitorConf*    conf    配置对象地址
 * @return      BDFaceStatusCode            状态码
 */
DLL_API enum BDFaceStatusCode bdface_driver_monitor_get_default_conf(struct BDFaceDriverMonitorConf* conf);

/**
 * @brief   加载驾驶行为检测能力
 * @param[in]   BDFaceInstance              face_instance   sdk实例对象地址
 * @param[in]   const long                  model_length    模型内存长度
 * @param[in]   const char*                 model_memory    模型内存地址
 * @param[in]   struct BDFaceDriverMonitorConf*      conf            配置对象地址
 * @return      enum BDFaceStatusCode       状态码
 */
DLL_API enum BDFaceStatusCode bdface_load_driver_monitor(
        BDFaceInstance face_instance,
        const long model_length,
        const char* model_memory,
        struct BDFaceDriverMonitorConf* conf);

/**
 * @brief   卸载驾驶行为检测能力
 * @param[in]   BDFaceInstance          face_instance   sdk实例对象地址
 * @return      enum BDFaceStatusCode   状态码
 */
DLL_API enum BDFaceStatusCode bdface_unload_driver_monitor(BDFaceInstance face_instance);

/**
 * @brief   驾驶行为检测接口
 * @param[in]   const BDFaceInstance                face_instance   sdk实例对象地址
 * @param[in]   const struct BDFaceImageInstance    img_instance     图像句柄
 * @param[in]   const struct BDFaceLandmarkList*    landmark_list   人脸关键点数据地址
 * @param[out]  struct BDFaceDriverMonitorList**             driver_monitor_list       模糊度数据列表地址
 * @return      enum BDFaceStatusCode               状态码
 */
DLL_API enum BDFaceStatusCode bdface_driver_monitor(
        const BDFaceInstance face_instance,
        const struct BDFaceImageInstance* img_instance,
        const struct BDFaceBBoxList* box_list,
        struct BDFaceDriverMonitorList** driver_monitor_list);

#ifdef __cplusplus
}

}
#endif

#endif
