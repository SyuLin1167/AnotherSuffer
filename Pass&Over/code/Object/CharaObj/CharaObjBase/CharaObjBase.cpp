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
    if (objDir != aimDir)
    {
        //Šp‘¬“x‚ğƒ‰ƒWƒAƒ“Šp‚É‚µ‚ÄA‰ñ“]•ûŒü‚ğZo
        rotRad = DX_PI_F * velocity / PI_RAD;
        if (VCross(objDir, aimDir).y < 0)
        {
            rotRad *= -1;
        }

        //‰ñ“]’†‚É‚·‚é
        nowRotate = true;
    }

    //‰ñ“]ˆ—
    if (nowRotate)
    {
        MATRIX objMat = MV1GetMatrix(objHandle);
        MATRIX rotMat = MGetRotY(rotRad);
        objMat = MMult(objMat, rotMat);
        MV1SetRotationMatrix(objHandle, objMat);
    }
}

float CharaObjBase::CaldRotDir()
{
    return 0.0f;
}

