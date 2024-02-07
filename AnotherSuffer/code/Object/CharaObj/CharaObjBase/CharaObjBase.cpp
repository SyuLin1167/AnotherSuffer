#include<DxLib.h>

#include"../../ObjBase/ObjBase.h"
#include"../../../Asset/AssetManager/AssetManager.h"
#include"../../Math/Math.h"
#include "CharaObjBase.h"

static constexpr float SIMILAR_ANGLE = 0.999f;     //‘ŠŽ—Šp
const float CharaObjBase::ROTATE_SPEED = 3.0f;     //‰ñ“]‘¬“x

using namespace math;

CharaObjBase::CharaObjBase(std::string tag)
    :ObjBase(tag)
    , isMove(false)
    , moveSpeed()
    , nowRotate(false)
    , modelData(GetAssetPathData(AssetManager::ModelInstance()))
    , soundData(GetAssetPathData(AssetManager::SoundInstance()))
    , motionData(GetAssetPathData(AssetManager::MotionInstance()))
{
    XAxisData.reset(new AxisData(xAxis, this));
    YAxisData.reset(new AxisData(yAxis, this, DX_PI_F / 2.0f));
    ZAxisData.reset(new AxisData(zAxis, this));
}

CharaObjBase::~CharaObjBase()
{
    //ˆ—‚È‚µ
}

rapidjson::Value& CharaObjBase::GetAssetPathData(AssetBase* asset)
{
    //”CˆÓ‚ÌƒAƒZƒbƒgƒf[ƒ^‚ÉƒIƒuƒWƒFƒNƒg‚ª‚¢‚½‚çƒpƒXƒf[ƒ^‰Šú‰»
    auto& jsonData = asset->GetJsonData();
    if (jsonData.HasMember(objTag.c_str()))
    {
        return jsonData[objTag.c_str()];
    }

    //‚È‚©‚Á‚½‚ç‹ó‚Ì’l‚ð•Ô‚·
    rapidjson::Value null;
    null.SetObject();
    return null;
}

CharaObjBase::AxisData::AxisData(const std::string& axis, CharaObjBase* obj, const float rad)
    :object(obj)
    , axisType(axis)
    , aimDir(VGet(0, 0, -1))
    , rotRad(rad)
    , rotVel()
    , rotMat(MGetIdent())
{
    if (axisType == obj->xAxis)
    {
        rotMat = MGetRotX(rotVel);
    }
    else if (axisType == obj->yAxis)
    {
        rotMat = MGetRotY(rotVel);
    }
    else if (axisType == obj->zAxis)
    {
        rotMat = MGetRotZ(rotVel);
    }
}

void CharaObjBase::AxisData::Rotate(const VECTOR& dir, const float& velocity)
{
    if (VSize(dir) > 0)
    {
        aimDir = dir;
        //‰ñ“]•ûŒüŽZo‚µ‚Ä‰ñ“]—Ê•ª‰ñ“]
        rotVel += CalcRotDir(velocity);
        if (rotVel > DX_PI_F * 2.0f)
        {
            rotVel = 0;
        }

        object->objDir = VTransform(object->objDir, rotMat);
        if (axisType == object->xAxis)
        {
            rotMat = MGetRotX(rotVel);
        }
        else if (axisType == object->yAxis)
        {
            rotMat = MGetRotY(rotVel);
        }
        else if (axisType == object->zAxis)
        {
            rotMat = MGetRotZ(rotVel);
        }
    }
}

void CharaObjBase::AxisData::RotateToAim(const VECTOR& dir,const float& velocity)
{
    if (VSize(dir) > 0)
    {
        //Œ»•ûŒü‚ª–Ú•W•ûŒü‚Å‚È‚¯‚ê‚Î‰ñ“]’†‚É‚·‚é
        aimDir = dir;
        if (VDot(object->objDir, aimDir) < SIMILAR_ANGLE)
        {
            object->nowRotate = true;
        }

        //‰ñ“]’†‚È‚ç
        if (object->nowRotate)
        {
            //–Ú•W•ûŒü•t‹ß‚Ü‚Å‰ñ“]
            if (VDot(object->objDir, aimDir) < SIMILAR_ANGLE)
            {
                //‰ñ“]•ûŒüŽZo‚µ‚Ä‰ñ“]—Ê•ª‰ñ“]
                rotVel += CalcRotDir(velocity);

                object->objDir = VTransform(object->objDir, rotMat);
                if (axisType == object->xAxis)
                {
                    rotMat = MGetRotX(rotVel);
                }
                else if (axisType == object->yAxis)
                {
                    rotMat = MGetRotY(rotVel);
                }
                else if (axisType == object->zAxis)
                {
                    rotMat = MGetRotZ(rotVel);
                }
            }
            else
            {
                //–Ú•W•ûŒü‚É‚µ‚Ä‰ñ“]’âŽ~
                rotMat = MGetRotVec2(object->objDir, aimDir);
                object->objDir = aimDir;
                object->nowRotate = false;
            }
        }
    }
}

void CharaObjBase::AxisData::RotateToAim(const VECTOR& dir)
{
    //–Ú•W•ûŒü‚É‰ñ“]
    rotMat = MMult(MGetIdent(), MGetRotVec2(aimDir, dir));
    object->objDir = dir;
}

float CharaObjBase::AxisData::CalcRotDir(const float& velocity)
{
    //ƒ‰ƒWƒAƒ“Šp‚É‚µ‚Ä‰ñ“]s—ñ‚Ö•ÏŠ·
    rotRad = math::DegToRad(velocity);
    if (axisType == object->xAxis)
    {
        rotMat = MGetRotX(rotRad);
    }
    else if (axisType == object->yAxis)
    {
        rotMat = MGetRotY(rotRad);
    }
    else if(axisType== object->zAxis)
    {
        rotMat = MGetRotZ(rotRad);
    }

    //‰ñ“]•ûŒü‚ðŽZo
    if (VCross(object->objDir, aimDir).y < 0)
    {
        rotMat = MTranspose(rotMat);
        return -rotRad;
    }
    return rotRad;
}
