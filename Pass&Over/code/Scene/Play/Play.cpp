#include<DxLib.h>

#include"../SceneBase/SceneBase.h"
#include "Play.h"

// コンストラクタ //

Play::Play()
{

}

// デストラクタ //

Play::~Play()
{

}

// シーン更新処理 //

SceneBase* Play::UpdateScene(const float deltaTime)
{
    return this;
}

// シーン描画処理 //

void Play::DrawScene()
{
    DrawFormatString(0, 0, GetColor(255, 255, 255), "play");
}