#include<DxLib.h>

#include"../../KeyStatus/KeyStatus.h"
#include"../../Object/ObjManager/ObjManager.h"
#include"../../Collision/CollisionManager/ColManager.h"
#include"../../Object/Camera/FirstPersonView/FirstPersonView.h"
#include"../../Object/CharaObj/Player/Player.h"
#include"../../Object/StageObj/StageManager/StageManager.h"
#include"../SceneBase/SceneBase.h"
#include"../Title/Title.h"
#include "Play.h"

Play::Play()
{
    ColManager::InitColManager();
    ObjManager::AddObj(new FirstPersonView);
    ObjManager::AddObj(new Player);
    stageManager.reset(new StageManager);
}

Play::~Play()
{
    //�����Ȃ�
}

SceneBase* Play::UpdateScene(const float deltaTime)
{
    //�I�u�W�F�N�g�X�V
    ObjManager::UpdateObj(deltaTime);
    //ObjManager::OnColllsionObj();
    ColManager::CheckCollisionPair();
    //�V�[���؂�ւ�
    if (KeyStatus::KeyStateDecision(KEY_INPUT_RETURN, ONINPUT))
    {
        ObjManager::DeleteAllObj();
        return new Title;
    }

    return this;
}

void Play::DrawScene()
{
    //�I�u�W�F�N�g�`��
    ObjManager::DrawObj();
    //stageManager->DebugDraw();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "play");
}
