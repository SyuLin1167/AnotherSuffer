#include "GameMgr.h"
#include<DxLib.h>
#include<memory>

#include"../GameSetting/GameSetting.h"

// �R���X�g���N�^ //

GameMgr::GameMgr()
{
    std::shared_ptr<GameSetting> gmSet(new GameSetting);
}

// �f�X�g���N�^ //

GameMgr::~GameMgr()
{

}

// ���� //

void GameMgr::Procces()
{
	
}