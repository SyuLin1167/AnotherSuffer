#pragma once
#include"../ObjBase/ObjBase.h"

/*Camera�N���X*/
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
    /// �X�V����
    /// </summary>
    /// <param name="deltaTime">:�t���[�����[�g</param>
    void Update(const float deltaTime)override;

    /// <summary>
    /// �`�揈��
    /// </summary>
    void Draw()override;
};

