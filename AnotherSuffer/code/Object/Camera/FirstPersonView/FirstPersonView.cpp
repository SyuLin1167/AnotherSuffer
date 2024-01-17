#include"../../ObjManager/ObjManager.h"
#include"../../../GameSystem/Window/Window.h"
#include "FirstPersonView.h"
#include"../../Math/Math.h"

static constexpr float LOOK_HEIGHT = 10.0f;    //視点高さ
static constexpr int PLAYER_HEAD_FRAME = 10;      //プレイヤー頭部フレーム
static constexpr float MAX_PITCH = 1.0f;               //ピッチ最大値

FirstPersonView::FirstPersonView()
    :ObjBase(ObjTag.CAMERA)
    , mousePosX(static_cast<int>(Window::GetWindowSize().x / 2))
    , mousePosY(static_cast<int>(Window::GetWindowSize().y / 2))
    , angleVel()
    , cameraYaw(-DX_PI_F / 2.0f)
    , cameraPitch(-DX_PI_F / 4.0f)
    , cameraViewMat(MGetIdent())
{
    SetCameraNearFar(CAMERA_NEAR, CAMERA_FAR);

    SetMousePoint(mousePosX, mousePosY);
    SetMouseDispFlag(false);
}

FirstPersonView::~FirstPersonView()
{
    //処理なし
}

void FirstPersonView::Update(const float deltaTime)
{
    //座標取得
    player = ObjManager::GetObj(ObjTag.PLAYER)[0];
    assert(player);
    objWorldPos = VAdd(player->GetObjFramePos(PLAYER_HEAD_FRAME),objDir);

    //視点移動算出
    CalcMoveView(deltaTime);
    objDir =  VGet(sinf(-cameraYaw), cameraPitch, cosf(-cameraYaw));
    cameraViewMat = MMult(MGetRotY(cameraYaw), MGetRotX(cameraPitch));

    //視点分カメラ座標を僅かに動かす
    objLocalPos = VNorm(objDir);
    objLocalPos.y=LOOK_HEIGHT;

    //マウスポインターは画面の中心
    SetMousePoint(static_cast<int>(Window::GetWindowSize().x / 2), static_cast<int>(Window::GetWindowSize().y / 2));

    //座標更新
    CalcObjPos();
}

void FirstPersonView::CalcMoveView(const float deltaTime)
{
    //マウス移動量
    GetMousePoint(&mousePosX, &mousePosY);
    angleVel.x = static_cast<float>(mousePosX - Window::GetWindowSize().x / 2);
    angleVel.y = static_cast<float>(mousePosY - Window::GetWindowSize().y / 2);

    //カメラ回転値算出
    if (abs(angleVel.x) > 0)
    {
        cameraYaw -= angleVel.x * DX_PI_F * deltaTime/10;
    }
    if (abs(angleVel.y) > 0)
    {
        if (abs(cameraPitch) <= MAX_PITCH)
        {
            cameraPitch -= angleVel.y * DX_PI_F * deltaTime / 10;
        }
        else
        {
            //ピッチの制限
            if (cameraPitch > MAX_PITCH)
            {
                cameraPitch = MAX_PITCH;
            }
            else
            {
                cameraPitch = -MAX_PITCH;
            }
        }
    }
}

void FirstPersonView::Draw()
{
    //視点を移動
    SetCameraViewMatrix(MMult( MInverse(MGetTranslate(objPos)),cameraViewMat));

    DrawCircle(objPos.z+60, objPos.x+60, 10, GetColor(255, 255, 255));
}