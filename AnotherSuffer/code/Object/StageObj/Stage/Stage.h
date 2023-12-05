#pragma once
#include"../../ObjBase/ObjBase.h"

/// <summary>
/// �X�e�[�W
/// </summary>
class Stage final:public ObjBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Stage(VECTOR pos);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Stage();

private:
    /// <summary>
    /// �X�V����
    /// </summary>
    /// <param name="deltaTime">�f���^�^�C��</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// �`�揈��
    /// </summary>
    void Draw() override;
};

