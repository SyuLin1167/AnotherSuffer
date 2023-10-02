#include<DxLib.h>

#include"../../Object/ObjMgr/ObjMgr.h"
#include"../../Object/Camera/Camera.h"
#include"../../Object/CharaObj/Player/Player.h"
#include"../SceneBase/SceneBase.h"
#include "Play.h"

// コンストラクタ //

Play::Play()
{
    ObjMgr::AddObj(new Camera);
    ObjMgr::AddObj(new Player);
}

// デストラクタ //

Play::~Play()
{

}

// シーン更新処理 //

SceneBase* Play::UpdateScene(const float deltaTime)
{
    ObjMgr::UpdateObj(deltaTime);
    return this;
}

// シーン描画処理 //

void Play::DrawScene()
{
    ObjMgr::DrawObj();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "play");
}