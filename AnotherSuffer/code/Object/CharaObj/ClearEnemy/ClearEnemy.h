#pragma once
#include"../CharaObjBase/CharaObjBase.h"

/// <summary>
/// �N���A���̓G
/// </summary>
class ClearEnemy:public CharaObjBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    ClearEnemy();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~ClearEnemy();

private:
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name="deltaTime">�f���^�^�C��</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// �L��������
    /// </summary>
    /// <param name="deltaTime">:�f���^�^�C��</param>
    void MoveChara(const float deltaTime) override;

    /// <summary>
    /// �`��
    /// </summary>
    void Draw() override;

    int clearGraph;
};

