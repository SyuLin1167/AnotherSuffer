#include<DxLib.h>

#include"../SceneBase/SceneBase.h"
#include"../Play/Play.h"
#include"../../Object/ObjManager/ObjManager.h"
#include "Title.h"

/// <summary>
/// コンストラクタ
/// </summary>
Title::Title()
    :SceneBase()
{
}

/// <summary>
/// デストラクタ
/// </summary>
Title::~Title()
{
}

/// <summary>
/// シーン更新処理
/// </summary>
/// <param name="deltaTime">:フレームレート</param>
/// <returns>次フレームのシーン</returns>
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

/// <summary>
/// シーン描画処理
/// </summary>
void Title::DrawScene()
{
    ObjManager::DrawObj();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
}
