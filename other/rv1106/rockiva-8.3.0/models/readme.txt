目标检测模型（根据设备和目标类型选择一个）
object_detection_v3_cls8.data	目标检测（人形、人脸、机动车、非机动车、人头）用于人脸抓拍/车辆车牌识别+周界等，detModel设置为ROCKIVA_DET_MODEL_CLS8
object_detection_pfp.data       目标检测（人形、人脸、宠物），detModel设置为ROCKIVA_DET_MODEL_PFP
object_detection_pfp_lite.data  目标检测（人形、人脸、宠物）更轻量模型，适合室内等近距离使用，需重名为object_detection_pfp.data，detModel设置为ROCKIVA_DET_MODEL_PFP
baby_classifier.data		婴幼儿检测，detClasses需要设置为ROCKIVA_OBJECT_TYPE_BITMASK(ROCKIVA_OBJECT_TYPE_BABY)


人脸抓拍分析模型
face_quality_v2.data			人脸质量评分模型
face_quality_mask.data			人脸质量评分模型
face_mask_classify.data			人脸口罩判断模型

人脸识别相关模型
face_liveness_2d.data		     人脸活体检测模型
face_landmark5.data                  人脸关键点模型
face_recognition_lite.data           人脸特征提取模型（最小），使用需重命名为face_recognition.data
face_recognition_mid1.data           人脸特征提取模型（中等），使用需重命名为face_recognition.data
face_recognition_mid2.data           人脸特征提取模型（中等），使用需重命名为face_recognition.data
object_detection_pfp_for_recog.data  人脸检测用于人脸导库

