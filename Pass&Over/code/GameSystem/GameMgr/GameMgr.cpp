#include"../GameSetting/GameSetting.h"
#include"../../Scene/SceneMgr/SceneMgr.h"
#include "GameMgr.h"

// コンストラクタ //

GameMgr::GameMgr()
{
    gmSet.reset(new GameSetting);
    sceneMgr.reset(new SceneMgr);
}

// デストラクタ //

GameMgr::~GameMgr()
{
}

// 処理 //

void GameMgr::Procces()
{
    sceneMgr->GameLoop();
}