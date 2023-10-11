#include<DxLib.h>

#include"../../Object/ObjManager/ObjManager.h"
#include"../../Object/Camera/Camera.h"
#include"../../Object/CharaObj/Player/Player.h"
#include"../SceneBase/SceneBase.h"
#include "Play.h"

/// <summary>
/// コンストラクタ
/// </summary>
Play::Play()
{
    ObjManager::AddObj(new Camera);
    ObjManager::AddObj(new Player);
}

/// <summary>
/// デストラクタ
/// </summary>
Play::~Play()
{

}

/// <summary>
/// シーン更新処理
/// </summary>
/// <param name="deltaTime">:フレームレート</param>
/// <returns>次フレームのシーン</returns>
SceneBase* Play::UpdateScene(const float deltaTime)
{
    ObjManager::UpdateObj(deltaTime);
    return this;
}

/// <summary>
/// シーン描画処理
/// </summary>
void Play::DrawScene()
{
    ObjManager::DrawObj();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "play");
}