#ifndef BAIDU_FACE_API_H
#define BAIDU_FACE_API_H
#include "struct_info.h"
#include "opencv2/opencv.hpp"
#include "img_instance/interface/ibdface_image_instance.h"

#ifdef __cplusplus
extern "C" {
#endif

class IFaceApi;
class BaiduFaceApi {
public:
    BaiduFaceApi();
    ~BaiduFaceApi();
    void get_device_id(std::string& device_id);
    void sdk_version(std::string& version);
    int sdk_init(const char* model_path);
    bool is_log_open();
    bool is_auth();

    // 人脸属性
    int face_attr(std::vector<Attribute> &out, const cv::Mat* mat);
    // 眼睛闭合检测
    int face_eye_close(std::vector<EyeClose> &out, const cv::Mat* mat);
    // 注意力检测
    int face_gaze(std::vector<GazeInfo> &out, const cv::Mat* mat);
    // 姿态角检测
    int face_head_pose(std::vector<HeadPose> &out, const cv::Mat* mat);
    // 光照检测
    int face_illumination(std::vector<Illumination> &out, const cv::Mat* mat);
    // 模糊检测
    int face_blur(std::vector<Blur> &out, const cv::Mat* mat);
    // 嘴巴闭合检测
    int face_mouth_close(std::vector<MouthClose> &out, const cv::Mat* mat);
    // 口罩佩戴检测
    int face_mouth_mask(std::vector<MouthMask> &out, const cv::Mat* mat);
    // 遮挡检测
    int face_occlusion(std::vector<Occlusion> &out, const cv::Mat* mat);

    int face_emotion(std::vector<Emotion> &out, const cv::Mat *mat);
    // 暗光恢复
    int dark_enhance(cv::Mat&out, const cv::Mat* mat);
    // 驾驶行为检测
    int driver_monitor(std::vector<DriverMonitor> &out, 
            const cv::Mat *mat);
    // 安全带佩戴检测
    int safety_belt(std::vector<SafetyBelt>& out, const cv::Mat* mat);
    // 人脸抠图
    int face_crop(cv::Mat&out, const cv::Mat* mat);
    // 最优人脸检测
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
    // 人脸特征值
    int face_feature(std::vector<Feature> &out_fea, std::vector<FaceBox> &out_box, const cv::Mat* mat, int type = 0);
    // 人脸特征值+rgb活体检测
    int liveness_feature(std::vector<Feature> &out_fea, std::vector<FaceBox> &out_box, float& score, const cv::Mat* mat, int type = 0);
    // rgb+depth的特征值
    int rgbd_feature(std::vector<RgbdFeature> &out_fea, std::vector<FaceBox> &out_box, const cv::Mat* rgb, char* depth);
    // rgb单目活体
    int rgb_liveness(std::vector<TrackFaceInfo> &out, float &score, const cv::Mat* mat);
    // nir单目活体
    int nir_liveness(std::vector<TrackFaceInfo> &out, float &score, const cv::Mat* mat);
    // rgb+depth双目活体
    int rgb_depth_liveness(std::vector<TrackFaceInfo> &out, float &rgb_score, 
            float &depth_score, const cv::Mat* rgb, char* depth);

    // 人脸注册（传图片帧)
    void user_add(std::string& res, const cv::Mat* img, const char* user_id, const char* group_id,
        const char* user_info = nullptr);
    // 人脸注册（传特征值）
    void user_add(std::string& res, Feature* f1, const char* user_id, const char* group_id,
        const char* user_info = nullptr);

    // 人脸更新
    void user_update(std::string&res, const cv::Mat *img, const char* user_id, const char* group_id,
        const char* user_info = nullptr);

    // 人脸删除
    void user_delete(std::string&res, const char* user_id, const char* group_id);
    // 组添加
    void group_add(std::string& res, const char* group_id);
    // 组删除
    void group_delete(std::string& res, const char* group_id);
    
    // 查询用户图片
    int get_user_image(cv::Mat &img, const char*user_id, const char* group_id);
    // 获取用户信息
    void get_user_info(std::string& res, const char*user_id, const char* group_id);
    // 获取用户列表
    void get_user_list(std::string& res, const char* group_id, int start = 0, int length = 100);
    // 获取组列表
    void get_group_list(std::string& res, int start = 0, int length = 100);

    // 人脸数量查询
    int db_face_count(const char* group_id = nullptr);
    // 人脸1：1比对
    int match(const cv::Mat &img1, const cv::Mat &img2, int type = 0);
    // 人脸识别 （传图片帧）
    void identify(std::string& res, const cv::Mat* img, const char* group_id_list,
        const char* user_id, int type = 0);
    // 人脸识别（传特征值）
    void identify(std::string& res, Feature* f1, const char* group_id_list,
        const char* user_id, int type = 0);
    // 人脸识别(传入图片帧)(和整个库比较)
    void identify_with_all(std::string& res, const cv::Mat* img, int type = 0);

    // 人脸识别(传入特征值)(和整个库比较)
    void identify_with_all(std::string& res, Feature* f1, int type = 0);
    // 加载人脸库到内存
    bool load_db_face(); 
    // 特征值比对
    float compare_feature(Feature* f1, Feature* f2, int type = 0);
    // 清除人脸跟踪历史
    void clear_track_history(int type = 0);
private:
    IFaceApi *g_api = nullptr;
};

#ifdef __cplusplus
}    
#endif

#endif

