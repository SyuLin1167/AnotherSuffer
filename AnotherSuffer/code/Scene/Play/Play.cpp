#include<DxLib.h>

#include"../../KeyStatus/KeyStatus.h"
#include"../../Object/ObjManager/ObjManager.h"
#include"../../Object/Camera/FirstPersonView/FirstPersonView.h"
#include"../../Object/CharaObj/Player/Player.h"
#include"../../Object/StageObj/Stage/Stage.h"
#include"../SceneBase/SceneBase.h"
#include"../Title/Title.h"
#include "Play.h"

Play::Play()
{
    ObjManager::AddObj(new FirstPersonView);
    ObjManager::AddObj(new Player);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (box[i][j] == 1)
            {
                ObjManager::AddObj(new Stage(VGet(i * 20, 0, j * 20)));
            }
        }
    }
}

Play::~Play()
{
    //処理なし
}

SceneBase* Play::UpdateScene(const float deltaTime)
{
    //オブジェクト更新
    ObjManager::UpdateObj(deltaTime);
    ObjManager::OnColllsionObj();

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