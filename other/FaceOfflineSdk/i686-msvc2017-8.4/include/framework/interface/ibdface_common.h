/***************************************************************************
*
* Copyright (c) 2018 Baidu.com, Inc. All Rights Reserved
*
**************************************************************************/

/**
 * @file    ibdface_common.h
 * @author  taotianran<taotianran@baidu.com>
 * @date    2019-01-07 10:53
 */

#ifndef INTERFACE_IBDFACE_COMMON_H
#define INTERFACE_IBDFACE_COMMON_H
#pragma once

#ifdef __cplusplus
namespace bdface {
    
extern "C" {
#endif
    
typedef void* BDFaceInstance;
    
enum BDFaceStatusCode {
    OK = 0,                             // 成功
    ILLEGAL_PARAMS = -1,                // 非法的参数
    MEMORY_ALLOCATION_FAILED = -2,      // 内存分配失败
    INSTANCE_IS_EMPTY = -3,             // 实例对象为空
    MODEL_IS_EMPTY = -4,                // 模型内容为空
    UNSUPPORT_ABILITY_TYPE = -5,        // 不支持的能力类型
    UNSUPPORT_INFER_TYPE = -6,          // 不支持的预测库类型
    NN_CREATE_FAILED = -7,              // 预测库对象创建失败
    NN_INIT_FAILED = -8,                // 预测库对象初始化失败
    IMAGE_IS_EMPTY = -9,                // 图像数据为空
    ABILITY_INIT_FAILED = -10,          // 人脸能力初始化失败
    ABILITY_UNLOAD = -11,               // 能力未加载
    ABILITY_ALREADY_LOADED = -12,       // 人脸能力已加载
    NOT_AUTHORIZED = -13,               // 未授权
    ABILITY_RUN_EXCEPTION = -14,        // 人脸能力运行异常
    UNSUPPORT_IMAGE_TYPE = -15,         // 不支持的图像类型
    IMAGE_TRANSFORM_FAILED = -16,       // 图像转换失败
};

#ifdef __cplusplus
}

}
#endif

#endif
