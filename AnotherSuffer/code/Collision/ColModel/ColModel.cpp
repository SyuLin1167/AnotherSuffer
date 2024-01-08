#include<DxLib.h>

#include "ColModel.h"

ColModel::ColModel(int handle)
    :colHandle(handle)
    ,colInfo()
{
    //�����Ȃ�
}

ColModel::~ColModel()
{
    //�����Ȃ�
}

bool ColModel::OnCollisionWithCapsule(const VECTOR startPos, const VECTOR endPos, const float radius)
{
    //�����蔻���񂩂画�茋�ʂ�Ԃ�
    colInfo = MV1CollCheck_Capsule(colHandle, -1, startPos, endPos, radius);
    if (colInfo.HitNum > 0)
    {
        return true;
    }
    return false;
}

