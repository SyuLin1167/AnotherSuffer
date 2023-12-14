#include"../Window/Window.h"
#include"../GameSetting/GameSetting.h"
#include"../../Scene/SceneManager/SceneManager.h"

#include "GameManager.h"

GameManager::GameManager()
{
    //ログの非表示
    SetOutApplicationLogValidFlag(false);

    //初期化
    Window::InitWindow();
    GameSetting::InitGameSetting();
    SceneManager::InitSceneManager();
}

GameManager::~GameManager()
{
    //処理なし
}

void GameManager::Procces()
{
    //ゲームループ実行
    SceneManager::GameLoop();
}