#include<DxLib.h>
#include<memory>

#include"../GameSetting/GameSetting.h"
#include"../Scene/SceneMgr/SceneMgr.h"
#include "GameMgr.h"

// �R���X�g���N�^ //

GameMgr::GameMgr()
{
}

// �f�X�g���N�^ //

GameMgr::~GameMgr()
{
}

// ���� //

void GameMgr::Procces()
{
    std::shared_ptr<GameSetting> gmSet(new GameSetting);
    std::shared_ptr<SceneMgr> sceneMgr(new SceneMgr);
    sceneMgr->GameLoop();
}