#include<DxLib.h>
#include<time.h>
#include<stack>

#include "StageManager.h"

StageManager::StageManager()
{
    std::srand(unsigned int(time(NULL)));
    InitStageData();
    CreateStage();
    //SetBarricade();
}

StageManager::~StageManager()
{
    dirArray.clear();
    stageData.clear();
}

void StageManager::InitStageData()
{
    //ステージのサイズ分壁ブロックとしてデータ追加
    for (int i = 0; i < STAGE_SIZE; i++)
    {
        for (int j = 0; j < STAGE_SIZE; j++)
        {
            stageData[i][j] = WALL;
        }
    }
}

void StageManager::CreateStage(int indexX, int indexY)
{
    //現在のマスを通路にする
    stageData[indexY][indexX] = AISLE;

    //進行方向を通路に
    for (auto& direction: dirArray)
    {
        int nextX = indexX + CalcNextCell(LEFT | RIGHT);
        int nextY = indexY + CalcNextCell(UP | DOWN);

        //2マス移動後が外壁を超えなかったら通路を作る
        if (nx > 0 && nx < STAGE_SIZE && ny > 0 && ny < STAGE_SIZE && (stageData[ny][nx] & WALL)) {
            stageData[indexY + dy][x + dx] = AISLE;
            GenerateMaze(nx, ny);
        }
    }
}

void StageManager::ShuffleDirection()
{
    //ランダムに配列内をシャッフル
    for (auto& direction: dirArray)
    {
        int randIndex = rand() % dirArray.size();
        std::swap(direction, dirArray[randIndex]);
    }
}

int StageManager::CalcNextCell(int dir)
{
    //進行方向によってセルの移動量を返す
    if (dir & (UP | LEFT))
    {
        return -MOVE_CELL;
    }
    else if (dir & (DOWN | RIGHT))
    {
        return MOVE_CELL;
    }
    DebugBreak();
}

bool StageManager::IsOnStage(int index)
{
    //
    if (index > 0 && index < STAGE_SIZE)
    {
        return true;
    }
    return false;
}




