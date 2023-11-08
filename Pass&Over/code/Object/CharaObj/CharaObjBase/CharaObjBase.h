#pragma once
#include"../../ObjBase/ObjBase.h"
#include"../../Math/Math.h"

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
    /// <param name="deltaTime">:�f���^�^�C��</param>
    virtual void MoveChara(const float deltaTime) = 0;

    /// <summary>
    /// �s�b�`��]����
    /// </summary>
    /// <param name="aimDir">:�ڕW�̌���</param>
    /// <param name="velocity">:�p���x</param>
    void RotatePitch(const VECTOR& aimDir, float velocity);

    /// <summary>
    /// ��]�����Z�o����
    /// </summary>
    /// <returns>:</returns>
    float CaldRotDir();

    float moveSpeed;                        //�ړ����x

    const VECTOR FRONT = { 1,0,0 };         //�O��
    const VECTOR BACK = { -1,0,0 };         //���
    const VECTOR LEFT = { 0,0,1 };          //��
    const VECTOR RIGHT = { 0,0,-1 };        //�E

    const float PI_RAD = 180;               //180�x
    bool nowRotate;                         //��]����
    float rotRad;                           //�p���x�̃��W�A���p
    float pitch;                            //�s�b�`(��])

    const rapidjson::Value& modelData = model->GetJsonData()[objTag.c_str()];      //���f���p�X�f�[�^
    const rapidjson::Value& soundData = sound->GetJsonData()[objTag.c_str()];      //�T�E���h�p�X�f�[�^
    const rapidjson::Value& motionData = motion->GetJsonData()[objTag.c_str()];     //���[�V�����p�X�f�[�^
};

