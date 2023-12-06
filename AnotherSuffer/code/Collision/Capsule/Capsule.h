#pragma once
#include<DxLib.h>
#include<unordered_map>

/// <summary>
/// �J�v�Z���^�����蔻��
/// </summary>
class Capsule final
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
    /// �X�V����
    /// </summary>
    /// <param name="pos">:�ړ����W</param>
    void Update(const VECTOR& pos);

    /// <summary>
    /// ���b�V���Ƃ̏Փ˔��菈��
    /// </summary>
    /// <param name="modelHandle">:���f���n���h��</param>
    /// <param name="colInfo">:�����蔻����</param>
    /// <returns>�Ԃ�����:true|�Ԃ����Ă��Ȃ�:false</returns>
    bool OnCollisionWithMesh(const int modelHandle, MV1_COLL_RESULT_POLY_DIM& colInfo);

    /// <summary>
    /// ���b�V���Ƃ̏Փˎ������߂��ʎZ�o
    /// </summary>
    /// <param name="colInfo">:�����蔻����</param>
    /// <returns>�����߂���</returns>
    VECTOR CalcPushBackFromMesh(MV1_COLL_RESULT_POLY_DIM& colInfo);

    /// <summary>
    /// ���b�V���Ƃ̏Փˎ������߂��ʎZ�o(�אڔ���)
    /// </summary>
    /// <param name="adjoinObj">:�אڃI�u�W�F�N�g</param>
    /// <returns>�����߂���</returns>
    VECTOR CalcPushBackFromMesh(std::unordered_map<class ObjBase*, MV1_COLL_RESULT_POLY_DIM> adjoinObj);

    /// <summary>
    /// �J�v�Z���`��
    /// </summary>
    void DrawCapsule();

private:
    VECTOR localStart;                  //�J�v�Z���̃��[�J�����W�n�_
    VECTOR localEnd;                    //�J�v�Z���̃��[�J�����W�I�_
    VECTOR worldStart;                  //�J�v�Z���̃��[���h���W�n�_
    VECTOR worldEnd;                    //�J�v�Z���̃��[���h���W�I�_
    VECTOR worldCenter;                 //�J�v�Z���̃��[���h���S���W
    float radius;                       //�J�v�Z���̔��a
};