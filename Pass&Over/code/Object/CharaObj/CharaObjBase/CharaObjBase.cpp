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
    //処理なし
}

void CharaObjBase::RotateYAxis(const VECTOR aimDir, float velocity)
{
    //現方向が目標方向でなければ回転中にする
    if (objDir != aimDir)
    {
        nowRotate = true;
    }

    //目標方向まで回転処理

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
    //角速度をラジアン角にして、回転方向を算出
    rotRad = math::DegToRad(velocity);
    if (VCross(objDir, aimDir).y < 0)
    {
        return -rotRad;
    }
    return rotRad;
}

