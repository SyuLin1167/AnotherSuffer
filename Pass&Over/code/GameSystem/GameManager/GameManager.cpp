#include"../Window/Window.h"
#include"../GameSetting/GameSetting.h"
#include"../../Scene/SceneMgr/SceneMgr.h"

#include "GameManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
GameManager::GameManager()
{
    //ログの非表示
    SetOutApplicationLogValidFlag(false);

    //初期化処理
    Window::Init();
    GameSetting::Init();
    sceneMgr.reset(new SceneMgr);
}

/// <summary>
/// デストラクタ
/// </summary>
GameManager::~GameManager()
{
    //処理なし
}

/// <summary>
/// 処理
/// </summary>
void GameManager::Procces()
{
    sceneMgr->GameLoop();
}