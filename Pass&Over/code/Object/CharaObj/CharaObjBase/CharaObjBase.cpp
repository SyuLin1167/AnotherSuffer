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
        nowRotate = true;
    }
    rotRad += CalcRotDir(dir, velocity);

    //–Ú•W•ûŒü‚Ü‚Å‰ñ“]ˆ—
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
    //‰ñ“]•ûŒü‚ğZo
    velocity = math::DegToRad(velocity);
    if (VCross(objDir, dir).y < 0)
    {
        return velocity *= -1;
    }
    return velocity;
}

