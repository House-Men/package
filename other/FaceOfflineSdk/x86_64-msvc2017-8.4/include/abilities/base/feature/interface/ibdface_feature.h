/***************************************************************************
*
* Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
*
**************************************************************************/

/**
 * @file        ibdface_feature.h
 * @author      yangrui09<yangrui09@baidu.com>
 * @created     2019-02-15
 * @brief       特征值提取和比对接口文件
 */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_framework.h"
#include "nn/interface/ibdface_inference.h"
#include "abilities/base/align/interface/ibdface_align.h"

#ifndef INTERFACE_IBDFACE_FEATURE_H
#define INTERFACE_IBDFACE_FEATURE_H
#pragma once

#ifdef __cplusplus
namespace bdface {

extern "C" {
#endif

/**
 * @brief	人脸feature数据结构体
 */
struct BDFaceFeature {
    int size;               // feature维度
    float* data;            // feature的数据指针
};

/**
 * @brief   人脸feature数据列表
 */
struct BDFaceFeatureList {
    int num;                    // feature个数
    BDFaceFeature* features;    // feature数据指针
};

/**
 * @brief	识别的枚举类型
 */
enum BDFaceFeatureType {
    BDFACE_FEATURE_TYPE_LIVE_PHOTO = 0,     // 生活照特征提取
    BDFACE_FEATURE_TYPE_ID_PHOTO = 1,       // 证件照特征提取
    BDFACE_FEATURE_TYPE_NIR = 2,       // 证件照特征提取
    BDFACE_FEATURE_TYPE_RGBD = 3,       // 证件照特征提取
};

/**
 * @brief	人脸feature配置参数结构体
 */
struct BDFaceFeatureConf {
    struct BDFaceInferenceConf infer_conf;
};

/**
 * @brief	获取默认配置参数
 * @param[in]   enum BDFaceFeatureType      type    人脸识别类型
 * @param[out]  struct BDFaceFeatureConf*   conf    配置对象地址
 * @return      enum BDFaceStatusCode       状态码
 */
DLL_API enum BDFaceStatusCode bdface_feature_get_default_conf(
        enum BDFaceFeatureType type,
        struct BDFaceFeatureConf* conf);

/**
 * @brief	加载特征提取能力
 * @param[in]	BDFaceInstance              face_instance   sdk实例对象地址
 * @param[in]   enum BDFaceFeatureType      type            人脸识别类型
 * @param[in]   const long model_length     model_length    模型长度
 * @param[in]   const char*                 model_memory    模型内存地址
 * @param[in]   struct BDFaceFeatureConf*   conf            配置对象地址
 * @return      enum BDFaceStatusCode       状态码
 */
DLL_API enum BDFaceStatusCode bdface_load_feature(
        BDFaceInstance face_instance,
        enum BDFaceFeatureType type,
        const long model_length,
        const char* model_memory,
        struct BDFaceFeatureConf* conf);

/**
 * @brief   卸载人脸识别能力
 * @param[in]   const BDFaceInstance    face_instance   sdk实例对象地址
 * @param[in]   enum BDFaceFeatureType  type            人脸识别类型
 * @return      enum BDFaceStatusCode   状态码
 */
DLL_API enum BDFaceStatusCode bdface_unload_feature(
        BDFaceInstance face_instance,
        enum BDFaceFeatureType type);

/**
 * @brief   人脸特征提取接口
 * @param[in]   const BDFaceInstance                face_instance   sdk实例对象地址
 * @param[in]   const struct BDFaceImageInstance*   image    		图像句柄
 * @param[in]   enum BDFaceFeatureType              type            人脸识别类型
 * @param[in]   struct struct BDFaceLandmarkList*   landmark_list   人脸关键点数据地址
 * @param[out]  struct BDFaceFeatureList**          feature_list    特征值数据指针地址
 * @return      enum BDFaceStatusCode               状态码
 */
DLL_API enum BDFaceStatusCode bdface_feature(
        const BDFaceInstance face_instance,
        const struct BDFaceImageInstance* image,
        const enum BDFaceFeatureType type,
        const struct BDFaceLandmarkList* landmark_list,
        struct BDFaceFeatureList** feature_list);

/**
* @brief   人脸特征提取接口
* @param[in]   const BDFaceInstance                face_instance   sdk实例对象地址
* @param[in]   const struct BDFaceImageInstance*   image    		RGB图像句柄
* @param[in]   const struct BDFaceImageInstance*   image_depth    	Depth图像句柄
* @param[in]   enum BDFaceFeatureType              type            人脸识别类型
* @param[in]   struct struct BDFaceLandmarkList*   landmark_list   人脸关键点数据地址
* @param[out]  struct BDFaceFeatureList**          feature_list    特征值数据指针地址
* @return      enum BDFaceStatusCode               状态码
*/
DLL_API enum BDFaceStatusCode bdface_rgbd_feature(
        const BDFaceInstance face_instance,
        const struct BDFaceImageInstance* image,
        const struct BDFaceImageInstance* image_depth,
        const enum BDFaceFeatureType type,
        const struct BDFaceLandmarkList* landmark_list,
        struct BDFaceFeatureList** feature_list);

/**
 * @brief   人脸特征值比对接口
 * @param[in]   const BDFaceInstance            face_instance   sdk实例对象地址
 * @param[in]   const struct BDFaceFeature*     feature_first   人脸特征值数据地址
 * @param[in]   const struct BDFaceFeature*     feature_second  人脸特征值数据地址
 * @param[in]   const enum BDFaceFeatureType    type            特征值类型
 * @param[in]   int                             is_percent      是否转化为百分制
 *                                                              百分制：比对分值 0~100
 *                                                              小数：比对分值0~1
 * @param[out]  float*                          score           比对分值
 * @return      enum BDFaceStatusCode           状态码
 */
DLL_API enum BDFaceStatusCode bdface_feature_compare(
        const BDFaceInstance face_instance,
        const struct BDFaceFeature* feature_first,
        const struct BDFaceFeature* feature_second,
        const enum BDFaceFeatureType type,
        int is_percent,
        float* score);

/**
* @brief   人脸特征值比对分值映射接口
* @param[in]   const BDFaceInstance            face_instance   sdk实例对象地址
* @param[in]   const enum BDFaceFeatureType    type            特征值类型
* @param[in]   float                           cosin_score     小数：比对分值0~1
* @param[out]  float*                          score           百分制：比对分值 0~100
* @return      enum BDFaceStatusCode           状态码
*/
DLL_API enum BDFaceStatusCode bdface_percent_map(
        const BDFaceInstance face_instance,
        const enum BDFaceFeatureType type,
        float cosin_score,
        float* score);

#ifdef __cplusplus
}

}
#endif

#endif
