#pragma once
#include"../../ObjBase/ObjBase.h"

/// <summary>
/// TitleCamera�N���X
/// </summary>
class TitleCamera final:public ObjBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    TitleCamera();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~TitleCamera();

private:
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name="deltaTime">:�f���^�^�C��</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// �`��
    /// </summary>
    void Draw() override;

    std::shared_ptr<ObjBase> player;            //�v���C���[
    int handle;

    float rotRad;                               //��]�p
    float rotAngle;                             //��]����
};

