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
    //�����Ȃ�
}

Capsule::~Capsule()
{
    //�����Ȃ�
}

void Capsule::Update(const VECTOR& pos)
{
    //���W�ړ�
    worldStart = VAdd(localStart, pos);
    worldEnd = VAdd(localEnd, pos);
    worldCenter = VAdd(worldStart, VScale(VSub(worldEnd, worldStart), 0.5f));
}

bool Capsule::OnCollisionWithMesh(const int modelHandle, MV1_COLL_RESULT_POLY_DIM& colInfo)
{
    //�����蔻���񂩂画�茋�ʂ�Ԃ�
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
    VECTOR distance = VGet(0, 0, 0);

    // �Փ˃|���S�����������߂��ʂ��v�Z����
    for (int i = 0; i < colInfo.HitNum; ++i)
    {
        if (HitCheck_Capsule_Triangle(worldStart, worldEnd,
            radius, colInfo.Dim[i].Position[0], colInfo.Dim[i].Position[1], colInfo.Dim[i].Position[2]))
        {
            VECTOR normalVec = VNorm(colInfo.Dim[i].Normal);
            distance = VSub(worldCenter, colInfo.Dim[i].Position[0]);

            float dot = VDot(normalVec, distance);
            float len = radius - VSize(VScale(normalVec, dot));

            pushBack = VAdd(pushBack, VScale(normalVec, len));
        }
    }


    return VScale(VSub(pushBack, worldCenter), 0.005f);                                      // �����߂��ʂ�ԋp
}

void Capsule::DrawDebug()
{
    DrawCapsule3D(worldStart, worldEnd, radius, 8, GetColor(255, 255, 255), GetColor(255, 50, 255), false);
}




