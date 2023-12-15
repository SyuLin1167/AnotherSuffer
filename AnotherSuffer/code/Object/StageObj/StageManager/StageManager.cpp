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
        if (nx > 0 && nx < STAGE_SIZE && ny > 0 && ny < STAGE_SIZE && (stageData[ny][nx] & WALL)) {
            stageData[indexY + dy][x + dx] = AISLE;
            GenerateMaze(nx, ny);
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




