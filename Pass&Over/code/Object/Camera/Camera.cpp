#include "Camera.h"

// �R���X�g���N�^ //

Camera::Camera()
    :ObjBase(ObjTag::CAMERA)
{
    SetCameraNearFar(0.1f, 500.0f) ;
}

// �f�X�g���N�^ //

Camera::~Camera()
{

}

// �X�V���� //

void Camera::Update(const float deltaTime)
{
    objPos = VGet(-250, 150, 0);
}

// �`�揈�� //

void Camera::Draw()
{
    SetCameraPositionAndTarget_UpVecY(objPos, VGet(0, 0, 0));
}