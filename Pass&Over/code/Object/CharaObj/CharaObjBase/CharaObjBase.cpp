#include "CharaObjBase.h"

using namespace math;

CharaObjBase::CharaObjBase(std::string tag)
    :ObjBase(tag)
    , isMove(false)
    , moveSpeed(0.0f)
    , nowRotate(false)
    , rotRad(0.0f)
{


}

CharaObjBase::~CharaObjBase()
{
    //�����Ȃ�
}

void CharaObjBase::RotateYAxis(const VECTOR dir, float velocity)
{
    //���������ڕW�����łȂ���Ή�]���ɂ���
    if (objDir != dir)
    {
        aimDir = dir;
        nowRotate = true;
        CalcRotDir(dir, velocity);
    }

    //�ڕW�����܂ŉ�]����
    if (VDot(objDir, aimDir) < 1.0f)
    {
        objDir = VTransform(objDir, rotYMat);
        rotRad += velocity;
    }
    else
    {
        objDir = aimDir;
        nowRotate = false;
    }
    rotateMat = MMult(MGetScale(objScale), rotYMat);
}

float CharaObjBase::CalcRotDir(const VECTOR dir, float velocity)
{
    //���W�A���p�ɕϊ�
    rotRad = math::DegToRad(velocity);
    rotYMat = MGetRotY(rotRad);

    //��]�������Z�o
    if (VCross(objDir, aimDir).y < 0)
    {
        rotYMat = MTranspose(rotYMat);
    }
    return velocity;
}

