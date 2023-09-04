#include<DxLib.h>
#include<memory>

#include "GameMgr.h"
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