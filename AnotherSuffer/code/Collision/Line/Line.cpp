#include "Line.h"

Line::Line(const VECTOR& startPos, const VECTOR& endPos)
    :localStartPos(startPos)
    , worldStartPos(startPos)
    , localEndPos(endPos)
    , worldEndPos(endPos)
{
}

Line::~Line()
{

}

void Line::Update(const VECTOR& pos)
{
    worldStartPos = VAdd(localStartPos, pos);
    worldEndPos = VAdd(localEndPos, pos);
}

bool Line::OnCollisionWithMesh(const int modelHandle, MV1_COLL_RESULT_POLY_DIM& colInfo)
{
    //�����蔻���񂩂画�茋�ʂ�Ԃ�
    colInfo = MV1CollCheck_LineDim(modelHandle, -1, worldStartPos, worldEndPos);
    return colInfo.Dim->HitFlag;
}