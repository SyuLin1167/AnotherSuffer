#include "ObjBase.h"

ObjBase::ObjBase(std::string tag)
    :objTag(tag)
    , model(AssetManager::ModelInstance())
    , motion(AssetManager::MotionInstance())
    , sound(AssetManager::SoundInstance())
    , isAlive(true)
    , isVisible(true)
    , objHandle(-1)
    , objScale(VGet(0.1f, 0.1f, 0.1f))
    , objPos(VGet(0, 0, 0))
    , objWorldPos(VGet(0, 0, 0))
    , objLocalPos(VGet(0, 0, 0))
    , objDir(VGet(1, 0, 0))
{
    //èàóùÇ»Çµ
}

ObjBase::~ObjBase()
{
    //èàóùÇ»Çµ
}

void ObjBase::CalcObjPos()
{
    objPos = VAdd(objWorldPos, objLocalPos);
}
