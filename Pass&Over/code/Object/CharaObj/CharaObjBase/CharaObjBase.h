#pragma once
#include"../../ObjBase/ObjBase.h"

/// <summary>
/// CharaObjBase�N���X
/// </summary>
class CharaObjBase:public ObjBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="tag">:�^�O��</param>
    CharaObjBase(std::string tag);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~CharaObjBase();

protected:
    /// <summary>
    /// �f�[�^���t�@�C���p�X�擾����
    /// </summary>
    /// <param name="objData">:�擾�������I�u�W�F�N�g�f�[�^</param>
    /// <returns>�t�@�C���p�X</returns>
    const std::string GetFilePass(const rapidjson::Value& objData) { return objData[jsondata::dataKey.pass.c_str()].GetString(); }

    /// <summary>
    /// �L�������쏈��
    /// </summary>
    /// <param name="deltaTime">:�t���[�����[�g</param>
    //virtual void MoveChara(const float deltaTime);

    /// <summary>
    /// �L������]����
    /// </summary>
    /// <param name="speed">:��]���x</param>
    void RotateModel(float speed);

    const rapidjson::Value& modelData = model->GetJsonData()[objTag.c_str()];      //���f���p�X�f�[�^
    const rapidjson::Value& soundData = sound->GetJsonData()[objTag.c_str()];      //�T�E���h�p�X�f�[�^
    const rapidjson::Value& motionData = motion->GetJsonData()[objTag.c_str()];     //���[�V�����p�X�f�[�^
};

