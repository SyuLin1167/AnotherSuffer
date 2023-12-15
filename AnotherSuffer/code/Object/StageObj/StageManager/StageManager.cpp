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
    //�X�e�[�W�̃T�C�Y���ǃu���b�N�Ƃ��ăf�[�^�ǉ�
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
    //���݂̃}�X��ʘH�ɂ���
    stageData[indexY][indexX] = AISLE;

    //�i�s������ʘH��
    for (auto& direction: dirArray)
    {
        int nextX = indexX + CalcNextCell(LEFT | RIGHT);
        int nextY = indexY + CalcNextCell(UP | DOWN);

        //2�}�X�ړ��オ�O�ǂ𒴂��Ȃ�������ʘH�����
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
    //�����_���ɔz������V���b�t��
    for (auto& direction: dirArray)
    {
        int randIndex = rand() % dirArray.size();
        std::swap(direction, dirArray[randIndex]);
    }
}

int StageManager::CalcNextCell(int dir)
{
    //�i�s�����ɂ���ăZ���̈ړ��ʂ�Ԃ�
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
    //�ǂ�T��
    for (int i = 1; i < STAGE_SIZE - 1; ++i) 
    {
        for (int j = 1; j < STAGE_SIZE - 1; ++j)
        {
            if (stageData[i][j] & WALL) 
            {
                //�ǂɋ��܂�Ă�����4����1�̊m���ŏ�ǂɂ���
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




