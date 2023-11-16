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

void CharaObjBase::RotateYAxis(const VECTOR dir, float velocity)
{
    //現方向が目標方向でなければ回転中にする
    if (objDir != dir)
    {
        nowRotate = true;
    }
    rotRad += CalcRotDir(dir, velocity);

    //目標方向まで回転処理
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
    //回転方向を算出
    velocity = math::DegToRad(velocity);
    if (VCross(objDir, dir).y < 0)
    {
        return velocity *= -1;
    }
    return velocity;
}

