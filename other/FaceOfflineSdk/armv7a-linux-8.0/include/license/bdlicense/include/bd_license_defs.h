/**
 * @file license_define.hpp
 * @author zhangwenming02@baidu.com
 * @date 2019/01/28
 * @brief 
 *  
 **/

#pragma once

#include <iostream>
#include <string>

namespace vis_license {
    enum class ErrorCode {
        SUCCESS = 0,
        LICENSE_NOT_INIT_ERROR = 1,
        LICENSE_DECRYPT_ERROR = 2,
        LICENSE_INFO_FORMAT_ERROR = 3,
        LICENSE_KEY_CHECK_ERROR = 4,
        LICENSE_ALGORITHM_CHECK_ERROR = 5,
        LICENSE_MD5_CHECK_ERROR = 6,
        LICENSE_DEVICE_ID_CHECK_ERROR = 7,
        LICENSE_PACKAGE_NAME_CHECK_ERROR = 8,
        LICENSE_EXPIRED_TIME_CHECK_ERROR = 9,
        LICENSE_FUNCTION_CHECK_ERROR = 10,
        LICENSE_TIME_EXPIRED = 11,
        LICENSE_LOCAL_FILE_ERROR = 12,
        LICENSE_REMOTE_DATA_ERROR = 13,
        LICENSE_LOCAL_TIME_ERROR = 14,
        LICENSE_PARAM_ERROR = 15,
        OTHER_ERROR = 1000
    };

    struct BDLicenseLocalInfo {
        std::string _license_key;          // 用户设定的license key
        int _algorithm_id;                 // SDK使用的算法ID
        std::string _package_name;         // 本地包名
        std::string _md5;                  // 本地包MD5签名
        std::string _device_id;            // 本地设备ID
        std::string _finger_version;       // 获取设备指纹库版本号
        std::string _license_sdk_version;  // 鉴权库版本号
    };

    struct BDLicenseAuthInfo {
        std::string _license_key;      // 授权license key
        int _algorithm_id;             // 授权算法ID
        std::string _package_name;     // 授权包名
        std::string _md5;              // 授权包MD5签名
        std::string _device_id;        // 授权设备ID
        std::string _function_list;    // 功能授权信息
        int64_t _expire_time;          // 过期时间
    };

}  // end  namespace LICENSE_NAMESPACE
