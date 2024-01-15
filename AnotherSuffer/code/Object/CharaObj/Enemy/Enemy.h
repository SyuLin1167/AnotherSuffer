#pragma once
#include"../CharaObjBase/CharaObjBase.h"

/// <summary>
/// �G�L����
/// </summary>
class Enemy final :public CharaObjBase
{
public:
    Enemy();
    ~Enemy();

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
};