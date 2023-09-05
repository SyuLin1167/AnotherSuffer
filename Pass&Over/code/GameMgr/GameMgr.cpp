#include<DxLib.h>
#include<memory>

#include"../GameSetting/GameSetting.h"
#include"../Scene/SceneMgr/SceneMgr.h"
#include "GameMgr.h"

// コンストラクタ //

GameMgr::GameMgr()
{
}

// デストラクタ //

GameMgr::~GameMgr()
{
}

// 処理 //

void GameMgr::Procces()
{
    std::shared_ptr<GameSetting> gmSet(new GameSetting);
    std::shared_ptr<SceneMgr> sceneMgr(new SceneMgr);
    sceneMgr->GameLoop();
}