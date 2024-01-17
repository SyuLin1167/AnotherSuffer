#include "Camera.h"
#include"../../Object/ObjManager/ObjManager.h"
#include"../Math/Math.h"

static constexpr int PLAYER_HEAD_FRAME = 10;      //�v���C���[�����t���[��

Camera::Camera()
    :ObjBase(ObjTag.CAMERA)
{
    SetCameraNearFar(0.1f, 500.0f) ;
    //�����C�g
    handle = CreateSpotLightHandle(objPos, objDir, DX_PI_F / 4, DX_PI_F / 2, 150.0f, 0.0f, 0.0f, 0.0005f);
}

Camera::~Camera()
{
    //�����Ȃ�
}

void Camera::Update(const float deltaTime)
{
    rotAngle += deltaTime;
    rotRad = math::DegToRad(rotAngle);
    objLocalPos=VAdd(objWorldPos,VGet(cosf(rotAngle)*2, cosf(rotAngle) * 3, sinf(rotAngle)*4));
    //player = ObjManager::GetObj(ObjTag.PLAYER)[0];
    //objLocalPos = player->GetObjFramePos(PLAYER_HEAD_FRAME);
    //MV1SetOpacityRate(player->GetObjHandle(), 1.0f);
    CalcObjPos();
    SetLightPositionHandle(handle, objPos);
    //objPos = VGet(0, 50, 0);
}

void Camera::Draw()
{
    SetCameraPositionAndTarget_UpVecY(objPos, VGet(50, 0, 20));
}