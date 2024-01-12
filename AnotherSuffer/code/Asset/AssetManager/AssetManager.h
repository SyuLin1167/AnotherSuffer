#pragma once
#include<memory>

#include"../Graph/Graph.h"
#include"../Model/Model.h"
#include"../Motion/Motion.h"
#include"../Sound/Sound.h"

/// <summary>
/// �A�Z�b�g�Ǘ�
/// </summary>
class AssetManager final
{
public:
    /// <summary>
    /// �A�Z�b�g�}�l�[�W���[������
    /// </summary>
    static void InitAssetManager();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~AssetManager();

    /// <summary>
    /// �O���t�C���X�^���X
    /// </summary>
    /// <returns>Graph�N���X</returns>
    static class Graph* GraphInstance(){return singleton->graph.get(); }

    /// <summary>
    /// ���f���C���X�^���X
    /// </summary>
    /// <returns>Model�N���X</returns>
    static class Model* ModelInstance(){ return singleton->model.get(); }

    /// <summary>
    /// ���[�V�����C���X�^���X
    /// </summary>
    /// <returns>Motion�N���X</returns>
    static class Motion* MotionInstance(){ return singleton->motion.get(); }

    /// <summary>
    /// �T�E���h�C���X�^���X
    /// </summary>
    /// <returns>Sound�N���X</returns>
    static class Sound* SoundInstance(){ return singleton->sound.get(); }

    /// <summary>
    /// �f�[�^���t�@�C���p�X�擾
    /// </summary>
    /// <param name="objData">:�擾�������I�u�W�F�N�g�f�[�^</param>
    /// <returns>�t�@�C���p�X</returns>
    static const std::string GetFilePass(const rapidjson::Value& objData)
    {
        return objData[jsondata::dataKey.pass.c_str()].GetString();
    }

private:
    /// <summary>
    /// �R���X�g���N�^(�V���O���g��)
    /// </summary>
    AssetManager();

    static std::unique_ptr<AssetManager> singleton;      //���g�̎���

    std::unique_ptr<class Graph> graph;                           //�摜
    std::unique_ptr<class Model> model;                           //���f��
    std::unique_ptr<class Motion> motion;                         //���[�V����
    std::unique_ptr<class Sound> sound;                           //�T�E���h
};

