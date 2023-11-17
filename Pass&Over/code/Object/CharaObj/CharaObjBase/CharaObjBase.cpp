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
    aimDir = dir;
    if (objDir != aimDir)
    {
        nowRotate = true;
    }

    //�ڕW�����܂ŉ�]����
    if (VDot(objDir, aimDir) < 1.0f)
    {
        rotYRad += CalcRotDir(velocity);
        objDir = VTransform(objDir, rotYMat);
        rotateMat = MMult(MGetScale(objScale), MGetRotY(rotYRad-math::DegToRad(PI_RAD / 2)));
    }
    else
    {
        objDir = aimDir;
        nowRotate = false;
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

