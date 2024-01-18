#include "Camera.h"
#include"../../Object/ObjManager/ObjManager.h"
#include"../Math/Math.h"

static constexpr int PLAYER_HEAD_FRAME = 10;      //プレイヤー頭部フレーム

Camera::Camera()
    :ObjBase(ObjTag.CAMERA)
{
    SetCameraNearFar(0.1f, 500.0f) ;
    //仮ライト
    handle = CreatePointLightHandle(objPos,  150.0f, 0.0f, 0.0f, 0.0005f);
}

Camera::~Camera()
{
    DeleteLightHandle(handle);
}

void Camera::Update(const float deltaTime)
{
    rotAngle += deltaTime;
    rotRad = math::DegToRad(rotAngle);
    float x = cosf(rotAngle) - cosf(rotAngle) * sinf(rotAngle);
    float z= sinf(rotAngle) - sinf(rotAngle) * cosf(rotAngle);
    objLocalPos=VAdd(objWorldPos,VGet(x*x, cosf(rotAngle) * sinf(rotAngle) + 50, z * z ));
    //player = ObjManager::GetObj(ObjTag.PLAYER)[0];
    //objLocalPos = player->GetObjFramePos(PLAYER_HEAD_FRAME);
    //MV1SetOpacityRate(player->GetObjHandle(), 1.0f);
    CalcObjPos();
    SetLightPositionHandle(handle, objPos);
    //objPos = VGet(0, 50, 0);
}

void Camera::Draw()
{
    player = ObjManager::GetObj(ObjTag.PLAYER)[0];
    VECTOR aimPos = player->GetObjFramePos(10);
    SetCameraPositionAndTarget_UpVecY(objPos,VGet(50,10,20));
}