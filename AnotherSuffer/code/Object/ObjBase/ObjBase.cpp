#include "ObjBase.h"

ObjBase::ObjBase(std::string tag)
    :objTag(tag)
    , isAlive(true)
    , isVisible(true)
    , objHandle(-1)
    , objScale(VGet(0.1f, 0.1f, 0.1f))
    , objPos()
    , objWorldPos()
    , objLocalPos()
    , objDir(VGet(1, 0, 0))
    , colInfo()
{
    //�����Ȃ�
}

ObjBase::~ObjBase()
{
    //�����Ȃ�
}

void ObjBase::CalcObjPos()
{
    objPos = VAdd(objWorldPos, objLocalPos);
}
