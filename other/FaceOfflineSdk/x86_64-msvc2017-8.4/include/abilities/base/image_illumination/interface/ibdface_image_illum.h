/***************************************************************************
 *
 * Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

/**
 * @file    ibdface_image_illum.h
 * @author  v_shishuaifeng<v_shishuaifeng@baidu.com>
 * @date    2020-10-15 10:20
 * @brief   图像光照强度检测接口文件
 */
#include "utils/interface/DLL_API.h"
#include "framework/interface/ibdface_framework.h"

#ifndef INTERFACE_IBDFACE_IMAGE_ILLUM_H
#define INTERFACE_IBDFACE_IMAGE_ILLUM_H
#pragma once

#ifdef __cplusplus
namespace bdface {
extern "C" {
#endif

/**
 * @brief   图像光照强度检测接口
 * @param[in]   const struct BDFaceImageInstance*   img_instance    图像句柄
 * @param[out]  int*                                illum_score     光照强度数据指针
 * @return      enum BDFaceStatusCode               状态码
 */
DLL_API enum BDFaceStatusCode bdface_image_illumination(
        const struct BDFaceImageInstance* img_instance,
        int* illum_score);

#ifdef __cplusplus
}
}
#endif

#endif
