#include<DxLib.h>

#include"../SceneBase/SceneBase.h"
#include"../Play/Play.h"
#include"../../Object/ObjManager/ObjManager.h"
#include "Title.h"

// コンストラクタ //

Title::Title()
    :SceneBase()
{
}

// デストラクタ //

Title::~Title()
{
}

// シーン更新処理 //

SceneBase* Title::UpdateScene(const float deltaTime)
{
    ObjManager::UpdateObj(deltaTime);

    if (CheckHitKey(KEY_INPUT_RETURN))
    {
        ObjManager::DeleteAllObj();
        return new Play;
    }

    return this;
}

// シーン描画処理 //

void Title::DrawScene()
{
    ObjManager::DrawObj();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
}
