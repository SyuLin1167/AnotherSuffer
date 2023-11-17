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
    aimDir = dir;
    if (objDir != aimDir)
    {
        nowRotate = true;
    }

    //目標方向まで回転処理
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
    //ラジアン角にして回転行列へ変換
    rotRad = math::DegToRad(velocity);
    rotYMat = MGetRotY(rotRad);

    //回転方向を算出
    if (VCross(objDir, aimDir).y < 0)
    {
        rotYMat = MTranspose(rotYMat);
        return -rotRad;
    }
    return rotRad;
}

