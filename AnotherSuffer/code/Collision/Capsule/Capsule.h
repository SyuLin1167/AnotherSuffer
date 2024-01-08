#pragma once
#include<unordered_map>
#include"../CollisionBase/CollisionBase.h"

/// <summary>
/// �J�v�Z���^�����蔻��
/// </summary>
class Capsule final:public CollisionBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="startPos">:�n�_</param>
    /// <param name="endPos">:�I�_</param>
    /// <param name="rad">:���a</param>
    Capsule(const VECTOR& startPos, const VECTOR& endPos, float rad);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Capsule();

    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name="pos">:�ړ����W</param>
    void Update(const VECTOR& pos)override;

    /// <summary>
    /// ���b�V���Ƃ̏Փ˔���
    /// </summary>
    /// <param name="modelHandle">:���f���n���h��</param>
    /// <param name="colInfo">:�����蔻����</param>
    /// <returns>�Փ�:true|���Փ�:false</returns>
    bool OnCollisionWithMesh(const int modelHandle, MV1_COLL_RESULT_POLY_DIM& colInfo);

    /// <summary>
    /// ���b�V���Ƃ̏Փˎ������߂��ʎZ�o
    /// </summary>
    /// <param name="colInfo">:�����蔻����</param>
    /// <returns>�����߂���</returns>
    VECTOR CalcPushBackFromMesh(MV1_COLL_RESULT_POLY_DIM& colInfo);

    /// <summary>
    /// �J�v�Z���`��
    /// </summary>
    void DrawCapsule();
};