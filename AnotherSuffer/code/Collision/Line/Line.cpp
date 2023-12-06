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

bool Line::OnCollisionWithMesh(const int modelHandle, MV1_COLL_RESULT_POLY& colInfo)
{
    //“–‚½‚è”»’èî•ñ‚©‚ç”»’èŒ‹‰Ê‚ğ•Ô‚·
    colInfo = MV1CollCheck_Line(modelHandle, -1, worldStartPos, worldEndPos);
    return colInfo.HitFlag;
}