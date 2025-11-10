/***************************************************************************
 *
 * Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

 /**
  * @file    ibdface_attribute.h
  * @author  zhangjifeng<zhangjifeng@baidu.com>
  * @date    2019-02-18 10:20
  * @brief   人脸属性检测接口文件
  */

#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_framework.h"
#include "nn/interface/ibdface_inference.h"
#include "../../align/interface/ibdface_align.h"

#ifndef INTERFACE_IBDFACE_ATTRIBUTE_H
#define INTERFACE_IBDFACE_ATTRIBUTE_H
#pragma once

#ifdef __cplusplus
namespace bdface {

extern "C" {
#endif

/**
 * @brief   人脸表情属性枚举
 */
enum BDFaceAttributeEmotionType {
    BDFACE_ATTRIBUTE_EMOTION_FROWN = 0,     // 皱眉
    BDFACE_ATTRIBUTE_EMOTION_SMILE = 1,     // 笑
    BDFACE_ATTRIBUTE_EMOTION_CALM = 2,      // 平静
};

/**
 * @brief   人脸种族属性枚举
 */
enum BDFaceRace {
    BDFACE_RACE_YELLOW = 0, // 黄种人
    BDFACE_RACE_WHITE = 1,  // 白种人
    BDFACE_RACE_BLACK = 2,  // 黑种人
    BDFACE_RACE_INDIAN = 3, // 印第安人
};

/**
 * @brief   眼镜状态属性枚举
 */
enum BDFaceGlasses {
    BDFACE_NO_GLASSES = 0,   // 无眼镜
    BDFACE_GLASSES = 1,      // 有眼镜
    BDFACE_SUN_GLASSES = 2,  // 墨镜
};

/**
 * @brief   性别属性枚举
 */
enum BDFaceGender {
    BDFACE_GENDER_FEMAILE = 0, // 女性
    BDFACE_GENDER_MALE = 1,    // 男性
};

/**
 * @brief   人脸属性结构体
 */
struct BDFaceAttribute {
    int age;                            // 年龄
    BDFaceRace race;                    // 种族
    BDFaceAttributeEmotionType emotion; // 表情
    BDFaceGlasses glasses;              // 戴眼镜状态
    BDFaceGender gender;                // 性别
};

/**
 * @brief   人脸属性数据列表
 */
struct BDFaceAttributeList {
    int num;                                // 人脸属性数量
    struct BDFaceAttribute* attributes;     // 人脸属性数据指针
};

/**
 * @brief   人脸属性参数配置结构体
 */
struct BDFaceAttributeConf {
    struct BDFaceInferenceConf infer_conf; // 预测库配置
};

/**
 * @brief   获取默认参数配置
 * @param[in]   struct BDFaceAttributeConf* conf    配置对象地址
 * @return      enum BDFaceStatusCode       状态码
 */
DLL_API enum BDFaceStatusCode bdface_attribute_get_default_conf(
        struct BDFaceAttributeConf* conf);

/**
 * @brief   加载人脸属性检测能力
 * @param[in]   BDFaceInstance              face_instance   sdk实例对象地址
 * @param[in]   const long                  model_length    模型内存长度
 * @param[in]   const char*                 model_memory    模型内存地址
 * @param[in]   struct BDFaceAttributeConf* conf            配置对象地址
 * @return      enum BDFaceStatusCode       状态码
 */
DLL_API enum BDFaceStatusCode bdface_load_attribute(
        BDFaceInstance face_instance,
        const long model_length,
        const char* model_memory,
        struct BDFaceAttributeConf* conf);

/**
 * @brief   卸载人脸属性检测能力
 * @param[in]   BDFaceInstance          face_instance   sdk实例对象地址
 * @return      enum BDFaceStatusCode   状态码
 */
DLL_API enum BDFaceStatusCode bdface_unload_attribute(BDFaceInstance face_instance);

/**
 * @brief   人脸属性检测接口
 * @param[in]   const BDFaceInstance                face_instance   sdk实例对象地址
 * @param[in]   const struct BDFaceImageInstance    img_instance    图像句柄
 * @param[in]   struct BDFaceLandmarkList*          landmark_list   人脸关键点数据地址
 * @param[out]  struct BDFaceAttributeList**        attr_list       人脸属性数据指针地址
 * @return      enum BDFaceStatusCode               状态码
 */
DLL_API enum BDFaceStatusCode bdface_attribute(
        const BDFaceInstance face_instance,
        const struct BDFaceImageInstance* img_instance,
        const struct BDFaceLandmarkList* landmark_list,
        struct BDFaceAttributeList** attr_list);

#ifdef __cplusplus
}

}
#endif

#endif
