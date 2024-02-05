#include<DxLib.h>

#include"../../KeyStatus/KeyStatus.h"
#include"../../Object/ObjManager/ObjManager.h"
#include"../../Collision/CollisionManager/CollisionManager.h"
#include"../../Object/Camera/FirstPersonView/FirstPersonView.h"
#include"../../Object/CharaObj/Player/Player.h"
#include"../../Object/CharaObj/Enemy/Enemy.h"
#include"../../Object/StageObj/StageManager/StageManager.h"
#include"../SceneBase/SceneBase.h"
#include"../Title/Title.h"
#include "Play.h"

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
    ObjManager::UpdateObj(deltaTime);
    //ObjManager::OnColllsionObj();
    CollisionManager::CheckCollisionPair();
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
    DrawBox(25, 25, 280, 160, GetColor(255, 255, 0), true);

    ChangeFont(HElP_ME.c_str(), DX_CHARSET_DEFAULT);
    DrawFormatString(50, 50, GetColor(0, 0, 0), "%d LEFT", StageManager::GetBarricadeNum());
    ChangeFont(msGothic.c_str(), DX_CHARSET_DEFAULT);
    
#ifdef _DEBUG
    DrawFormatString(0, 0, GetColor(255, 255, 255), "play %d",StageManager::GetBarricadeNum());
#endif // _DEBUG
}
