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
{
    StageManager::InitStageManager();
    ObjManager::AddObj(new Player);
    ObjManager::AddObj(new FirstPersonView);
    ObjManager::AddObj(new Enemy);
}

Play::~Play()
{
    //処理なし
}

SceneBase* Play::UpdateScene(const float deltaTime)
{
    //オブジェクト更新
    ObjManager::UpdateObj(deltaTime);
    //ObjManager::OnColllsionObj();
    CollisionManager::CheckCollisionPair();
    //シーン切り替え
    if (KeyStatus::KeyStateDecision(KEY_INPUT_RETURN, ONINPUT))
    {
        ObjManager::DeleteAllObj();
        CollisionManager::DeleteCollision();
        return new Title;
    }

    return this;
}

void Play::DrawScene()
{
    //オブジェクト描画
    ObjManager::DrawObj();

#ifdef _DEBUG
    DrawFormatString(0, 0, GetColor(255, 255, 255), "play");
#endif // _DEBUG
}
