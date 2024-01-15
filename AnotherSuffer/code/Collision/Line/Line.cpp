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

bool Line::OnCollisionWithMesh(const int modelHandle)
{
    //�����蔻���񂩂画�茋�ʂ�Ԃ�
    colInfo = MV1CollCheck_Line(modelHandle, -1, worldStartPos, worldEndPos);
    if (colInfo.HitNum > 0)
    {
        return true;
    }
    return false;
}