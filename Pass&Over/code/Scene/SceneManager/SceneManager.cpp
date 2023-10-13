#include<DxLib.h>
#include<assert.h>

#include"../SceneBase/SceneBase.h"
#include"../../Object/ObjManager/ObjManager.h"
#include"../../Asset/AssetManager/AssetManager.h"
#include"../../FPS/FPS.h"
#include"../Title/Title.h"
#include "SceneManager.h"

SceneManager::SceneManager()
    :holdScene(nullptr)
    , fps(new FPS)
{
    ObjManager::InitObjManager();
    AssetManager::InitAssetManager();

    nowScene.emplace(new Title);
}

SceneManager::~SceneManager()
{
    //処理なし
}

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

void SceneManager::UpdateScene()
{
    //現在のシーンを更新してtmpSceneに代入
    fps->Update();
    holdScene=nowScene.top()->UpdateScene(fps->GetDeltaTime());
}

void SceneManager::DrawScene()
{
    //現在のシーンを描画
    ClearDrawScreen();
    nowScene.top()->DrawScene();
    ScreenFlip();
}

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