#include<DxLib.h>

#include "CollisionBase.h"

CollisionBase::CollisionBase()
    :localStart()
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

}

void CollisionBase::Update(const VECTOR& pos)
{
    //処理なし
}
