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
    Capsule(const VECTOR& startPos, const VECTOR& endPos,const float& rad);

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
    /// <returns>�Փ�:true|���Փ�:false</returns>
    bool OnCollisionWithMesh(const int& modelHandle);

    bool OnCollisionWithCapsule(const VECTOR& pos, const VECTOR& pos2, const float& rad);

    /// <summary>
    /// ���b�V���Ƃ̏Փˎ������߂��ʎZ�o
    /// </summary>
    /// <returns>�����߂���</returns>
    VECTOR CalcPushBackFromMesh();

    /// <summary>
    /// �J�v�Z���`��
    /// </summary>
    void DrawCapsule();
};