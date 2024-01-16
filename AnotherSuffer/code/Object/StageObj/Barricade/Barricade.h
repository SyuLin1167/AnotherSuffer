#pragma once
#include"../StageObjBase/StageObjBase.h"

/// <summary>
/// ���
/// </summary>
class Barricade final:public StageObjBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="pos">:���W</param>
    /// <param name="node">:�m�[�h</param>
    Barricade(const VECTOR pos, std::pair<int, int> node);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Barricade();

    /// <summary>
    /// �����蔻��
    /// </summary>
    /// <param name="colObj">:���肷��I�u�W�F�N�g</param>
    void OnCollisionEnter(class ObjBase* colObj) override;

    /// <summary>
    /// ��ǔj��
    /// </summary>
    void BreakBarricade();

    std::pair<int, int> myNode;             //���g�̃m�[�h
};

