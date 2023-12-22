#include<DxLib.h>

#include"../../ObjBase/ObjBase.h"
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
    , modelData(model->GetJsonData()[objTag.c_str()])
    , soundData(sound->GetJsonData()[objTag.c_str()])
    , motionData(motion->GetJsonData()[objTag.c_str()])
    , aimDir()
    , rotRad()
    , rotYRad(-DX_PI_F / 2)
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

