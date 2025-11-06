#ifndef FACEOFFLINESAMPLE_FACEOFFLINESAMPLE_BAIDU_FACE_API_H
#define FACEOFFLINESAMPLE_FACEOFFLINESAMPLE_BAIDU_FACE_API_H

#include <string>
#include <vector>
#include <iostream>
#include "struct_info.h"
#include "opencv2\opencv.hpp"
#include "img_instance/interface/ibdface_image_instance.h"

class IFaceApi;
class BaiduFaceApi
{
public:
    BaiduFaceApi();
    ~BaiduFaceApi();
    // 获取设备指纹
    void get_device_id(std::string& device_id);
    // 获取版本号
    void sdk_version(std::string& version);
    // sdk初始化
    int sdk_init(const char* model_path);
    int log_type();
    bool is_auth();
    
    // 人脸特性
    int face_attr(std::vector<Attribute> &out, const cv::Mat* mat);
    // 眼睛闭合检测
    int face_eye_close(std::vector<EyeClose> &out, const cv::Mat* mat);
    // 注意力检测
    int face_gaze(std::vector<GazeInfo> &out, const cv::Mat* mat);
    // 姿态角
    int face_head_pose(std::vector<HeadPose> &out, const cv::Mat* mat);
    // 光照检测
    int face_illumination(std::vector<Illumination> &out, const cv::Mat* mat);
    // 模糊度检测
    int face_blur(std::vector<Blur> &out, const cv::Mat* mat);
    // 嘴巴闭合检测
    int face_mouth_close(std::vector<MouthClose> &out, const cv::Mat* mat);
    // 口罩佩戴检测
    int face_mouth_mask(std::vector<MouthMask> &out, const cv::Mat* mat);
    // 遮挡度检测
    int face_occlusion(std::vector<Occlusion> &out, const cv::Mat* mat);
    // 暗光恢复
    int dark_enhance(cv::Mat&out, const cv::Mat* mat);
    // 人脸抠图
    int face_crop(cv::Mat&out, const cv::Mat* mat);
    // 最佳人脸
    int face_best(std::vector<Best> &out, const cv::Mat* mat);
    // 人脸关键点
    int face_landmark(std::vector<Landmarks> &out, const cv::Mat* mat, int type = 0);
    // 人脸跟踪
    int track(std::vector<TrackFaceInfo> &out, const cv::Mat *mat, int type = 0);
    // 人脸检测
    int detect(std::vector<FaceBox> &out, const cv::Mat* mat, int type = 0);
    // 动作活体
    int face_action_live(std::vector<FaceBox> &out, ActionLiveType type, int& action_result, const cv::Mat* mat);
    // 清除动作活体历史
    int action_live_clear_history();
    // 特征值提取
    int face_feature(std::vector<Feature> &out_fea, std::vector<FaceBox> &out_box, const cv::Mat* mat, int type = 0);
    // 特征值+活体 (type: 0 为rgb 1：为nir)
    int liveness_feature(std::vector<Feature> &out_fea, std::vector<FaceBox> &out_box, float& score, 
        const cv::Mat* mat, int type = 0);
    // 特征值+深度活体
    int depth_liveness_feature(std::vector<Feature> &out_fea, std::vector<FaceBox> &out_box, float& rgb_score,
        float & depth_score, const cv::Mat* rgb, const cv::Mat* depth);
   
    // 可见光静默活体
    int rgb_liveness(std::vector<FaceBox> &out, float &score, const cv::Mat* mat);
    // 近红外静默活体
    int nir_liveness(std::vector<FaceBox> &out, float &score, const cv::Mat* mat);
    // rgb+depth双目静默活体
    int rgb_depth_liveness(std::vector<FaceBox> &out, float &rgb_score,
        float &depth_score, const cv::Mat* rgb, const cv::Mat* depth);
    //人脸注册（图片帧)
    void user_add(std::string& res, const cv::Mat* img, const char* user_id, const char* group_id,
        const char* user_info = nullptr);
    // 人脸注册 （特征值)
    void user_add(std::string& res, Feature* f1, const char* user_id, const char* group_id,
        const char* user_info = nullptr);

    // 人脸更新
    void user_update(std::string& res, const cv::Mat* img, const char* user_id, const char* group_id,
        const char* user_info = nullptr);

    // 用户删除
    void user_delete(std::string& res, const char* user_id, const char* group_id);
    // 组添加
    void group_add(std::string& res, const char* group_id);
    // 组删除
    void group_delete(std::string& res, const char* group_id);
    // 查询用户信息
    void get_user_info(std::string& res, const char*user_id, const char* group_id);
    // 查询用户图片
    int get_user_image(cv::Mat &img, const char*user_id, const char* group_id);
    // 用户组列表查询
    void get_user_list(std::string& res, const char* group_id, int start = 0, int length = 100);
    // 组列表查询
    void get_group_list(std::string& res, int start = 0, int length = 100);
    // 人脸数量查询
    int db_face_count(const char* group_id = nullptr);
    // 人脸比对
    int match(const cv::Mat &img1, const cv::Mat &img2, int type = 0);
    // 人脸识别
    void identify(std::string& res, const cv::Mat* img, const char* group_id_list,
        const char* user_id, int type = 0);

    // 人脸识别（传入特征值)
    void identify(std::string& res, Feature* f1, const char* group_id_list,
        const char* user_id, int type = 0);

    // 人脸识别(传入特征值feature)(和整个库比较)
    void identify_with_all(std::string& res, const cv::Mat* img, int type = 0);
    // 人脸识别(传入特征值feature)(和整个库比较)
    void identify_with_all(std::string& res, Feature* f1, int type = 0);
    // 加载人脸库到内存
    bool load_db_face(); 
    // 特征值比对
    float compare_feature(Feature* f1, Feature* f2, int type = 0);
    void clear_track_history(int type = 0);
public:
    const bdface::BDFaceInstance face_instance();
private:
    IFaceApi *m_api = nullptr;
};
#endif

