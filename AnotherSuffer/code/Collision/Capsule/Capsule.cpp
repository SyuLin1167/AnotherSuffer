#include<DxLib.h>
#include<iostream>

#include "Capsule.h"

Capsule::Capsule(const VECTOR& startPos, const VECTOR& endPos, float rad)
    :localStart(startPos)
    , localEnd(endPos)
    , worldStart(startPos)
    , worldEnd(endPos)
    , worldCenter(VGet(0, 0, 0))
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
    worldCenter = VAdd(worldStart, VScale(VSub(worldEnd, worldStart), 0.5f));
}

bool Capsule::OnCollisionWithMesh(const int modelHandle, MV1_COLL_RESULT_POLY_DIM& colInfo)
{
    //当たり判定情報から判定結果を返す
    colInfo = MV1CollCheck_Capsule(modelHandle, -1, worldStart, worldEnd, radius);
    MV1SetupCollInfo(modelHandle);
    if (colInfo.HitNum == 0)
    {
        return false;
    }
    return true;
}

VECTOR Capsule::CalcPushBackFromMesh(const MV1_COLL_RESULT_POLY_DIM& colInfo, bool shouldVecY)
{
    //押し戻し量初期化
    VECTOR pushBack = worldCenter;

    // 衝突ポリゴン数分押し戻し量を計算する
    for (int i = 0; i < colInfo.HitNum; ++i)
    {
        //押し戻し後の座標がまだめり込んでいたら押し戻し量計算
        if (HitCheck_Capsule_Triangle(
            VAdd(worldStart, VSub(pushBack, worldCenter)), VAdd(worldEnd, VSub(pushBack, worldCenter)),
            radius, colInfo.Dim[i].Position[0], colInfo.Dim[i].Position[1], colInfo.Dim[i].Position[2]))
        {
            //2辺から法線ベクトル算出
            VECTOR poligonVec1 = VSub(colInfo.Dim[i].Position[1], colInfo.Dim[i].Position[0]);
            VECTOR poligonVec2 = VSub(colInfo.Dim[i].Position[2], colInfo.Dim[i].Position[0]);
            VECTOR normalVec = VNorm(VCross(poligonVec1, poligonVec2));

            //めり込み量算出
            VECTOR distance = VSub(pushBack, colInfo.Dim[i].Position[0]);
            float dot = VDot(normalVec, distance);
            float cavedLen = radius - VSize(VScale(normalVec, dot));

            //めり込んだ分押し戻し量として加算
            pushBack = VAdd(pushBack, VScale(normalVec, cavedLen));
        }
    }

    // 押し戻し量を返却
    return VSub(pushBack, worldCenter);
}

void Capsule::DrawCapsule()
{
    DrawCapsule3D(worldStart, worldEnd, radius, 8, GetColor(255, 255, 255), GetColor(255, 50, 255), false);
}




