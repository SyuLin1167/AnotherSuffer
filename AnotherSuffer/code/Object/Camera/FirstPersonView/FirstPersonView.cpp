#include"../../ObjManager/ObjManager.h"
#include"../../../GameSystem/Window/Window.h"
#include "FirstPersonView.h"

FirstPersonView::FirstPersonView()
    :ObjBase(ObjTag.CAMERA)
    , mousePosX(static_cast<int>(Window::GetWindowSize().x / 2))
    , mousePosY(static_cast<int>(Window::GetWindowSize().y / 2))
    , angleVel(VGet(0, 0, 0))
    , cameraYaw(0)
    , cameraPitch(0)
{
    SetCameraNearFar(CAMERA_NEAR, CAMERA_FAR);
    objLocalPos = ANGLE_POS;

    SetMousePoint(mousePosX, mousePosY);
    SetMouseDispFlag(false);
}

FirstPersonView::~FirstPersonView()
{
    //処理なし
}

void FirstPersonView::Update(const float deltaTime)
{
    ObjBase* player = ObjManager::GetObj(ObjTag.PLAYER)[0].get();
    objWorldPos = player->GetObjPos();

    GetMousePoint(&mousePosX, &mousePosY);
    angleVel.x = static_cast<float>(mousePosX - Window::GetWindowSize().x / 2);
    angleVel.y = static_cast<float>(mousePosY - Window::GetWindowSize().y / 2);

    if (abs(angleVel.x) > 0)
    {
        cameraYaw -= angleVel.x * DX_PI_F * deltaTime/10;
    }
    if (abs(angleVel.y) > 0)
    {
        if (abs(cameraPitch) <= 3.5f)
        {
            cameraPitch -= angleVel.y * DX_PI_F * deltaTime / 10;
        }
        else
        {
            if (cameraPitch > 3.5f)
            {
                cameraPitch = 3.5;
            }
            else
            {
                cameraPitch = -3.5f;
            }
        }
    }

    objDir = VGet(cosf(cameraYaw), cameraPitch, sinf(cameraYaw));

    //マウスポインターは画面の中心
    SetMousePoint(static_cast<int>(Window::GetWindowSize().x / 2), static_cast<int>(Window::GetWindowSize().y / 2));

    CalcObjPos();
}

void FirstPersonView::Draw()
{
    //カーソルの移動した方向に視点を移動
    SetCameraPositionAndTarget_UpVecY(objPos, VAdd(objPos, objDir));

    DrawFormatString(0, 300, GetColor(0, 255, 255), "%f", objDir.x);
    DrawFormatString(0, 350, GetColor(0, 255, 255), "%f", objDir.y);
    DrawFormatString(0, 400, GetColor(0, 255, 255), "%f", objDir.z);
}