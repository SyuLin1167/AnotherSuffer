#pragma once
#include"CollisionTag.h"

/// <summary>
/// �����蔻��̊��N���X
/// </summary>
class CollisionBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="tag">:�^�O</param>
    CollisionBase(std::string tag);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~CollisionBase();

    /// <summary>
    /// �����蔻��^�O�擾
    /// </summary>
    /// <returns></returns>
    std::string GetColTag() const { return colTag; }

    /// <summary>
    /// ���f���擾
    /// </summary>
    /// <returns></returns>
    int GetColModel() const { return colHandle; }

    /// <summary>
    /// �z��^�Փ˔�����擾
    /// </summary>
    /// <returns>�z��^�Փ˔�����</returns>
    MV1_COLL_RESULT_POLY_DIM GetColInfoDim() const { return colInfoDim; }

    /// <summary>
    /// �Փ˔�����擾
    /// </summary>
    /// <returns>�Փ˔�����</returns>
    MV1_COLL_RESULT_POLY GetColInfo() const { return colInfo; }

    /// <summary>
    /// ���[���h�n�_���W�擾
    /// </summary>
    /// <returns>���[���h�n�_���W</returns>
    VECTOR GetWorldStartPos() const {return worldStart; }

    /// <summary>
    /// ���[���h�I�_���W�擾
    /// </summary>
    /// <returns>���[���h�I�_���W</returns>
    VECTOR GetWorldEndPos() const {return worldEnd; }

    /// <summary>
    /// ���a�擾
    /// </summary>
    /// <returns>���a</returns>
    float GetRadius() const {return radius; }

protected:
    /// <summary>
    /// ���W�X�V
    /// </summary>
    /// <param name="pos"></param>
    virtual void Update(const VECTOR& pos);

    std::string colTag;                     //�����蔻��^�O

    int colHandle;                          //�n���h��
    MV1_COLL_RESULT_POLY_DIM colInfoDim;    //�����蔻����z��
    MV1_COLL_RESULT_POLY colInfo;           //�����蔻����

    VECTOR localStart;                      //���[�J���n�_���W
    VECTOR localEnd;                        //���[�J���I�_���W
    VECTOR worldStart;                      //���[���h�n�_���W
    VECTOR worldEnd;                        //���[���h�I�_���W
    VECTOR worldCenter;                     //���[���h���S���W
    float radius;                           //���a
};

