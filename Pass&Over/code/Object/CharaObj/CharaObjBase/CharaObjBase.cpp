#include "CharaObjBase.h"

using namespace math;

CharaObjBase::CharaObjBase(std::string tag)
    :ObjBase(tag)
    , moveSpeed(0.0f)
{


}

CharaObjBase::~CharaObjBase()
{
    //ˆ—‚È‚µ
}

void CharaObjBase::RotateYAxis(const VECTOR aimDir, float velocity)
{
    //Œ»•ûŒü‚ª–Ú•W•ûŒü‚Å‚È‚¯‚ê‚Î‰ñ“]’†‚É‚·‚é
    if (objDir != aimDir)
    {
        nowRotate = true;
    }

    //–Ú•W•ûŒü‚Ü‚Å‰ñ“]ˆ—
    CalcRotDir(aimDir, velocity);

    MATRIX rotYMat = MGetRotY(rotRad);
    objDir = VTransform(objDir, MInverse(rotYMat));
    if (VCross(objDir, aimDir).y < 0.0f)
    {
        objDir = VScale(aimDir, -1);
        nowRotate = false;
    }
    MV1SetRotationZYAxis(objHandle, objDir, VGet(0.0f, 1.0f, 0.0f), 0.0f);
}

float CharaObjBase::CalcRotDir(const VECTOR aimDir, float velocity)
{
    //Šp‘¬“x‚ğƒ‰ƒWƒAƒ“Šp‚É‚µ‚ÄA‰ñ“]•ûŒü‚ğZo
    rotRad = math::DegToRad(velocity);
    if (VCross(objDir, aimDir).y < 0)
    {
        rotRad = -rotRad;
    }
    return rotRad;
}

