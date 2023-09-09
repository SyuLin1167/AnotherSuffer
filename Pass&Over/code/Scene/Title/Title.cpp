#include<DxLib.h>

#include"../SceneBase/SceneBase.h"
#include"../Play/Play.h"
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

SceneBase* Title::UpdateScene(const float& deltaTime)
{
    if (CheckHitKey(KEY_INPUT_RETURN))
    {
        return new Play;
    }

    return this;
}

void Title::DrawScene()
{
    DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
}
