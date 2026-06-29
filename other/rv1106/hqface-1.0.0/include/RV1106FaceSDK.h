#ifndef _RV1106FaceSDK_H
#define _RV1106FaceSDK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>


#define RV1106_SDK_API __attribute__ ((visibility ("default")))

#define    NUM_LANDMARKS   5
#define    MAX_FACES_NUM   1
#define    UUID_LEN        64

   
#define    IMAGE_FORMAT_NV21       0
#define    IMAGE_FORMAT_BGR888     10
#define    IMAGE_FORMAT_RGB888     11


#define    BAD_FACE_POSE     102
#define    BAD_FACE_SIZE     103
#define    FACE_SPOOFING     105


#define    HQ_OK     0

#define    HQ_ERR_GENERIC              -0001  ///< 通用未知错误
#define    HQ_ERR_TRIAL_VERSION        -1100
#define    HQ_ERR_INVALID_PARAM        -1201  ///< 无效参数（空指针或数值越界）
#define    HQ_ERR_MALLOC_FAILED        -1202  ///< 内存分配失败（OOM）

#define    HQ_ERR_NOT_INITIALIZED      -2000  ///< 模块未初始化
#define    HQ_ERR_INVALID_HANDLE       -2001  ///< 无效句柄（句柄为NULL或已失效）
#define    HQ_ERR_ALREADY_EXISTS       -2002  ///< 资源已存在
#define    HQ_ERR_RESOURCE_EMPTY       -2003  ///< 资源为空

#define    HQ_ERR_OPEN_FILE            -3000  ///< 文件打开失败
#define    HQ_ERR_READ_IO              -3001  ///< 硬件/磁盘IO读取错误
#define    HQ_ERR_NETWORK_FAIL         -3002  ///< 网络连接异常
#define    HQ_ERR_AUTH_DENIED          -3003  ///< 鉴权失败或权限不足

#define    HQ_ERR_NOT_ACTIVATE         -9100
#define    HQ_ERR_ACTIVATE_FAILED      -9112


typedef struct rv1106_face_t
{
	int              track_id;
    float            rect_x;
    float            rect_y;
    float            rect_w;
    float            rect_h;
    float            landmarks[NUM_LANDMARKS*2];   //// xyxyxyxyxy
    float            confidence;

    int              face_id;
    char             face_uuid[UUID_LEN];
    int              face_uuid_len;
    // char             name[UUID_LEN];
    // int              name_len;
    float            similarity;
    int              res_code;
    uint64_t         track_start_at;   // must be 8 bytes
}rv1106_face;

typedef struct rv1106_enroll_face_t
{
	int             face_id;
	char            face_uuid[UUID_LEN];
    int             uuid_len;
}rv1106_enroll_face;

typedef struct rv1106_image_t
{
    unsigned char   *data;
    int             width;
    int             height;
    int             channel;
    int             stride;
	int             image_format;
	int             frame_id;
	int             mirror;
	int             rotate;
}rv1106_image;

typedef struct rv1106_face_list_t
{
    rv1106_face_t     faces[MAX_FACES_NUM];
    int cnt;
}rv1106_face_list;


RV1106_SDK_API int RV1106FaceInitLicense();

RV1106_SDK_API const char *RV1106FaceGetDeviceKey();

RV1106_SDK_API int RV1106FaceRequestSignatureV2(const char* host, int port, const char* product_id, const char* access_code, char **sign);

RV1106_SDK_API int RV1106FaceRequestSignatureRetail(const char* host, int port, const char* product_id, const char* sn, char **sign);

/////////////////////////////////
// identify
/////////////////////////////////
RV1106_SDK_API int RV1106FaceInit(const char* db_path, const char* sign);

RV1106_SDK_API int RV1106FaceUnInit();

// 设置红外活体参数
RV1106_SDK_API int RV1106SetIRLiveness(int en, float thres);

// 加载双目相机参数
RV1106_SDK_API int RV1106FaceLoadCameraParams(const char * param);

// 设置人脸识别阈值，推荐值为 0.8
RV1106_SDK_API int RV1106FaceSetThreshold(float thres);

// 双目追踪人脸，并自动识别
RV1106_SDK_API int RV1106FaceTrackDualCam(rv1106_image_t rgbImage, rv1106_image_t irImage, rv1106_face_list_t *pFaces);

/////////////////////////////////
// 人脸库管理
/////////////////////////////////
// 注册图片中最大人脸
RV1106_SDK_API int RV1106FaceEnrollByImage(const unsigned char* jpgdata, int jpglen, const char * uuid, rv1106_enroll_face_t *en_face);

// 注册当前追踪的人脸
RV1106_SDK_API int RV1106FaceEnrollByTrackID(int track_id, const char * uuid, rv1106_enroll_face_t *en_face);

// 根据 uuid 删除人脸
RV1106_SDK_API int RV1106FaceDeleteByUUID(const char * uuid);

// 清空人脸库
RV1106_SDK_API int RV1106FaceDeleteAll();

// 获取 人脸库中人脸数量
RV1106_SDK_API int RV1106FaceCountPerson();

// 获取 SDK 版本
RV1106_SDK_API const char* RV1106FaceSDKVersion();

#ifdef __cplusplus
}
#endif
#endif // _RV1106FaceSDK_H