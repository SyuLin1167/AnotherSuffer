#include<DxLib.h>
#include<assert.h>

#include"../SceneBase/SceneBase.h"
#include"../../Object/ObjMgr/ObjMgr.h"
#include"../../Asset/AssetMgr/AssetMgr.h"
#include"../../TimeMgr/TimeMgr.h"
#include"../Title/Title.h"
#include "SceneMgr.h"

// コンストラクタ //

SceneMgr::SceneMgr()
    :tmpScene(nullptr)
{
    ObjMgr::InitObjMgr();
    AssetMgr::InitAssetMgr();

    timeMgr.reset(new TimeMgr);
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
        DrawScene();
        ChangeScene();
    }
    ObjMgr::DeleteAllObj();
}

// シーン更新処理 //

void SceneMgr::UpdateScene()
{
    //現在のシーンを更新してtmpSceneに代入
    tmpScene = nowScene.top()->UpdateScene(timeMgr->DeltaTime());
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
    if (nowScene.top().get() != tmpScene)
    {
        nowScene.pop();
        nowScene.emplace(tmpScene);

        assert(!nowScene.empty());
    }
}