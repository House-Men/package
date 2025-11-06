#pragma once
#include <vector>

// 人脸框
struct FaceBox {
    int index;
    float center_x; //中心x坐标
    float center_y; //中心y坐标
    float width; //人脸宽度
    float height; // 人脸高度
    float score; //置信度
};

// 人脸关键点
struct Landmarks {
    int index;
    int size;
    float data[144];
    float score;
};
// 人脸跟踪信息
struct TrackFaceInfo
{
    unsigned long face_id;
    FaceBox box;
    Landmarks facelandmarks;
};

struct Feature {
    int size;
    float data[128];
};

// 深度特征值
struct RgbdFeature {
    int size;
    float data[256];
};

struct Emotion {
    int expression;    // 情绪
    float expression_conf;                // 对应的置信度
    float expression_conf_list[7];          // 所有情绪的置信度
};

// 光照
struct Illumination {
    float score;
};

// 模糊度
struct Blur {
    float score;
};

// 嘴巴闭合
struct MouthClose {
    float score;
};

// 口罩检测
struct MouthMask {
    float score;
};

// 最优人脸 
struct Best {
    float score;
};
// 人脸检测配置
struct DetectConf {
    int max_detect_num;                     // 需要检测的最大人脸数目
    float min_face_size;                    // 需要检测的最小人脸大小
    float not_face_threshold;               // 过滤非人脸的阈值
    float scale_ratio;                      // 输入图像的缩放系数
											//（检测分值大于该阈值认为是人脸）
};

struct LivenessScore
{
    float score; //分值
};

/**
* @brief   动作活体参数配置结构体
*/
struct ActionLiveConf {
    float eye_open_threshold;       // 睁眼的阈值
    float eye_close_threshold;      // 闭眼的阈值
    float mouth_open_threshold;     // 张嘴的阈值
    float mouth_close_threshold;    // 闭嘴的阈值
    float look_up_threshold;        // 抬头的阈值
    float look_down_threshold;      // 低头的阈值
    float turn_left_threshold;      // 向左转头的阈值
    float turn_right_threshold;     // 向右转头的阈值
    float nod_threshold;            // 点头的角度差阈值
    float shake_threshold;          // 摇头的角度差阈值
    int max_cache_num;                // 缓存的帧数
};

/**
* @brief   抠图参数配置
*/
struct CropFaceConf {
    int is_flat;         // 是否镜像
    int crop_size;       // 抠图大小
    float enlarge_ratio; // 抠图的倍数
};

/**
* @brief   人脸跟踪配置结构体
*/
struct TrackConf {
    float detect_intv_before_track;     // 未跟踪到人脸前的检测时间间隔
    float detect_intv_during_track;     // 已跟踪到人脸后的检测时间间隔
};

/**
* @brief   人脸表情属性枚举
*/
enum AttributeEmotionType {
    BDFACE_ATTRIBUTE_EMOTION_FROWN = 0,     // 皱眉
    BDFACE_ATTRIBUTE_EMOTION_SMILE = 1,     // 笑
    BDFACE_ATTRIBUTE_EMOTION_CALM = 2,      // 平静
};

/**
* @brief   人脸种族属性枚举
*/
enum Race {
    BDFACE_RACE_YELLOW = 0, // 黄种人
    BDFACE_RACE_WHITE = 1,  // 白种人
    BDFACE_RACE_BLACK = 2,  // 黑种人
    BDFACE_RACE_INDIAN = 3, // 印第安人
};

/**
* @brief   眼镜状态属性枚举
*/
enum Glasses {
    BDFACE_NO_GLASSES = 0,   // 无眼镜
    BDFACE_GLASSES = 1,      // 有眼镜
    BDFACE_SUN_GLASSES = 2,  // 墨镜
};

/**
* @brief   性别属性枚举
*/
enum Gender {
    BDFACE_GENDER_FEMAILE = 0, // 女性
    BDFACE_GENDER_MALE = 1,    // 男性
};


/**
* @brief   人脸属性结构体
*/
struct Attribute {
    int age;                      // 年龄
    Race race;                    // 种族
    AttributeEmotionType emotion; // 表情
    Glasses glasses;              // 戴眼镜状态
    Gender gender;                // 性别
};

/**
* @brief   人眼闭合状态结构体
*/
struct EyeClose {
    float left_eye_close_conf;      // 左眼闭合的置信度
    float right_eye_close_conf;     // 右眼闭合的置信度
};

/**
* @brief   双眼注意力信息
*/
enum GazeDirection {
    BDFACE_GAZE_DIRECTION_UP = 0,           // 向上看
    BDFACE_GAZE_DIRECTION_DOWN = 1,         // 向下看
    BDFACE_GAZE_DIRECTION_RIGHT = 2,        // 向右看
    BDFACE_GAZE_DIRECTION_LEFT = 3,         // 向左看
    BDFACE_GAZE_DIRECTION_FRONT = 4,        // 向前看
    BDFACE_GAZE_DIRECTION_EYE_CLOSE = 5,    // 闭眼
};

/**
* @brief 注意力信息
*/
struct Gaze {
    GazeDirection direction;      // 凝视方向
    float confidence;                   // 置信度
};

/**
* @brief   双眼注意力信息
*/
struct GazeInfo {
    Gaze left_eye;    // 左眼注意力信息
    Gaze right_eye;   // 右眼注意力信息
};

/**
* @brief   姿态角
*/
struct HeadPose {
    float yaw;        // 左右偏转角
    float roll;       // 与人脸平行平面内的头部旋转角
    float pitch;      // 上下偏转角
};

/**
* @brief   人脸遮挡信息结构体
*/
struct Occlusion {
    float left_eye;    // 左眼遮挡置信度
    float right_eye;   // 右眼遮挡置信度
    float nose;        // 鼻子遮挡置信度
    float mouth;       // 嘴巴遮挡置信度
    float left_cheek;  // 左脸遮挡置信度
    float right_cheek; // 右脸遮挡置信度
    float chin;        // 下巴遮挡置信度
};

/**
* @brief   动作活体类型枚举
*/
enum ActionLiveType {
    BDFACE_ACTION_LIVE_BLINK = 0,           // 眨眨眼
    BDFACE_ACTION_LIVE_OPEN_MOUTH = 1,      // 张张嘴
    BDFACE_ACTION_LIVE_NOD = 2,             // 点点头
    BDFACE_ACTION_LIVE_SHAKE_HEAD = 3,      // 摇摇头
    BDFACE_ACTION_LIVE_LOOK_UP = 4,         // 抬头
    BDFACE_ACTION_LIVE_TURN_LEFT = 5,       // 向左转
    BDFACE_ACTION_LIVE_TURN_RIGHT = 6,      // 向右转
};
