#include<DxLib.h>

#include"../../ObjBase/ObjBase.h"
#include"../../../Asset/AssetManager/AssetManager.h"
#include"../../Math/Math.h"
#include "CharaObjBase.h"

static constexpr float SIMILAR_ANGLE = 0.999f;     //�����p
const float CharaObjBase::ROTATE_SPEED = 3.0f;     //��]���x

using namespace math;

CharaObjBase::CharaObjBase(std::string tag)
    :ObjBase(tag)
    , isMove(false)
    , moveSpeed()
    , nowRotate(false)
    , modelData(GetAssetPathData(AssetManager::ModelInstance()))
    , soundData(GetAssetPathData(AssetManager::SoundInstance()))
    , motionData(GetAssetPathData(AssetManager::MotionInstance()))
    , aimDir()
    , rotRad()
    , rotXRad()
    , rotYRad(-DX_PI_F / 2.0f)
    , rotZRad()
{
    rotXMat = MGetRotX(rotXRad);
    rotYMat = MGetRotY(rotYRad);
    rotZMat = MGetRotZ(rotZRad);
    rotateYMat = MMult(MGetScale(objScale), rotYMat);
}

CharaObjBase::~CharaObjBase()
{
    //�����Ȃ�
}

void CharaObjBase::RotateYAxis(const VECTOR dir, float velocity)
{
    //���������ڕW�����łȂ���Ή�]���ɂ���
    aimDir = dir;
    if (objDir != aimDir)
    {
        nowRotate = true;
    }

    //��]���Ȃ�
    if (nowRotate)
    {
        //�ڕW�����t�߂܂ŉ�]
        if (VDot(objDir, aimDir) < SIMILAR_ANGLE )
        {
            //��]�����Z�o���ăx�N�g���ƍs��̗�������]������
            rotYRad += CalcRotDirY(velocity);
            objDir = VTransform(objDir, rotYMat);
            rotateYMat = MGetRotY(rotYRad);
        }
        else
        {
            //�ڕW�����ɂ��ĉ�]��~
            rotateYMat =  MGetRotVec2(objDir, aimDir);
            objDir = aimDir;
            nowRotate = false;
        }
    }
}

void CharaObjBase::RotateXAxis(const VECTOR dir, float velocity)
{
    aimDir = dir;
    float rotDir = CalcRotDirX(velocity);

    //��]�����Z�o���ăx�N�g���ƍs��̗�������]������
    rotXRad += rotDir;
    objDir = VTransform(objDir, rotXMat);
    rotateXMat = MGetRotX(rotXRad);
}

void CharaObjBase::RotateToAimXAxis(const VECTOR dir, float velocity)
{
    //���������ڕW�����łȂ���Ή�]���ɂ���
    aimDir = dir;
    if (objDir != aimDir)
    {
        nowRotate = true;
    }

    //��]���Ȃ�
    if (nowRotate)
    {
        //�ڕW�����t�߂܂ŉ�]
        if (VDot(objDir, aimDir) < SIMILAR_ANGLE)
        {
            //��]�����Z�o���ăx�N�g���ƍs��̗�������]������
            rotXRad += CalcRotDirX(velocity);
            objDir = VTransform(objDir, rotXMat);
            rotateXMat = MGetRotX(rotXRad);
        }
        else
        {
            //�ڕW�����ɂ��ĉ�]��~
            rotateXMat =  MGetRotVec2(objDir, aimDir);
            objDir = aimDir;
            nowRotate = false;
        }
    }
}

void CharaObjBase::RotateZAxis(const VECTOR dir, float velocity)
{
    aimDir = dir;
    float rotDir = CalcRotDirZ(velocity);

    //��]�����Z�o���ăx�N�g���ƍs��̗�������]������
    rotZRad += rotDir;
    objDir = VTransform(objDir, rotZMat);
    rotateZMat = MGetRotZ(rotZRad);
}

void CharaObjBase::RotateToAimZAxis(const VECTOR dir, float velocity)
{
    //���������ڕW�����łȂ���Ή�]���ɂ���
    aimDir = dir;
    if (objDir != aimDir)
    {
        nowRotate = true;
    }

    //��]���Ȃ�
    if (nowRotate)
    {
        //�ڕW�����t�߂܂ŉ�]
        if (VDot(objDir, aimDir) < SIMILAR_ANGLE)
        {
            //��]�����Z�o���ăx�N�g���ƍs��̗�������]������
            rotZRad += CalcRotDirZ(velocity);
            objDir = VTransform(objDir, rotZMat);
            rotateZMat = MGetRotZ(rotZRad);
        }
        else
        {
            //�ڕW�����ɂ��ĉ�]��~
            rotateZMat = MGetRotVec2(objDir, aimDir);
            objDir = aimDir;
            nowRotate = false;
        }
    }
}

float CharaObjBase::CalcRotDirX(float velocity)
{
    //���W�A���p�ɂ��ĉ�]�s��֕ϊ�
    rotRad = math::DegToRad(velocity);
    rotXMat = MGetRotX(rotRad);

    //��]�������Z�o
    if (VCross(objDir, aimDir).y < 0)
    {
        rotXMat = MTranspose(rotXMat);
        return -rotRad;
    }
    return rotRad;
}

float CharaObjBase::CalcRotDirY(float velocity)
{
    //���W�A���p�ɂ��ĉ�]�s��֕ϊ�
    rotRad = math::DegToRad(velocity);
    rotYMat = MGetRotY(rotRad);

    //��]�������Z�o
    if (VCross(objDir, aimDir).y < 0)
    {
        rotYMat = MTranspose(rotYMat);
        return -rotRad;
    }
    return rotRad;
}

float CharaObjBase::CalcRotDirZ(float velocity)
{
    //���W�A���p�ɂ��ĉ�]�s��֕ϊ�
    rotRad = math::DegToRad(velocity);
    rotZMat = MGetRotZ(rotRad);

    //��]�������Z�o
    if (VCross(objDir, aimDir).y < 0)
    {
        rotZMat = MTranspose(rotZMat);
        return -rotRad;
    }
    return rotRad;
}

rapidjson::Value& CharaObjBase::GetAssetPathData(AssetBase* asset)
{
    //�C�ӂ̃A�Z�b�g�f�[�^�ɃI�u�W�F�N�g��������p�X�f�[�^������
    auto& jsonData = asset->GetJsonData();
    if (jsonData.HasMember(objTag.c_str()))
    {
        return jsonData[objTag.c_str()];
    }

    //�Ȃ������炩��̒l��Ԃ�
    rapidjson::Value null;
    null.Set(-1);
    return null;
}

