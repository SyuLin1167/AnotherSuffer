#include "GameMgr.h"
#include<DxLib.h>
#include<memory>

#include"../GameSetting/GameSetting.h"

// コンストラクタ //

GameMgr::GameMgr()
    :gmSet(new GameSetting)
{
}

// デストラクタ //

GameMgr::~GameMgr()
{
    delete gmSet;
}

// 処理 //

void GameMgr::Procces()
{
    
}