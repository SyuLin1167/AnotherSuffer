#include "Camera.h"

/// <summary>
/// コンストラクタ
/// </summary>
Camera::Camera()
    :ObjBase(ObjTag::CAMERA)
{
    SetCameraNearFar(0.1f, 500.0f) ;
}

/// <summary>
/// デストラクタ
/// </summary>
Camera::~Camera()
{
    //処理なし
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="deltaTime">:フレームレート</param>
void Camera::Update(const float deltaTime)
{
    objPos = VGet(-250, 150, 0);
}

/// <summary>
/// 描画処理
/// </summary>
void Camera::Draw()
{
    SetCameraPositionAndTarget_UpVecY(objPos, VGet(0, 0, 0));
}