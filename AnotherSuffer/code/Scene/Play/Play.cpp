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

Play::Play()
    :SceneBase(SceneTag.PLAY)
{
    StageManager::InitStageManager();
    ObjManager::AddObj(new FirstPersonView);
    ObjManager::AddObj(new Player);
    ObjManager::AddObj(new Enemy);
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

    
#ifdef _DEBUG
    DrawFormatString(0, 0, GetColor(255, 255, 255), "play %d",StageManager::GetBarricadeNum());
#endif // _DEBUG
}
