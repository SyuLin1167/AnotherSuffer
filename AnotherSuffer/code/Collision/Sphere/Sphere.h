#pragma once

/// <summary>
/// ���̌^�����蔻��
/// </summary>
class Sphere final
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="centerPos">:���S�_</param>
    /// <param name="rad">:���a</param>
    Sphere(const VECTOR& centerPos, float rad);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Sphere();

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
    VECTOR CalcPushBackFromMesh(const MV1_COLL_RESULT_POLY_DIM& colInfo);

    /// <summary>
    /// �f�o�b�O�p�`��
    /// </summary>
    void DrawDebug();
private:
    VECTOR localPos;                  //�J�v�Z���̃��[�J�����S���W
    VECTOR worldPos;                  //�J�v�Z���̃��[���h���S���W
    float radius;                     //�J�v�Z���̔��a
};

