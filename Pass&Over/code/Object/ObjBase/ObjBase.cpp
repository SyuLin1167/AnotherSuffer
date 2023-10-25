#include "ObjBase.h"

ObjBase::ObjBase(std::string tag)
    :objTag(tag)
    , isAlive(true)
    , isVisible(true)
    , objHandle(-1)
    , objScale(VGet(0.1f, 0.1f, 0.1f))
    , objPos(VGet(0, 0, 0))
    , objDir(VGet(1, 0, 0))
{
    //�����Ȃ�
}

ObjBase::~ObjBase()
{
    //�����Ȃ�
}