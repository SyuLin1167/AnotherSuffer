#include"../Window/Window.h"
#include"../GameSetting/GameSetting.h"
#include"../../Scene/SceneMgr/SceneMgr.h"

#include "GameManager.h"

// コンストラクタ //

GameManager::GameManager()
{
    //ログの非表示
    SetOutApplicationLogValidFlag(false);

    //初期化処理
    Window::Init();
    GameSetting::Init();
    sceneMgr.reset(new SceneMgr);
}

// デストラクタ //

GameManager::~GameManager()
{
    //処理なし
}

// 処理 //

void GameManager::Procces()
{
    sceneMgr->GameLoop();
}