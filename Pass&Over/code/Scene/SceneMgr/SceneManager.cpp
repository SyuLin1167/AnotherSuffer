#include<DxLib.h>
#include<assert.h>

#include"../SceneBase/SceneBase.h"
#include"../../Object/ObjManager/ObjManager.h"
#include"../../Asset/AssetManager/AssetManager.h"
#include"../../FPS/FPS.h"
#include"../Title/Title.h"
#include "SceneManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
SceneManager::SceneManager()
    :holdScene(nullptr)
    , fps(new FPS)
{
    ObjManager::InitObjManager();
    AssetManager::InitAssetManager();

    nowScene.emplace(new Title);
}

/// <summary>
/// デストラクタ
/// </summary>
SceneManager::~SceneManager()
{
}

/// <summary>
/// ゲームループ
/// </summary>
void SceneManager::GameLoop()
{
    //ウィンドウが閉じられるまでループする
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //シーンのフロー
        UpdateScene();
        ChangeScene();
        DrawScene();
    }
    ObjManager::DeleteAllObj();
}

/// <summary>
/// シーン更新処理
/// </summary>
void SceneManager::UpdateScene()
{
    //現在のシーンを更新してtmpSceneに代入
    fps->Update();
    holdScene=nowScene.top()->UpdateScene(fps->GetDeltaTime());
}

/// <summary>
/// シーン描画処理
/// </summary>
void SceneManager::DrawScene()
{
    //現在のシーンを描画
    ClearDrawScreen();
    nowScene.top()->DrawScene();
    DrawFormatString(0, 100, GetColor(255, 255, 255), "非同期読み込みの数 %d", GetASyncLoadNum());
    ScreenFlip();
}

/// <summary>
/// シーン切り替え処理
/// </summary>
void SceneManager::ChangeScene()
{
    //nowSceneがtmpSceneと異なっていたら解放して代入
    if (nowScene.top().get() != holdScene)
    {
        nowScene.pop();
        nowScene.emplace(holdScene);

        assert(!nowScene.empty());
    }
}