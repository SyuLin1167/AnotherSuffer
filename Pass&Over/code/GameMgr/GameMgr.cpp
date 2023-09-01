#include "GameMgr.h"
#include<DxLib.h>
#include<memory>

#include"../GameSetting/GameSetting.h"

// コンストラクタ //

GameMgr::GameMgr()
{
    std::shared_ptr<GameSetting> gmSet(new GameSetting);
}

// デストラクタ //

GameMgr::~GameMgr()
{

}

// 処理 //

void GameMgr::Procces()
{
	
}