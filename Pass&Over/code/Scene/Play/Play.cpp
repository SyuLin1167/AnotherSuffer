#include<DxLib.h>

#include"../../Object/ObjManager/ObjManager.h"
#include"../../Object/Camera/Camera.h"
#include"../../Object/CharaObj/Player/Player.h"
#include"../SceneBase/SceneBase.h"
#include "Play.h"

// コンストラクタ //

Play::Play()
{
    ObjManager::AddObj(new Camera);
    ObjManager::AddObj(new Player);
}

// デストラクタ //

Play::~Play()
{

}

// シーン更新処理 //

SceneBase* Play::UpdateScene(const float deltaTime)
{
    ObjManager::UpdateObj(deltaTime);
    return this;
}

// シーン描画処理 //

void Play::DrawScene()
{
    ObjManager::DrawObj();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "play");
}