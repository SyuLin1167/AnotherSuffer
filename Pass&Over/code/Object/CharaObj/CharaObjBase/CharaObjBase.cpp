#include "CharaObjBase.h"

CharaObjBase::CharaObjBase(std::string tag)
    :ObjBase(tag)
    , moveSpeed(0.0f)
{


}

CharaObjBase::~CharaObjBase()
{
    //ˆ—‚È‚µ
}

void CharaObjBase::RotatePitch(const VECTOR& aimDir, float velocity)
{
    //Šp‘¬“x‚ğƒ‰ƒWƒAƒ“Šp‚É‚µ‚ÄA‰ñ“]•ûŒü‚ğZo
    rotRad = math::DegToRad(velocity);
    if (VCross(objDir, aimDir).y < 0)
    {
        rotRad *= -1;
    }

    //‰ñ“]’†‚É‚·‚é
    nowRotate = true;
    
    //‰ñ“]ˆ—
    if (nowRotate)
    {
        // ƒ‚ƒfƒ‹‚ÉŒü‚¢‚Ä‚Ù‚µ‚¢•ûŒü‚É‰ñ“].
        MATRIX rotYMat = MGetRotY(rotRad);
        MV1SetRotationMatrix(objHandle, rotYMat);
    }
}

float CharaObjBase::CaldRotDir()
{
    return 0.0f;
}

