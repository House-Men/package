/***************************************************************************
*
* Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
*
**************************************************************************/

/**
 * @file    ibdface_license.h
 * @author  zhangwenming02@baidu.com
 * @date    2019/01/28 14:32:57
 * @brief   授权接口文件
 *
 **/

#include <vector>
#include "utils/interface/DLL_API.h"
#include "license/bdlicense/include/bd_license_defs.h"

#ifndef INTERFACE_IBDFACE_LICENSE_H
#define INTERFACE_IBDFACE_LICENSE_H
#pragma once

#ifdef __cplusplus
namespace bdface {

extern "C" {
#endif

/**
 * @brief   从授权文件读取授权信息进行授权
 * @param[in]   const std::string&      license_key     license key
 * @param[in]   const std::string&      license_path    授权文件路径
 * @param[in]   bool                    is_remote       是否允许网络授权
 * @return      vis_license::ErrorCode  状态码
 */
DLL_API vis_license::ErrorCode bdface_auth_from_file(
        const std::string& license_key,
        const std::string& license_path,
        bool is_remote);

/**
 * @brief   从内存中读取授权信息进行授权
 * @param[in]   const std::string&              license_key     license key
 * @param[in]   const std::vector<std::string>  license_str     license信息
 * @param[in]   const std::string&              license_path
 * @return      vis_license::ErrorCode          状态码
 */
DLL_API vis_license::ErrorCode bdface_auth_from_memory(
        const std::string& license_key,
        const std::vector<std::string>& license_str,
        const std::string& license_path);

/**
 * @brief   获取本地授权信息
 * @return  vis_license::BDLicenseLocalInfo     授权信息
 */
DLL_API vis_license::BDLicenseLocalInfo bdface_auth_get_local_info();

/**
 * @brief   获取本地授权信息
 * @return  vis_license::BDLicenseLocalInfo     授权信息
 */
DLL_API vis_license::BDLicenseAuthInfo bdface_auth_get_auth_info();

/**
 * @brief   获取授权日志信息
 * @return  std::string     授权日志
 */
DLL_API std::string bdface_auth_get_error_msg();

#ifdef __cplusplus
}

}
#endif

#endif
