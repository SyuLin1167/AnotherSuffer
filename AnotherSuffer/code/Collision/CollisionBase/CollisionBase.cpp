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
    //処理なし
}

CollisionBase::~CollisionBase()
{
    //処理なし
}

void CollisionBase::Update(const VECTOR& pos)
{
    //処理なし
}
