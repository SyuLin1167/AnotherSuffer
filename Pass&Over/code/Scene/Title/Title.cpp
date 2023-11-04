#include<DxLib.h>

#include"../../KeyStatus/KeyStatus.h"
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
    //処理なし
}

/// <summary>
/// デストラクタ
/// </summary>
Title::~Title()
{
    //処理なし
}

/// <summary>
/// シーン更新処理
/// </summary>
/// <param name="deltaTime">:フレームレート</param>
/// <returns>次フレームのシーン</returns>
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

/// <summary>
/// シーン描画処理
/// </summary>
void Title::DrawScene()
{
    //オブジェクト描画
    ObjManager::DrawObj();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
}
