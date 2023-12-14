#include<DxLib.h>

#include<random>

#include"../../KeyStatus/KeyStatus.h"
#include"../../Object/ObjManager/ObjManager.h"
#include"../../Object/Camera/FirstPersonView/FirstPersonView.h"
#include"../../Object/CharaObj/Player/Player.h"
#include"../../Object/StageObj/Stage/Stage.h"
#include"../SceneBase/SceneBase.h"
#include"../Title/Title.h"
#include "Play.h"

Play::Play()
{
    ObjManager::AddObj(new FirstPersonView);
    ObjManager::AddObj(new Player);

    std::srand(unsigned int(time(NULL)));
    InitializeMaze();
    GenerateMaze(1, 1);

    for (int i = 1; i < STAGE_SIZE - 1; ++i) {
        for (int j = 1; j < STAGE_SIZE - 1; ++j) {
            if (stageData[i][j] == WALL) {
                int trapProb = rand() % 4;
                if (trapProb == 1)
                {
                    if ((stageData[i][j + 1] & stageData[i][j - 1] & WALL) ||
                        (stageData[i + 1][j] & stageData[i - 1][j] & WALL))
                    {
                        if ((stageData[i][j + 1] != BARRICADE && stageData[i][j - 1] != BARRICADE) &&
                            (stageData[i + 1][j] != BARRICADE && stageData[i - 1][j] != BARRICADE))
                        {
                            stageData[i][j] = BARRICADE;
                        }
                    }
                }
            }
        }
    }

    for (auto& i : stageData)
    {
        for (int j = 0; j < i.second.size(); ++j) {
            if (i.second[j] == WALL)
            {
                ObjManager::AddObj(new Stage(VGet(i.first * 40.0f - 40.0f, 0, j * 40.0f - 40.0f)));
            }
        }
    }
}

Play::~Play()
{
    //�����Ȃ�
}

SceneBase* Play::UpdateScene(const float deltaTime)
{
    //�I�u�W�F�N�g�X�V
    ObjManager::UpdateObj(deltaTime);
    ObjManager::OnColllsionObj();

    //�V�[���؂�ւ�
    if (KeyStatus::KeyStateDecision(KEY_INPUT_RETURN, ONINPUT))
    {
        ObjManager::DeleteAllObj();
        return new Title;
    }

    return this;
}

void Play::DrawScene()
{
    //�I�u�W�F�N�g�`��
    ObjManager::DrawObj();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "play");
    DrawMaze();
}

void Play::InitializeMaze()
{
    for (int i = 0; i < STAGE_SIZE; ++i) {
        for (int j = 0; j < STAGE_SIZE; ++j) {
            stageData[i].emplace_back(WALL);
        }
    }
}

void Play::GenerateMaze(int x, int y)
{
    stageData[y][x] = AISLE; // ���݂̃Z����ʘH�ɂ���

    // �����_���Ɏ��̕�����I��
    for (auto& i : directions)
    {
        int randIndex = rand() % directions.size();
        std::swap(i, directions[randIndex]);
    }

    // �I�����������ɐi�݁A�ׂ̃Z����ʘH�ɂ���
    for (auto& i:directions)
    {
        int dx = 0, dy = 0;
        if (i & UP) dy = -1; // ��
        else if (i & DOWN) dy = 1; // ��
        else if (i & LEFT) dx = -1; // ��
        else if (i & RIGHT) dx = 1; // �E

        int nx = x + dx * 2;
        int ny = y + dy * 2;

        if (nx > 0 && nx < STAGE_SIZE && ny > 0 && ny < STAGE_SIZE && (stageData[ny][nx] & WALL)) {
            stageData[y + dy][x + dx] = AISLE;
            GenerateMaze(nx, ny);
        }
    }
}

void Play::DrawMaze()
{
    for (int i = 0; i < STAGE_SIZE; ++i) {
        for (int j = 0; j < STAGE_SIZE; ++j) {
            if (stageData[i][j] == WALL) {
                DrawBox(j * CELL_SIZE, i * CELL_SIZE, (j + 1) * CELL_SIZE, (i + 1) * CELL_SIZE, GetColor(255, 255, 0), TRUE);
            }
            if (stageData[i][j] == BARRICADE)
            {
                DrawBox(j * CELL_SIZE, i * CELL_SIZE, (j + 1) * CELL_SIZE, (i + 1) * CELL_SIZE, GetColor(255, 0, 255), TRUE);
            }
        }
    }
}