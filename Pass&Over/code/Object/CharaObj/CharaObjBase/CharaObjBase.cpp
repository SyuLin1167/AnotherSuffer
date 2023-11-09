#include "CharaObjBase.h"

CharaObjBase::CharaObjBase(std::string tag)
    :ObjBase(tag)
    , moveSpeed(0.0f)
{


}

CharaObjBase::~CharaObjBase()
{
    //�����Ȃ�
}

void CharaObjBase::RotatePitch(const VECTOR& aimDir, float velocity)
{
    //�p���x�����W�A���p�ɂ��āA��]�������Z�o
    rotRad = math::DegToRad(velocity);
    if (VCross(objDir, aimDir).y < 0)
    {
        rotRad *= -1;
    }

    //��]���ɂ���
    nowRotate = true;
    
    //��]����
    if (nowRotate)
    {
        // ���f���Ɍ����Ăق��������ɉ�].
        MATRIX rotYMat = MGetRotY(rotRad);
        MV1SetRotationMatrix(objHandle, rotYMat);
    }
}

float CharaObjBase::CaldRotDir()
{
    return 0.0f;
}

