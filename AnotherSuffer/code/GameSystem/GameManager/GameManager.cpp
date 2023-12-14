#include"../Window/Window.h"
#include"../GameSetting/GameSetting.h"
#include"../../Scene/SceneManager/SceneManager.h"

#include "GameManager.h"

GameManager::GameManager()
{
    //���O�̔�\��
    SetOutApplicationLogValidFlag(false);

    //������
    Window::InitWindow();
    GameSetting::InitGameSetting();
    SceneManager::InitSceneManager();
}

GameManager::~GameManager()
{
    //�����Ȃ�
}

void GameManager::Procces()
{
    //�Q�[�����[�v���s
    SceneManager::GameLoop();
}