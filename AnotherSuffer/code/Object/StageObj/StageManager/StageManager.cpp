#include<DxLib.h>
#include<time.h>
#include<stack>

#include "StageManager.h"

StageManager::StageManager()
{

    InitStageData();
    CreateStage();
    ChangeToBarricade();
}

StageManager::~StageManager()
{
    dirArray.clear();
    stageData.clear();
}

void StageManager::InitStageData()
{
    //ステージのサイズ分壁ブロックでデータ追加
    for (int i = 0; i < STAGE_SIZE; i++)
    {
        for (int j = 0; j < STAGE_SIZE; j++)
        {
            stageData[i][j] = WALL;
        }
    }
}



