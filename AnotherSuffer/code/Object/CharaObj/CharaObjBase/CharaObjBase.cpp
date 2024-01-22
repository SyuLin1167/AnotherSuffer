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
    , rotYRad(-DX_PI_F / 2.0f)
{
    rotYMat = MGetRotY(rotYRad);
    rotateMat = MMult(MGetScale(objScale), rotYMat);
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
            rotYRad += CalcRotDir(velocity);
            objDir = VTransform(objDir, rotYMat);
            rotateMat = MMult(MGetScale(objScale), MGetRotY(rotYRad));
        }
        else
        {
            //�ڕW�����ɂ��ĉ�]��~
            rotateMat = MMult(MGetScale(objScale), MGetRotVec2(objDir, aimDir));
            objDir = aimDir;
            nowRotate = false;
        }
    }
}

void CharaObjBase::RotateXAxis(const VECTOR dir, float velocity)
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
            rotYRad += CalcRotDir(velocity);
            objDir = VTransform(objDir, rotYMat);
            rotateMat = MMult(MGetScale(objScale), MGetRotX(rotYRad));
        }
        else
        {
            //�ڕW�����ɂ��ĉ�]��~
            rotateMat = MMult(MGetScale(objScale), MGetRotVec2(objDir, aimDir));
            objDir = aimDir;
            nowRotate = false;
        }
    }
}

void CharaObjBase::RotateZAxis(const VECTOR dir, float velocity)
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
            rotYRad += CalcRotDir(velocity);
            objDir = VTransform(objDir, rotYMat);
            rotateMat = MMult(MGetScale(objScale), MGetRotZ(rotYRad));
        }
        else
        {
            //�ڕW�����ɂ��ĉ�]��~
            rotateMat = MMult(MGetScale(objScale), MGetRotVec2(objDir, aimDir));
            objDir = aimDir;
            nowRotate = false;
        }
    }
}

float CharaObjBase::CalcRotDir(float velocity)
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

