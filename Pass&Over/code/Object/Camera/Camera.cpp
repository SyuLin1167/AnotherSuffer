#include "Camera.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Camera::Camera()
    :ObjBase(ObjTag::CAMERA)
{
    SetCameraNearFar(0.1f, 500.0f) ;
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Camera::~Camera()
{
    //�����Ȃ�
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="deltaTime">:�t���[�����[�g</param>
void Camera::Update(const float deltaTime)
{
    objPos = VGet(-250, 150, 0);
}

/// <summary>
/// �`�揈��
/// </summary>
void Camera::Draw()
{
    SetCameraPositionAndTarget_UpVecY(objPos, VGet(0, 0, 0));
}