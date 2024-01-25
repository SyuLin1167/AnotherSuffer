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
    //ˆ—‚È‚µ
}

CollisionBase::~CollisionBase()
{
    //ˆ—‚È‚µ
}

void CollisionBase::Update(const VECTOR& pos)
{
    //ˆ—‚È‚µ
}
