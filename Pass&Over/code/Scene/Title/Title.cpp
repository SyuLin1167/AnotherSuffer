#include<DxLib.h>

#include"../SceneBase/SceneBase.h"
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

SceneBase* Title::SceneUpdate(const float& deltaTime)
{
    return this;
}

void Title::SceneDraw()
{
    DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
}
