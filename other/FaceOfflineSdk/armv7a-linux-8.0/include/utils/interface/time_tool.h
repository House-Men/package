/***************************************************************************
 * 
 * Copyright (c) 2018 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/

 /**
  * @file    timer_tool.h
  * @author  taotianran<taotianran@baidu.com>
  * @date    2019-01-27 09:15
  */

#include <chrono>
#include <time.h>

#ifndef UTILS_SRC_TIME_TOOL_H
#define UTILS_SRC_TIME_TOOL_H
#pragma once

#ifdef __cplusplus
namespace bdface {
    extern "C" {
#endif

struct TimeTool {
    /**
     * @brief   现在到2017.01.01年时间间隔毫秒数
     * @return  long long   毫秒数
     */
    static long long ms_since() {
        auto n = std::chrono::system_clock::now();
        auto m = n.time_since_epoch();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(m).count();
        return diff;
    }

    /**
     * @brief   设置开始时间锚点
     * @return  void
     */
    void tic() {
        start = std::chrono::high_resolution_clock::now();
    }
    
    /**
     * @brief   获得从开始时间锚点到现在的时间间隔（ms）
     * @return  double  毫秒数
     */
    double toc() {
        stop = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = stop - start;
        return diff.count() * 1000; //ms
    }
    
    /**
     * @brief   获取当前的unix时间戳（s）
     * @return  time_t  秒数
     */
    static time_t unix_now() {
        time_t timep;
        time(&timep);
        return timep;
    }

    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::chrono::time_point<std::chrono::high_resolution_clock> stop;
};

#ifdef __cplusplus
    }
}
#endif

#endif
