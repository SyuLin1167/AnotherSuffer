#include"../Window/Window.h"
#include"../GameSetting/GameSetting.h"
#include"../../Scene/SceneMgr/SceneMgr.h"

#include "GameManager.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
GameManager::GameManager()
{
    //���O�̔�\��
    SetOutApplicationLogValidFlag(false);

    //����������
    Window::Init();
    GameSetting::Init();
    sceneMgr.reset(new SceneMgr);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
GameManager::~GameManager()
{
    //�����Ȃ�
}

/// <summary>
/// ����
/// </summary>
void GameManager::Procces()
{
    sceneMgr->GameLoop();
}