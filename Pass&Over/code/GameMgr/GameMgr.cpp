#include "GameMgr.h"
#include<DxLib.h>
#include<memory>

#include"../GameSetting/GameSetting.h"

// �R���X�g���N�^ //

GameMgr::GameMgr()
    :gmSet(new GameSetting)
{
}

// �f�X�g���N�^ //

GameMgr::~GameMgr()
{
    delete gmSet;
}

// ���� //

void GameMgr::Procces()
{
    
}