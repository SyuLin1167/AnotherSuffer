#include<DxLib.h>

#include"../../KeyStatus/KeyStatus.h"
#include"../SceneBase/SceneBase.h"
#include"../Play/Play.h"
#include"../../Object/ObjManager/ObjManager.h"
#include "Title.h"

Title::Title()
    :SceneBase()
{
    //処理なし
}

Title::~Title()
{
    //処理なし
}

SceneBase* Title::UpdateScene(const float deltaTime)
{
    //オブジェクト更新
    ObjManager::UpdateObj(deltaTime);

    //シーン切り替え
    if (KeyStatus::KeyStateDecision(KEY_INPUT_RETURN, ONINPUT))
    {
        ObjManager::DeleteAllObj();
        return new Play;
    }

    return this;
}

void Title::DrawScene()
{
    //オブジェクト描画
    ObjManager::DrawObj();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
}
