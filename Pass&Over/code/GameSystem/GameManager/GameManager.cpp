#include"../Window/Window.h"
#include"../GameSetting/GameSetting.h"
#include"../../Scene/SceneMgr/SceneMgr.h"

#include "GameManager.h"

// コンストラクタ //

GameManager::GameManager()
{
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