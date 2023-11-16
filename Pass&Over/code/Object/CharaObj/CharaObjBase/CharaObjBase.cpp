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
        nowRotate = true;
    }
    rotRad += CalcRotDir(dir, velocity);

    //�ڕW�����܂ŉ�]����
    MATRIX rotScale = MGetScale(objScale);
    rotYMat = MGetRotY(rotRad);
    rotYMat = MGetRotVec2(objDir, VTransform(objDir, MMult(rotScale, rotYMat)));

    //if (VCross(objDir, dir).y < 0.0f)
    //{
    //    objDir = dir;
    //    nowRotate = false;
    //}
    rotateMat = MMult(rotScale, rotYMat);
}

float CharaObjBase::CalcRotDir(const VECTOR dir, float velocity)
{
    //��]�������Z�o
    velocity = math::DegToRad(velocity);
    if (VCross(objDir, dir).y < 0)
    {
        return velocity *= -1;
    }
    return velocity;
}

