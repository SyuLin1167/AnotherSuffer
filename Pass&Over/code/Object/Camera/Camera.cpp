#include "Camera.h"

// コンストラクタ //

Camera::Camera()
    :ObjBase(ObjTag::CAMERA)
{
    SetCameraNearFar(0.1f, 500.0f) ;
}

// デストラクタ //

Camera::~Camera()
{

}

// 更新処理 //

void Camera::Update(const float deltaTime)
{
    objPos = VGet(-250, 150, 0);
}

// 描画処理 //

void Camera::Draw()
{
    SetCameraPositionAndTarget_UpVecY(objPos, VGet(0, 0, 0));
}