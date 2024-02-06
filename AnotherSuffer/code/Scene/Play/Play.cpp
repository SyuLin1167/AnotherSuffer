#include<DxLib.h>

#include"../SceneBase/SceneBase.h"
#include "Play.h"
#include"../../KeyStatus/KeyStatus.h"
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

static const std::string HElP_ME = "horroroid";
static const LPCSTR fileName = "../assets/font/horroroid.ttf";
static const std::string msGothic = "�l�r�@�S�V�b�N";    //�t�H���g��
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
    //�I�u�W�F�N�g�X�V
    MousePoint::UnVisible();
    ObjManager::UpdateObj(deltaTime);
    CollisionManager::CheckCollisionPair();
    MiniMap::Update();

    //�V�[���؂�ւ�
    if (!ObjManager::GetObj(ObjTag.ENEMY, 0) || KeyStatus::KeyStateDecision(KEY_INPUT_RETURN, ONINPUT))
    {
        ObjManager::DeleteAllObj();
        CollisionManager::DeleteCollision();
        return new Title;
    }

    return this;
}

void Play::DrawScene()
{
    //�I�u�W�F�N�g�`��
    ObjManager::DrawObj();

    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
    DrawBox(25, 25, 280, 160, GetColor(255, 255, 0), true);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

    MiniMap::Draw();
    MousePoint::Draw();
    PhysicalMeter::Draw();

    SetFontSize(TEXT_SIZE);
    ChangeFont(HElP_ME.c_str(), DX_CHARSET_DEFAULT);
    DrawFormatString(50, 50, GetColor(0, 0, 0), "%d LEFT", StageManager::GetBarricadeNum());
    ChangeFont(msGothic.c_str(), DX_CHARSET_DEFAULT);
    SetFontSize(10);
    
#ifdef _DEBUG
    DrawFormatString(0, 0, GetColor(255, 255, 255), "play %d",StageManager::GetBarricadeNum());
#endif // _DEBUG
}
