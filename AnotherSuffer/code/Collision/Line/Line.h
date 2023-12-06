#pragma once
#include<DxLib.h>

/// <summary>
/// ���������蔻��
/// </summary>
class Line final
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="startPos">:�n�_</param>
    /// <param name="endPos">:�I�_</param>
    Line(const VECTOR& startPos, const VECTOR& endPos);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Line();

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

private:
    VECTOR localStartPos;
    VECTOR worldStartPos;
    VECTOR localEndPos;
    VECTOR worldEndPos;
};

