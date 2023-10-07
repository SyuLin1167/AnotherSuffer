#include"../Window/Window.h"
#include"../GameSetting/GameSetting.h"
#include"../../Scene/SceneMgr/SceneMgr.h"

#include "GameManager.h"

// �R���X�g���N�^ //

GameManager::GameManager()
{
    Window::Init();
    GameSetting::Init();
    sceneMgr.reset(new SceneMgr);
}

// �f�X�g���N�^ //

GameManager::~GameManager()
{
    //�����Ȃ�
}

// ���� //

void GameManager::Procces()
{
    sceneMgr->GameLoop();
}