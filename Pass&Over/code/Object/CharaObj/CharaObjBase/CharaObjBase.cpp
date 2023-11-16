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
    //ˆ—‚È‚µ
}

void CharaObjBase::RotateYAxis(const VECTOR dir, float velocity)
{
    //Œ»•ûŒü‚ª–Ú•W•ûŒü‚Å‚È‚¯‚ê‚Î‰ñ“]’†‚É‚·‚é
    if (objDir != dir)
    {
        aimDir = dir;
        nowRotate = true;
        CalcRotDir(dir, velocity);
    }

    //–Ú•W•ûŒü‚Ü‚Å‰ñ“]ˆ—
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
    //ƒ‰ƒWƒAƒ“Šp‚É•ÏŠ·
    rotRad = math::DegToRad(velocity);
    rotYMat = MGetRotY(rotRad);

    //‰ñ“]•ûŒü‚ğZo
    if (VCross(objDir, aimDir).y < 0)
    {
        rotYMat = MTranspose(rotYMat);
    }
    return velocity;
}

