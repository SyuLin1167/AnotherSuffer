#include<DxLib.h>

#include "CollisionBase.h"

CollisionBase::CollisionBase(std::string tag)
    :colTag(tag)
    , colHandle(-1)
    , colInfoDim()
    , colInfo()
    , localStart()
    , localEnd()
    , worldStart()
    , worldEnd()
    , worldCenter()
    , radius()
{
    //�����Ȃ�
}

CollisionBase::~CollisionBase()
{
    //�����Ȃ�
}

void CollisionBase::Update(const VECTOR& pos)
{
    //�����Ȃ�
}
