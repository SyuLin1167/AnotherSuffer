#include<DxLib.h>
#include<iostream>

#include "Sphere.h"

Capsule::Capsule(const VECTOR& startPos, const VECTOR& endPos, float rad)
    :localStart(startPos)
    , localEnd(endPos)
    , worldStart(startPos)
    , worldEnd(endPos)
    , worldCenter(VGet(0, 0, 0))
    , radius(rad)
{
    //ˆ—‚È‚µ
}

Capsule::~Capsule()
{
    //ˆ—‚È‚µ
}

void Capsule::Update(const VECTOR& pos)
{
    //À•WˆÚ“®
    worldStart = VAdd(localStart, pos);
    worldEnd = VAdd(localEnd, pos);
    worldCenter = VAdd(worldStart, VScale(VSub(worldEnd, worldStart), 0.5f));
}

bool Capsule::OnCollisionWithMesh(const int modelHandle, MV1_COLL_RESULT_POLY_DIM& colInfo)
{
    //“–‚½‚è”»’èî•ñ‚©‚ç”»’èŒ‹‰Ê‚ğ•Ô‚·
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

    VECTOR pushBack = VGet(0, 0, 0);

    // Õ“Ëƒ|ƒŠƒSƒ“”•ª‰Ÿ‚µ–ß‚µ—Ê‚ğŒvZ‚·‚é
    for (int i = 0; i < colInfo.HitNum; ++i)
    {
        if (HitCheck_Capsule_Triangle(worldStart, worldEnd,
            radius, colInfo.Dim[i].Position[0], colInfo.Dim[i].Position[1], colInfo.Dim[i].Position[2]))
        {
            VECTOR normalVec = VNorm(colInfo.Dim[i].Normal);
            VECTOR distance = VSub(worldCenter, colInfo.Dim[i].HitPosition);

            float dot = VDot(normalVec, distance);
            float len = radius - VSize(VScale(normalVec, dot));
            if (len > 0)
            {
                len * 0.01f;
            }
            pushBack = VAdd(pushBack, VScale(normalVec, len/2));
        }
    }


    return pushBack;                                      // ‰Ÿ‚µ–ß‚µ—Ê‚ğ•Ô‹p
}

void Capsule::DrawDebug()
{
    DrawCapsule3D(worldStart, worldEnd, radius, 8, GetColor(255, 255, 255), GetColor(255, 50, 255), false);
}




