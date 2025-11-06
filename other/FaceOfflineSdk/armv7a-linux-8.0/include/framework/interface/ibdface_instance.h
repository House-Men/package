/***************************************************************************
 *
 * Copyright (c) 2018 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

 /**
  * @file       ibdface_instance.h
  * @author     taotianran<taotianran@baidu.com>
  * @created    2019-01-07 10:32
  * @brief
  */

#include "utils/interface/DLL_API.h"
#include "ibdface_common.h"

#ifndef INTERFACE_IBDFACE_INSTANCE_H
#define INTERFACE_IBDFACE_INSTANCE_H
#pragma once

#ifdef __cplusplus
namespace bdface {
    extern "C" {
#endif
        /**
         * @brief   创建SDK实例对象
         * @param[out]  BDFaceInstance          instance    指向SDK实例对象指针的指针
         * @return      enum BDFaceStatusCode   状态码
         */
        DLL_API enum BDFaceStatusCode bdface_create_instance(BDFaceInstance* instance);

        /**
         * @brief   销毁SDK实例对象
         * @param[in]   BDFaceInstance          instance    指向SDK实例对象的指针
         * @return      enum BDFaceStatusCode   状态码
         */
        DLL_API enum BDFaceStatusCode bdface_destroy_instance(BDFaceInstance instance);
#ifdef __cplusplus
    }
}
#endif

#endif
