#include"../../ObjManager/ObjManager.h"
#include "FixedCamera.h"


static constexpr int ENEMY_HEAD_FRAME = 10;      //エネミー頭部フレーム

FixedCamera::FixedCamera(const VECTOR& pos, const VECTOR& dir)
    :CharaObjBase(ObjTag.CAMERA)
{
    objLocalPos = pos;
    objDir = dir;
    enemy = ObjManager::GetObj(ObjTag.ENEMY, 0);
    lightHandle = CreateSpotLightHandle(objPos, objDir, DX_PI_F, DX_PI_F / 2, 150.0f, 0.0f, 0.0f, 0.0005f);
}

FixedCamera::~FixedCamera()
{
    //処理なし
}

void FixedCamera::Update(const float deltaTime)
{
    CalcObjPos();
    YAxisData->RotateToAim(VNorm(VSub(enemy->GetObjFramePos(ENEMY_HEAD_FRAME), objPos)));
    SetLightDirectionHandle(lightHandle, objDir);
    SetLightPositionHandle(lightHandle, VAdd(objPos, VScale(objDir, -5)));
}

void FixedCamera::Draw()
{
    //視点を移動
    SetCameraPositionAndTarget_UpVecY(objPos, VAdd(objPos, objDir));
    DrawFormatString(1500, 0, GetColor(255, 255, 255), "camera %f,%f,%f", objPos.x, objPos.y, objPos.z);
}

