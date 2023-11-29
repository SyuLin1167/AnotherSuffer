#include<DxLib.h>
#include "Capsule.h"

Capsule::Capsule(const VECTOR& startPos, const VECTOR& endPos, float rad)
    :localStart(startPos)
    , localEnd(endPos)
    , worldStart(startPos)
    , worldEnd(endPos)
    , radius(rad)
{
    //処理なし
}

Capsule::~Capsule()
{
    //処理なし
}

void Capsule::Update(const VECTOR& pos)
{
    //座標移動
    worldStart = VAdd(localStart, pos);
    worldEnd = VAdd(localEnd, pos);
}

bool Capsule::OnCollisionWithMesh(const int modelHandle, MV1_COLL_RESULT_POLY_DIM& colInfo)
{
    //当たり判定情報から判定結果を返す
    colInfo = MV1CollCheck_Capsule(modelHandle, -1, worldStart, worldEnd, radius);
    if (colInfo.HitNum == 0)
    {
        return false;
    }
    return true;
}

VECTOR Capsule::CalcPushBackFromMesh(const MV1_COLL_RESULT_POLY_DIM& colInfo)
{
    VECTOR nomalVec;

    for (int i = 0; i < colInfo.HitNum; i++)
    {
        nomalVec = colInfo.Dim->Normal;

        if (HitCheck_Capsule_Triangle(worldStart, worldEnd,
            radius, colInfo.Dim[i].Position[0],colInfo.Dim[i].Position[1],colInfo.Dim[i].Position[2]))
        {

        }
    }
    return VECTOR(0,0,0);
}

void Capsule::DrawDebug()
{
    DrawCapsule3D(worldStart, worldEnd, radius, 8, GetColor(255, 255, 255), GetColor(255, 50, 255), false);
}




