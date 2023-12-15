#include<DxLib.h>
#include<time.h>
#include<stack>

#include "StageManager.h"

StageManager::StageManager()
{
    std::srand(unsigned int(time(NULL)));
    InitStageData();
    CreateStage();
    SetBarricade();
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
        int secondNextX = indexX + CalcNextCell(LEFT | RIGHT) * TWO_CELL;
        int secondNextY = indexX + CalcNextCell(LEFT | RIGHT) * TWO_CELL;
        if (IsOnStage(secondNextX) && IsOnStage(secondNextY) &&
            (stageData[secondNextY][secondNextX] & WALL)) {
            stageData[nextY][nextX] = AISLE;
            CreateStage(secondNextY, secondNextX);
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

void StageManager::SetBarricade()
{
    //壁を探す
    for (int i = 1; i < STAGE_SIZE - 1; ++i) 
    {
        for (int j = 1; j < STAGE_SIZE - 1; ++j)
        {
            if (stageData[i][j] & WALL) 
            {
                //壁に挟まれていたら4分の1の確立で障壁にする
                int trapProb = rand() % 4;
                if (trapProb & 1)
                {
                    if ((stageData[i][j + 1] & stageData[i][j - 1] & WALL) ||
                        (stageData[i + 1][j] & stageData[i - 1][j] & WALL))
                    {
                        stageData[i][j] = BARRICADE;
                    }
                }
            }
        }
    }
}

void StageManager::PlacementObject()
{
    for (auto& indexY : stageData)
    {
        for (auto& indexX : indexY.second)
        {

        }
    }
}




