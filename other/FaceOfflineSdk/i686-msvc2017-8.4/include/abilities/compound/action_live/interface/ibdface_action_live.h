/***************************************************************************
*
* Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
*
**************************************************************************/

/**
 * @file        ibdface_action_live.h
 * @author      taotianran<taotianran@baidu.com>
 * @created     2019-10-30 10:01
 */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_framework.h"
#include "abilities/base/align/interface/ibdface_align.h"

#ifndef INTERFACE_IBDFACE_ACTION_LIVE_H
#define INTERFACE_IBDFACE_ACTION_LIVE_H
#pragma once

#ifdef __cplusplus
namespace bdface {
extern "C" {
#endif

/**
 * @brief   动作活体类型枚举
 */
enum BDFaceActionLiveType {
    BDFACE_ACTION_LIVE_BLINK = 0,           // 眨眨眼
    BDFACE_ACTION_LIVE_OPEN_MOUTH = 1,      // 张张嘴
    BDFACE_ACTION_LIVE_NOD = 2,             // 点点头
    BDFACE_ACTION_LIVE_SHAKE_HEAD = 3,      // 摇摇头
    BDFACE_ACTION_LIVE_LOOK_UP = 4,         // 抬头
    BDFACE_ACTION_LIVE_TURN_LEFT = 5,       // 向左转
    BDFACE_ACTION_LIVE_TURN_RIGHT = 6,      // 向右转
};

/**
 * @brief   动作活体参数配置结构体
 */
struct BDFaceActionLiveConf {
    float eye_open_threshold;       // 睁眼的阈值
    float eye_close_threshold;      // 闭眼的阈值
    float mouth_open_threshold;     // 张嘴的阈值
    float mouth_close_threshold;    // 闭嘴的阈值
    float look_up_threshold;        // 抬头的阈值
    float look_down_threshold;      // 低头的阈值
    float turn_left_threshold;      // 向左转头的阈值
    float turn_right_threshold;     // 向右转头的阈值
    float nod_threshold;            // 点头的角度差阈值
    float shake_threshold;          // 摇头的角度差阈值
    int max_cache_num;                // 缓存的帧数
};

/**
 * @brief   获取动作活体默认配置
 */
DLL_API enum BDFaceStatusCode bdface_action_live_get_default_conf(
        struct BDFaceActionLiveConf* conf);

/**
 * @brief   加载动作活体能力
 * @param[in]   BDFaceInstance                  face_instance   sdk实例对象地址
 * @param[in]   struct BDFaceActionLiveConf*    conf            配置参数
 * @return      enum BDFaceStatusCode           状态码
 */
DLL_API enum BDFaceStatusCode bdface_load_action_live(
        BDFaceInstance face_instance,
        struct BDFaceActionLiveConf* conf);

/**
 * @brief   卸载动作活体能力
 * @param[in]   BDFaceInstance          face_instance   sdk对象实例
 * @return      enum BDFaceStatusCode   状态码
 */
DLL_API enum BDFaceStatusCode bdface_unload_action_live(BDFaceInstance face_instance);

/**
 * @brief       动作活体检测接口
 * @param[in]   const BDFaceInstance                face_instance   sdk实例对象地址
 * @param[in]   const struct BDFaceImageInstance*   img_instance    图像句柄
 * @param[in]   const struct BDFaceLandmark*        landmark        关键点数据
 * @param[in]   enum BDFaceActionType               type            指定检测的动作活体类型
 * @param[out]  int*                                is_exist        是否存在该动作
 * @return      enum BDFaceStatusCode               状态码
 */
DLL_API enum BDFaceStatusCode bdface_action_live(
        const BDFaceInstance face_instance,
        const struct BDFaceImageInstance* img_instance,
        const struct BDFaceLandmark* landmark,
        enum BDFaceActionLiveType type,
        int* is_exist);

/**
 * @brief       清除动作活体检测历史数据
 * @param[in]   const BDFaceInstance    face_instance   sdk实例对象地址
 * @return      enum BDFaceStatusCode   状态码
 */
DLL_API enum BDFaceStatusCode bdface_action_live_clear_history(
        const BDFaceInstance face_instance);

#ifdef __cplusplus
}
}
#endif

#endif
