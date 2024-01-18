#pragma once
#include"../ObjBase/ObjBase.h"

/// <summary>
/// Camera�N���X
/// </summary>
class Camera final:public ObjBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Camera();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Camera();

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

