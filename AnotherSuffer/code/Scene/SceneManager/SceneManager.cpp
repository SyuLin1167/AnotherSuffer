#include<DxLib.h>

#include"../SceneBase/SceneBase.h"
#include"../../Object/ObjManager/ObjManager.h"
#include"../../Asset/AssetManager/AssetManager.h"
#include"../../Collision/CollisionManager/CollisionManager.h"
#include"../../FPS/FPS.h"
#include"../../KeyStatus/KeyStatus.h"
#include"../Title/Title.h"
#include "SceneManager.h"

std::unique_ptr<SceneManager> SceneManager::singleton = nullptr;

void SceneManager::InitSceneManager()
{
    //インスタンス初期化
    if (!singleton)
    {
        singleton.reset(new SceneManager);
    }
}

SceneManager::SceneManager()
    :holdScene(nullptr)
{
    //管理クラス類初期化
    FPS::InitFPS();
    KeyStatus::InitKeyStatus();
    ObjManager::InitObjManager();
    AssetManager::InitAssetManager();
    CollisionManager::InitColManager();

    //初期シーン設定
    nowScene.emplace(new Title);
}

SceneManager::~SceneManager()
{
    //処理なし
}

void SceneManager::GameLoop()
{
    //ウィンドウが閉じられるまでループする
    while (!ProcessMessage() && !KeyStatus::KeyStateDecision(KEY_INPUT_ESCAPE, ONINPUT))
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
    FPS::Update();
    singleton->holdScene = singleton->nowScene.top()->UpdateScene(FPS::GetDeltaTime());
}

void SceneManager::DrawScene()
{
    //現在のシーンを描画
    ClearDrawScreen();
    singleton->nowScene.top()->DrawScene();
    ScreenFlip();
}

void SceneManager::ChangeScene()
{
    //nowSceneがtmpSceneと異なっていたら解放して代入
    if (singleton->nowScene.top().get() != singleton->holdScene)
    {
        singleton->nowScene.pop();
        singleton->nowScene.emplace(singleton->holdScene);
    }
}