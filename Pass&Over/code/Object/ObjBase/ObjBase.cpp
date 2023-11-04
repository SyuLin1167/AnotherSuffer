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
    , objDir(VGet(1, 0, 0))
{
    //ˆ—‚È‚µ
}

ObjBase::~ObjBase()
{
    //ˆ—‚È‚µ
}