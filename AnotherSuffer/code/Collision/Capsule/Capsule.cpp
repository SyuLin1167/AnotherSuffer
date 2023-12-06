#include<memory>

#include"../../Object/ObjBase/ObjBase.h"
#include"../Line/Line.h"
#include "Capsule.h"

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
    if (colInfo.HitNum == 0)
    {
        return false;
    }
    return true;
}

VECTOR Capsule::CalcPushBackFromMesh(MV1_COLL_RESULT_POLY_DIM& colInfo)
{
    //�����߂��ʏ�����
    VECTOR pushBack = worldCenter;

    // �Փ˃|���S�����������߂��ʂ��v�Z����
    for (int i = 0; i < colInfo.HitNum; ++i)
    {
        //�����߂���̍��W���܂��߂荞��ł����牟���߂��ʌv�Z
        if (HitCheck_Capsule_Triangle(
            VAdd(worldStart, VSub(pushBack, worldCenter)), VAdd(worldEnd, VSub(pushBack, worldCenter)),
            radius, colInfo.Dim[i].Position[0], colInfo.Dim[i].Position[1], colInfo.Dim[i].Position[2]))
        {
            //2�ӂ���@���x�N�g���Z�o
            VECTOR poligonVec1 = VSub(colInfo.Dim[i].Position[1], colInfo.Dim[i].Position[0]);
            VECTOR poligonVec2 = VSub(colInfo.Dim[i].Position[2], colInfo.Dim[i].Position[0]);
            VECTOR normalVec = VNorm(VCross(poligonVec1, poligonVec2));

            //�߂荞�ݗʎZ�o
            VECTOR distance = VSub(pushBack, colInfo.Dim[i].Position[0]);
            float dot = VDot(normalVec, distance);
            float cavedLen = radius - VSize(VScale(normalVec, dot));

            //�߂荞�񂾕������߂��ʂƂ��ĉ��Z
            pushBack = VAdd(pushBack, VScale(normalVec, cavedLen));
        }
    }

    // �����߂��ʂ�ԋp
    return VSub(pushBack, worldCenter);
}



VECTOR Capsule::CalcPushBackFromMesh(std::unordered_map<class ObjBase*, MV1_COLL_RESULT_POLY_DIM> adjoinObj)
{
    //�����߂��ʏ�����
    VECTOR pushBack = worldCenter;

    // �Փ˃|���S�����������߂��ʂ��v�Z����
    for (auto& colObj : adjoinObj)
    {
        for (int i = 0; i < colObj.second.HitNum; ++i)
        {
            //�����߂���̍��W���܂��߂荞��ł����牟���߂��ʌv�Z
            if (HitCheck_Capsule_Triangle(
                VAdd(worldStart, VSub(pushBack, worldCenter)), VAdd(worldEnd, VSub(pushBack, worldCenter)),
                radius, colObj.second.Dim[i].Position[0], colObj.second.Dim[i].Position[1], colObj.second.Dim[i].Position[2]))
            {
                //2�ӂ���@���x�N�g���Z�o
                VECTOR poligonVec1 = VSub(colObj.second.Dim[i].Position[1], colObj.second.Dim[i].Position[0]);
                VECTOR poligonVec2 = VSub(colObj.second.Dim[i].Position[2], colObj.second.Dim[i].Position[0]);
                VECTOR normalVec = VNorm(VCross(poligonVec1, poligonVec2));

                for (auto& adj : adjoinObj)
                {
                    for (int j = 0; j < adj.second.HitNum; j++)
                    {
                        if (VDot(adj.second.Dim[j].Normal, normalVec) == -1)
                        {
                            normalVec = VGet(0, 0, 0);
                            break;
                        }
                    }
                }

                //�߂荞�ݗʎZ�o
                VECTOR distance = VSub(pushBack, colObj.second.Dim[i].Position[0]);
                float dot = VDot(normalVec, distance);
                float cavedLen = radius - VSize(VScale(normalVec, dot));

                //�߂荞�񂾕������߂��ʂƂ��ĉ��Z
                pushBack = VAdd(pushBack, VScale(normalVec, cavedLen));
            }
        }
    }

    // �����߂��ʂ�ԋp
    return VSub(pushBack, worldCenter);
}

void Capsule::DrawCapsule()
{
    DrawCapsule3D(worldStart, worldEnd, radius, 8, GetColor(255, 255, 255), GetColor(255, 50, 255), false);
}