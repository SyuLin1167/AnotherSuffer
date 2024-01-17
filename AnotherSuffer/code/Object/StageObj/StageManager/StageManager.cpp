#include<DxLib.h>
#include<memory>
#include<vector>
#include<unordered_map>
#include<time.h>
#include<stack>

#include "StageManager.h"
#include"../../ObjManager/ObjManager.h"
#include"../Aisle/Aisle.h"
#include"../Wall/Wall.h"
#include"../Barricade/Barricade.h"

std::unique_ptr<StageManager> StageManager::singleton;

static constexpr float BLOCK_SIZE = 40.0f;                             //�u���b�N�T�C�Y
static constexpr int STAGE_SIZE = 17;                                  //�X�e�[�W�T�C�Y
static constexpr int MOVE_CELL = 1;                                    //�Z���̈ړ���
static constexpr int TWO_CELL = 2;

static constexpr int UP = 0x0001;                                      //��
static constexpr int DOWN = 0x0002;                                    //��
static constexpr int LEFT = 0x0004;                                    //��
static constexpr int RIGHT = 0x0008;                                   //�E

StageManager::StageManager()
    :dirArray{ UP, DOWN, LEFT, RIGHT }
{
    //�����Ȃ�
}

void StageManager::InitStageManager()
{
        singleton.reset(new StageManager);

        //�X�e�[�W�쐬&����
        std::srand(unsigned int(time(NULL)));
        singleton->InitStageData();
        singleton->CreateStage();
        singleton->SetBarricade();

        SetUseASyncLoadFlag(true);
        singleton->PlacementObject();
        SetUseASyncLoadFlag(false);
}

StageManager::~StageManager()
{
    dirArray.clear();
    stageData.clear();
}

void StageManager::InitStageData()
{
    //�X�e�[�W�̃T�C�Y���ǃu���b�N�Ƃ��ăf�[�^�ǉ�
    for (int i = 0; i < STAGE_SIZE; i++)
    {
        for (int j = 0; j < STAGE_SIZE; j++)
        {
            BlockParam blockParam = {};
            blockParam.type = WALL;
            blockParam.pos = VGet(j * BLOCK_SIZE - BLOCK_SIZE, 0, i * BLOCK_SIZE - BLOCK_SIZE);
            singleton->stageData[i].emplace(j, blockParam);
        }
    }
}

StageManager::BlockParam::BlockParam()
    :type()
    , pos()
{
    //�����Ȃ�
}

void StageManager::CreateStage(int indexX, int indexY)
{
    //���݂̃}�X��ʘH�ɂ���
    stageData[indexY][indexX].type = AISLE;

    //�i�s������ʘH��
    ShuffleDirection();
    for (auto& direction: dirArray)
    {
        int nextX = indexX + CalcNextCell(direction, LEFT , RIGHT);
        int nextY = indexY + CalcNextCell(direction, UP, DOWN);

        //2�}�X�ړ��オ�O�ǂ𒴂��Ȃ�������ʘH�����
        int secondNextX = indexX + CalcNextCell(direction, LEFT, RIGHT) * TWO_CELL;
        int secondNextY = indexY + CalcNextCell(direction, UP, DOWN) * TWO_CELL;
        if (IsOnStage(secondNextX) && IsOnStage(secondNextY) &&
            (stageData[secondNextY][secondNextX].type & WALL))
        {
            stageData[nextY][nextX].type = AISLE;
            CreateStage(secondNextX, secondNextY);
        }
    }
}

void StageManager::ShuffleDirection()
{
    //�����_���ɔz������V���b�t��
    for (auto& direction: dirArray)
    {
        int randIndex = rand() % dirArray.size();
        std::swap(direction, dirArray[randIndex]);
    }
}

int StageManager::CalcNextCell(int dir, int subDir, int addDir)
{
    //�i�s�����ɂ���ăZ���̈ړ��ʂ�Ԃ�
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
    //�Y�����ԍ����X�e�[�W�͈̔͂��z���Ă��Ȃ���
    if (index > 0 && index < STAGE_SIZE)
    {
        return true;
    }
    return false;
}

void StageManager::SetBarricade()
{
    //�ǂ�T��
    for (int i = 1; i < STAGE_SIZE - 1; ++i) 
    {
        for (int j = 1; j < STAGE_SIZE - 1; ++j)
        {
            if (stageData[i][j].type & WALL)
            {
                //�ǂɋ��܂�Ă�����5����1�̊m���ŏ�ǂɂ���
                int trapProb = rand() % 5;
                if (trapProb & 1)
                {
                    if (((stageData[i][j + 1].type & stageData[i][j - 1].type) & WALL) ||
                        ((stageData[i + 1][j].type & stageData[i - 1][j].type) & WALL))
                    {
                        stageData[i][j].type = BARRICADE;
                    }
                }
            }
        }
    }
}

void StageManager::PlacementObject()
{
    //�f�[�^���̏�񂩂�X�e�[�W�I�u�W�F�N�g�ݒu
    for (auto& indexY : stageData)
    {
        for (auto& indexX : indexY.second)
        {
            if (indexX.second.type & AISLE)
            {
                ObjManager::AddObj(new Aisle(indexX.second.pos));
            }
            else if (indexX.second.type & WALL)
            {
                ObjManager::AddObj(new Wall(indexX.second.pos));
            }
            else if (indexX.second.type & BARRICADE)
            {
                ObjManager::AddObj(new Barricade(indexX.second.pos, { indexX.first,indexY.first }));
            }
        }
    }
}

void StageManager::ChangeStageData(std::pair<int, int> cell,int type)
{
    singleton->stageData[cell.second][cell.first].type = type;
}



