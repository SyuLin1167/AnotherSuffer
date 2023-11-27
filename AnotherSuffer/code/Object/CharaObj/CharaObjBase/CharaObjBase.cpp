#include "CharaObjBase.h"

using namespace math;

CharaObjBase::CharaObjBase(std::string tag)
    :ObjBase(tag)
    , isMove(false)
    , moveSpeed(0.0f)
    , nowRotate(false)
    , aimDir(VGet(0, 0, 0))
    , rotRad(0.0f)
    , rotYRad(-DX_PI_F / 2)
{
    rotYMat = MGetRotY(rotYRad);
    rotateMat = MMult(MGetScale(objScale), rotYMat);
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

    //‰ñ“]’†‚È‚ç
    if (nowRotate)
    {
        //–Ú•W•ûŒü•t‹ß‚Ü‚Å‰ñ“]
        if (VDot(objDir, aimDir) < SIMILAR_ANGLE )
        {
            //‰ñ“]•ûŒüZo‚µ‚ÄƒxƒNƒgƒ‹‚Æs—ñ‚Ì—¼•û‚ğ‰ñ“]‚³‚¹‚é
            rotYRad += CalcRotDir(velocity);
            objDir = VTransform(objDir, rotYMat);
            rotateMat = MMult(MGetScale(objScale), MGetRotY(rotYRad));
        }
        else
        {
            //–Ú•W•ûŒü‚É‚µ‚Ä‰ñ“]’â~
            rotateMat = MMult(MGetScale(objScale), MGetRotVec2(objDir, aimDir));
            objDir = aimDir;
            nowRotate = false;
        }
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

