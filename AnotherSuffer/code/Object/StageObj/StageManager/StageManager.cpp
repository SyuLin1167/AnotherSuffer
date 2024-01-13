#include<DxLib.h>
#include<vector>
#include<unordered_map>
#include<time.h>
#include<stack>

#include "StageManager.h"
#include"../../ObjManager/ObjManager.h"
#include"../Aisle/Aisle.h"
#include"../Wall/Wall.h"
#include"../Barricade/Barricade.h"

static constexpr float BLOCK_SIZE = 40.0f;                             //ブロックサイズ
static constexpr int STAGE_SIZE = 17;                                  //ステージサイズ
static constexpr int MOVE_CELL = 1;                                    //セルの移動量
static constexpr int TWO_CELL = 2;

static constexpr int UP = 0x0001;                                      //上
static constexpr int DOWN = 0x0002;                                    //下
static constexpr int LEFT = 0x0004;                                    //左
static constexpr int RIGHT = 0x0008;                                   //右

static constexpr int WALL = 0x0001;                                    //壁
static constexpr int AISLE = 0x0002;                                   //通路
static constexpr int BARRICADE = 0x0004;                               //障壁

StageManager::StageManager()
    :dirArray{ UP, DOWN, LEFT, RIGHT }
{
    //ステージ作成&生成
    std::srand(unsigned int(time(NULL)));
    InitStageData();
    CreateStage();
    SetBarricade();

    SetUseASyncLoadFlag(true);
    PlacementObject();
    SetUseASyncLoadFlag(false);
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
    ShuffleDirection();
    for (auto& direction: dirArray)
    {
        int nextX = indexX + CalcNextCell(direction, LEFT , RIGHT);
        int nextY = indexY + CalcNextCell(direction, UP, DOWN);

        //2マス移動後が外壁を超えなかったら通路を作る
        int secondNextX = indexX + CalcNextCell(direction, LEFT, RIGHT) * TWO_CELL;
        int secondNextY = indexY + CalcNextCell(direction, UP, DOWN) * TWO_CELL;
        if (IsOnStage(secondNextX) && IsOnStage(secondNextY) &&
            (stageData[secondNextY][secondNextX] & WALL))
        {
            stageData[nextY][nextX] = AISLE;
            CreateStage(secondNextX, secondNextY);
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

int StageManager::CalcNextCell(int dir, int subDir, int addDir)
{
    //進行方向によってセルの移動量を返す
    if (dir & subDir)
    {
        return -MOVE_CELL;
    }
    else if (dir & addDir)
    {
        return MOVE_CELL;
    }
    return 0;
}

bool StageManager::IsOnStage(int index)
{
    //添え字番号がステージの範囲を越えていないか
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
                //壁に挟まれていたら5分の1の確立で障壁にする
                int trapProb = rand() % 5;
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
    //データ内の情報からステージオブジェクト設置
    for (auto& indexY : stageData)
    {
        for (auto& indexX : indexY.second)
        {
            if (indexX.second & AISLE)
            {
                ObjManager::AddObj(new Aisle(
                    VGet(indexY.first * BLOCK_SIZE - BLOCK_SIZE, 0, indexX.first * BLOCK_SIZE - BLOCK_SIZE)));
            }
            else if (indexX.second & WALL)
            {
                ObjManager::AddObj(new Wall(
                    VGet(indexY.first * BLOCK_SIZE - BLOCK_SIZE, 0, indexX.first * BLOCK_SIZE - BLOCK_SIZE)));
            }
            else if (indexX.second & BARRICADE)
            {
                ObjManager::AddObj(new Barricade(
                    VGet(indexY.first * BLOCK_SIZE - BLOCK_SIZE, 0, indexX.first * BLOCK_SIZE - BLOCK_SIZE)));
            }
        }
    }
}

void StageManager::DebugDraw()
{
    for (auto& indexY : stageData)
    {
        for (auto& indexX : indexY.second)
        {
            if (indexX.second & WALL) {
                DrawBox(indexX.first * 20, indexY.first * 20,
                    (indexX.first + 1) * 20, (indexY.first + 1) * 20, GetColor(150, 100, 10), TRUE);
            }
            if (indexX.second & BARRICADE)
            {
                DrawBox(indexX.first * 20, indexY.first * 20,
                    (indexX.first + 1) * 20, (indexY.first + 1) * 20, GetColor(100, 10, 120), TRUE);
            }
            if (indexX.second & AISLE)
            {
                DrawBox(indexX.first * 20, indexY.first * 20,
                    (indexX.first + 1) * 20, (indexY.first + 1) * 20, GetColor(50, 150, 150), TRUE);
            }
        }
    }
}




