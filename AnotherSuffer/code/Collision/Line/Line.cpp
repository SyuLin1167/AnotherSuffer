#include<DxLib.h>

#include "Line.h"

Line::Line(const VECTOR& startPos, const VECTOR& endPos)
    :CollisionBase(ColTag.LINE)
    , localStartPos(startPos)
    , worldStartPos(startPos)
    , localEndPos(endPos)
    , worldEndPos(endPos)
{
    //ˆ—‚È‚µ
}

Line::~Line()
{
    //ˆ—‚È‚µ
}

void Line::Update(const VECTOR& pos)
{
    worldStartPos = VAdd(localStartPos, pos);
    worldEndPos = VAdd(localEndPos, pos);
}

bool Line::OnCollisionWithMesh(const int modelHandle)
{
    //“–‚½‚è”»’èî•ñ‚©‚ç”»’èŒ‹‰Ê‚ğ•Ô‚·
    colInfo = MV1CollCheck_Line(modelHandle, -1, worldStartPos, worldEndPos);
    if (colInfo.HitNum > 0)
    {
        return true;
    }
    return false;
}