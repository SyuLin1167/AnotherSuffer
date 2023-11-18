#include"../Window/Window.h"
#include"../GameSetting/GameSetting.h"
#include"../../Scene/SceneManager/SceneManager.h"

#include "GameManager.h"

GameManager::GameManager()
{
    //ƒƒO‚Ì”ñ•\Ž¦
    SetOutApplicationLogValidFlag(false);

    //‰Šú‰»ˆ—
    Window::Init();
    GameSetting::Init();
    sceneManager.reset(new SceneManager);
}

GameManager::~GameManager()
{
    //ˆ—‚È‚µ
}

void GameManager::Procces()
{
    sceneManager->GameLoop();
}