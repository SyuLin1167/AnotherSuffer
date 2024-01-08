#pragma once

/// <summary>
/// �����蔻��̊��N���X
/// </summary>
class CollisionBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    CollisionBase();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~CollisionBase();

    /// <summary>
    /// ���[���h�n�_���W�擾
    /// </summary>
    /// <returns>���[���h�n�_���W</returns>
    VECTOR GetWorldStartPos() const { worldStart; }

    /// <summary>
    /// ���[���h�I�_���W�擾
    /// </summary>
    /// <returns>���[���h�I�_���W</returns>
    VECTOR GetWorldEndPos() const { worldEnd; }

    /// <summary>
    /// ���a�擾
    /// </summary>
    /// <returns>���a</returns>
    float GetRadius() const { radius; }

protected:
    /// <summary>
    /// ���W�X�V
    /// </summary>
    /// <param name="pos"></param>
    virtual void Update(const VECTOR& pos);

    VECTOR localStart;       //���[�J���n�_���W
    VECTOR localEnd;         //���[�J���I�_���W
    VECTOR worldStart;       //���[���h�n�_���W
    VECTOR worldEnd;         //���[���h�I�_���W
    VECTOR worldCenter;      //���[���h���S���W
    float radius;            //���a
};

