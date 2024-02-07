#include<DxLib.h>

#include"../SceneBase/SceneBase.h"
#include "Play.h"
#include"../../KeyStatus/KeyStatus.h"
#include"../../GameSystem/Window/Window.h"
#include"../../Object/ObjManager/ObjManager.h"
#include"../../Collision/CollisionManager/CollisionManager.h"
#include"../../Object/Camera/FirstPersonView/FirstPersonView.h"
#include"../../Object/StageObj/StageManager/StageManager.h"
#include"../../Object/CharaObj/Player/Player.h"
#include"../../Object/CharaObj/Enemy/Enemy.h"
#include"../../UI/MiniMap/MiniMap.h"
#include"../../UI/MousePoint/MousePoint.h"
#include"../../UI/PhysicalMeter/PhysicalMeter.h"
#include"../Title/Title.h"
#include"../Clear/Clear.h"

static const std::string HElP_ME = "horroroid";
static const LPCSTR fileName = "../assets/font/horroroid.ttf";
static const std::string msGothic = "ＭＳ　ゴシック";    //フォント名
static constexpr int TEXT_SIZE = 80;

Play::Play()
    :SceneBase(SceneTag.PLAY)
{
    StageManager::InitStageManager();
    ObjManager::AddObj(new FirstPersonView);
    ObjManager::AddObj(new Player);
    ObjManager::AddObj(new Enemy);

    MiniMap::InitMiniMap();
    MousePoint::InitMousePoint();
    PhysicalMeter::InitPhysicalMeter();

    AddFontResource(fileName);
    SetFontSize(TEXT_SIZE);
}

Play::~Play()
{
    RemoveFontResource(fileName);
}

SceneBase* Play::UpdateScene(const float deltaTime)
{
    //オブジェクト更新
    MousePoint::UnVisible();
    ObjManager::UpdateObj(deltaTime);
    CollisionManager::CheckCollisionPair();
    MiniMap::Update();

    //シーン切り替え
    if (!ObjManager::GetObj(ObjTag.ENEMY, 0))
    {
        ObjManager::DeleteAllObj();
        CollisionManager::DeleteCollision();
        return new Title;
    }
    else if (StageManager::GetBarricadeNum() <= 0)
    {
        ObjManager::DeleteAllObj();
        CollisionManager::DeleteCollision();
        return new Clear;
    }

    return this;
}

void Play::DrawScene()
{
    //オブジェクト描画
    ObjManager::DrawObj();


    MiniMap::Draw();
    MousePoint::Draw();
    PhysicalMeter::Draw();

    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
    DrawBox(25, 25, 280, 160, GetColor(255, 255, 0), true);
    if (!MiniMap::IsVisible())
    {
        DrawBox(35, Window::GetWindowSize().y - 75, 250, Window::GetWindowSize().y - 20, GetColor(150, 150, 150), true);
    }
    if (!PhysicalMeter::IsVisible())
    {
        DrawBox(Window::GetWindowSize().x/2 - 165, Window::GetWindowSize().y - 75,
            Window::GetWindowSize().x / 2+165, Window::GetWindowSize().y - 20, GetColor(150, 150, 150), true);
    }
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

    SetFontSize(TEXT_SIZE);
    ChangeFont(HElP_ME.c_str(), DX_CHARSET_DEFAULT);
    DrawFormatString(50, 50, GetColor(0, 0, 0), "%d LEFT", StageManager::GetBarricadeNum());

    SetFontSize(TEXT_SIZE/2);
    if (!MiniMap::IsVisible())
    {
        DrawFormatString(50, Window::GetWindowSize().y-70, GetColor(0, 0, 0), "MAP in SPACE");
    }
    if (!PhysicalMeter::IsVisible())
    {
        DrawFormatString(Window::GetWindowSize().x/2-130, Window::GetWindowSize().y - 70, GetColor(0, 0, 0), "RUNNING on LSHIFT");
    }
    ChangeFont(msGothic.c_str(), DX_CHARSET_DEFAULT);
    SetFontSize(10);
#ifdef _DEBUG
    DrawFormatString(0, 0, GetColor(255, 255, 255), "play %d",StageManager::GetBarricadeNum());
#endif // _DEBUG
}
