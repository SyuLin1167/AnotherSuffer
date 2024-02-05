#include<DxLib.h>

#include "ColModel.h"

ColModel::ColModel(int& handle)
    :CollisionBase(ColTag.MODEL)
{
    colHandle = handle;
}

ColModel::~ColModel()
{
    //�����Ȃ�
}

bool ColModel::OnCollisionWithCapsule(const VECTOR startPos, const VECTOR endPos, const float radius)
{
    //�����蔻���񂩂画�茋�ʂ�Ԃ�
    colInfoDim = MV1CollCheck_Capsule(colHandle, -1, startPos, endPos, radius);
    if (colInfoDim.HitNum > 0)
    {
        return true;
    }
    return false;
}

