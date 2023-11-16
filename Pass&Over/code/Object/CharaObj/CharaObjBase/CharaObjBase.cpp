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

void CharaObjBase::RotateYAxis(const VECTOR aimDir, float velocity)
{
    //���������ڕW�����łȂ���Ή�]���ɂ���
    if (objDir != aimDir)
    {
        nowRotate = true;
    }

    //�ڕW�����܂ŉ�]����

    CalcRotDir(aimDir, velocity);

    MATRIX rotScale = MGetScale(objScale);;
    MATRIX rotYMat = MGetRotY(rotRad);

    objDir = VTransform(objDir, rotYMat);
    if (VCross(objDir, aimDir).y < 0.0f)
    {
        objDir = aimDir;
        nowRotate = false;
    }

    rotateMat = MMult(rotScale, rotYMat);
}

float CharaObjBase::CalcRotDir(const VECTOR aimDir, float velocity)
{
    //�p���x�����W�A���p�ɂ��āA��]�������Z�o
    rotRad = math::DegToRad(velocity);
    if (VCross(objDir, aimDir).y < 0)
    {
        return -rotRad;
    }
    return rotRad;
}

