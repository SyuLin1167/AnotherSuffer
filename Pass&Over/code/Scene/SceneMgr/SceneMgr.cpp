#include<DxLib.h>
#include<assert.h>

#include"../SceneBase/SceneBase.h"
#include"../../TimeMgr/TimeMgr.h"
#include"../Title/Title.h"
#include "SceneMgr.h"

// コンストラクタ //

SceneMgr::SceneMgr()
    :tmpScene(nullptr)
{
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
        SceneUpdate();
        SceneDraw();
        SceneChange();
    }
}

// シーン更新処理 //

void SceneMgr::SceneUpdate()
{
    //現在のシーンを更新してtmpSceneに代入
    tmpScene = nowScene.top()->SceneUpdate(timeMgr->DeltaTime());
}

// シーン描画処理 //

void SceneMgr::SceneDraw()
{
    //現在のシーンを描画
    ClearDrawScreen();
    nowScene.top()->SceneDraw();
    ScreenFlip();
}

// シーン切り替え処理 //

void SceneMgr::SceneChange()
{
    //nowSceneがtmpSceneと異なっていたら解放して代入
    if (nowScene.top().get() != tmpScene)
    {
        nowScene.pop();
        nowScene.emplace(tmpScene);

        assert(!nowScene.empty());
    }
}