#include"../GameSetting/GameSetting.h"
#include"../../Scene/SceneMgr/SceneMgr.h"
#include "GameMgr.h"

// �R���X�g���N�^ //

GameMgr::GameMgr()
{
    gmSet.reset(new GameSetting);
    sceneMgr.reset(new SceneMgr);
}

// �f�X�g���N�^ //

GameMgr::~GameMgr()
{
}

// ���� //

void GameMgr::Procces()
{
    sceneMgr->GameLoop();
}