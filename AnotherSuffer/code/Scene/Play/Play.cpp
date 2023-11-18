#include<DxLib.h>

#include"../../KeyStatus/KeyStatus.h"
#include"../../Object/ObjManager/ObjManager.h"
#include"../../Object/Camera/Camera.h"
#include"../../Object/CharaObj/Player/Player.h"
#include"../SceneBase/SceneBase.h"
#include"../Title/Title.h"
#include "Play.h"

Play::Play()
{
    ObjManager::AddObj(new Camera);
    ObjManager::AddObj(new Player);
}

Play::~Play()
{
    //処理なし
}

SceneBase* Play::UpdateScene(const float deltaTime)
{
    //オブジェクト更新
    ObjManager::UpdateObj(deltaTime);

    //シーン切り替え
    if (KeyStatus::KeyStateDecision(KEY_INPUT_RETURN, ONINPUT))
    {
        ObjManager::DeleteAllObj();
        return new Title;
    }

    return this;
}

void Play::DrawScene()
{
    //オブジェクト描画
    ObjManager::DrawObj();
    for (int i = -20; i < 20; i++)
    {
        DrawLine3D(VGet(-200, 0, i * 10), VGet(200, 0, i * 10), GetColor(255, 255, 255));
        DrawLine3D(VGet(i*10, 0, -200), VGet(i*10, 0, 200), GetColor(255, 255, 255));
    }
    DrawFormatString(0, 0, GetColor(255, 255, 255), "play");
}