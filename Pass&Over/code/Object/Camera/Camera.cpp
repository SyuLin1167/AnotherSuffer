#include "Camera.h"

Camera::Camera()
    :ObjBase(ObjTag.CAMERA)
{
    SetCameraNearFar(0.1f, 500.0f) ;
}

Camera::~Camera()
{
    //ˆ—‚È‚µ
}

void Camera::Update(const float deltaTime)
{
    objPos = VGet(-80, 80, 0);
}

void Camera::Draw()
{
    SetCameraPositionAndTarget_UpVecY(objPos, VGet(0, 0, 0));
}