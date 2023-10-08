#include<DxLib.h>
#include<assert.h>

#include"../SceneBase/SceneBase.h"
#include"../../Object/ObjManager/ObjManager.h"
#include"../../Asset/AssetMgr/AssetMgr.h"
#include"../../FPS/FPS.h"
#include"../Title/Title.h"
#include "SceneMgr.h"

// コンストラクタ //

SceneMgr::SceneMgr()
    :holdScene(nullptr)
{
    ObjManager::InitObjManager();
    AssetMgr::InitAssetMgr();

    fps.reset(new FPS);
    nowScene.emplace(new Title);
}

// デストラクタ //

SceneMgr::~SceneMgr()
{
}

// ゲームループ //

void SceneMgr::GameLoop()
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

// シーン更新処理 //

void SceneMgr::UpdateScene()
{
    //現在のシーンを更新してtmpSceneに代入
    fps->Update();
    holdScene=nowScene.top()->UpdateScene(fps->GetDeltaTime());
}

// シーン描画処理 //

void SceneMgr::DrawScene()
{
    //現在のシーンを描画
    ClearDrawScreen();
    nowScene.top()->DrawScene();
    ScreenFlip();
}

// シーン切り替え処理 //

void SceneMgr::ChangeScene()
{
    //nowSceneがtmpSceneと異なっていたら解放して代入
    if (nowScene.top().get() != holdScene)
    {
        nowScene.pop();
        nowScene.emplace(holdScene);

        assert(!nowScene.empty());
    }
}