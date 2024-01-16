#include<DxLib.h>

#include "Line.h"

Line::Line(const VECTOR& startPos, const VECTOR& endPos)
    :CollisionBase(ColTag.LINE)
    , localStartPos(startPos)
    , worldStartPos(startPos)
    , localEndPos(endPos)
    , worldEndPos(endPos)
{
    //�����Ȃ�
}

Line::~Line()
{
    //�����Ȃ�
}

void Line::Update(const VECTOR& pos)
{
    worldStartPos = VAdd(localStartPos, pos);
    worldEndPos = VAdd(localEndPos, pos);
}

void Line::Update(const VECTOR& pos1, const VECTOR& pos2)
{
    worldStartPos = localStartPos = pos1;
    worldEndPos = localEndPos = pos2;
}

bool Line::OnCollisionWithMesh(const int modelHandle)
{
    //�����蔻���񂩂画�茋�ʂ�Ԃ�
    colInfo = MV1CollCheck_Line(modelHandle, -1, worldStartPos, worldEndPos);
    return colInfo.HitFlag;
}