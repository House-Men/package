/***************************************************************************
*
* Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
*
**************************************************************************/

/**
 * @file        ibdface_track.h
 * @author      yangrui09<yangrui09@baidu.com>
 * @created     2019-02-15 23:20
 */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_framework.h"
#include "abilities/base/align/interface/ibdface_align.h"
#include "abilities/base/detect/interface/ibdface_detect.h"

#ifndef INTERFACE_IBDFACE_TRACK_H
#define INTERFACE_IBDFACE_TRACK_H
#pragma once

#ifdef __cplusplus
namespace bdface {

extern "C" {
#endif
        /**
         * @brief   人脸跟踪配置结构体
         */
        struct BDFaceTrackConf {
            float detect_intv_before_track;     // 未跟踪到人脸前的检测时间间隔
            float detect_intv_during_track;     // 已跟踪到人脸后的检测时间间隔
        };

        /**
         * @brief	人脸跟踪数据结构体
         */
        struct BDFaceTrackInfo {
            int face_id;                // 已跟踪的人脸id标识
            BDFaceBBox box;             // 已跟踪的人脸框信息
            BDFaceLandmark landmark;    // 已跟踪的人脸的关键点信息
        };

        /**
         * @brief     人脸跟踪信息列表结构
         */
        struct BDFaceTrackInfoList {
            int num;                        // 已跟踪的人脸数量
            BDFaceTrackInfo* track_info;    // 已跟踪的人脸信息列表
        };

        /**
         * @brief	默认配置
         */
        DLL_API enum BDFaceStatusCode bdface_track_get_default_conf(
                struct BDFaceTrackConf* conf,
                enum BDFaceDetectType detect_type,
                enum BDFaceAlignType align_type);

	    /**
	     * @brief	    加载模型
	     * @param[in]   face_instance                                sdk实例对象指针
         * @param[in]   struct BDFaceTrackConf*      conf            配置
         * @return      enum BDFaceStatusCode        状态码          人脸识别模型加载结果
	     */
        DLL_API enum BDFaceStatusCode bdface_load_track(
                BDFaceInstance face_instance,
                enum BDFaceDetectType detect_type,
                enum BDFaceAlignType align_type,
                struct BDFaceTrackConf* conf);

	    /**
	     * @brief       卸载人脸跟踪能力
         * @param[in]   const BDFaceInstance    face_instance   sdk实例对象
         * @return      enum BDFaceStatusCode   状态码
	     */
        DLL_API enum BDFaceStatusCode bdface_unload_track(
                BDFaceInstance face_instance,
                enum BDFaceDetectType detect_type,
                enum BDFaceAlignType align_type);

	    /**
	     * @brief       人脸跟踪接口
         * @param[in]   const BDFaceInstance            face_instance       sdk实例对象
         * @param[in]   const BDFaceImageHandler        image    		    图像句柄
         * @param[out]  struct BDFaceTrackInfoList**    track_list          人脸跟踪结果列表
         * @return      enum BDFaceStatusCode           状态码
	     */
        DLL_API enum BDFaceStatusCode bdface_track(
                const BDFaceInstance face_instance,
                enum BDFaceDetectType detect_type,
                enum BDFaceAlignType align_type,
                const struct BDFaceImageInstance* image,
                struct BDFaceTrackInfoList** track_list);

	    /**
	     * @brief       清除跟踪的历史数据
         * @param[in]   const BDFaceInstance    face_instance   sdk实例对象
         * @return      enum BDFaceStatusCode   状态码
         */
        DLL_API enum BDFaceStatusCode bdface_track_clear_history(
                const BDFaceInstance face_instance,
                enum BDFaceDetectType detect_type,
                enum BDFaceAlignType align_type);
#ifdef __cplusplus
}

}
#endif

#endif
