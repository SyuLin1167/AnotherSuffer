#pragma once
#include"../CollisionBase/CollisionBase.h"

class ColModel final:public CollisionBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="handle">:�n���h��</param>
    ColModel(int handle);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~ColModel();

    /// <summary>
    /// �J�v�Z���Ƃ̏Փ˔���
    /// </summary>
    /// <param name="startPos">:�n�_</param>
    /// <param name="coendPos">:�I�_</param>
    /// <param name="radius">:���a</param>
    /// <returns>�Փ�:true|���Փ�:false</returns>
    bool OnCollisionWithCapsule(const VECTOR startPos, const VECTOR endPos,const float radius);

    /// <summary>
    /// �Փ˔�����擾
    /// </summary>
    /// <returns>�Փ˔�����</returns>
    MV1_COLL_RESULT_POLY_DIM GetColInfo() const { return colInfo; }

private:
    int colHandle;                          //�n���h��
    MV1_COLL_RESULT_POLY_DIM colInfo;       //�����蔻����
};

