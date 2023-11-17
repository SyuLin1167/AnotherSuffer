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
    aimDir = dir;
    if (objDir != aimDir)
    {
        nowRotate = true;
    }

    //–Ú•W•ûŒü‚Ü‚Å‰ñ“]ˆ—
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
    //ƒ‰ƒWƒAƒ“Šp‚É‚µ‚Ä‰ñ“]s—ñ‚Ö•ÏŠ·
    rotRad = math::DegToRad(velocity);
    rotYMat = MGetRotY(rotRad);

    //‰ñ“]•ûŒü‚ğZo
    if (VCross(objDir, aimDir).y < 0)
    {
        rotYMat = MTranspose(rotYMat);
        return -rotRad;
    }
    return rotRad;
}

