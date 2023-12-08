#include<DxLib.h>

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

    std::srand(time(NULL));
    InitializeMaze();
    GenerateMaze(1, 1);

    for (int i = 1; i < MAZE_HEIGHT - 1; ++i) {
        for (int j = 1; j < MAZE_WIDTH - 1; ++j) {
            if (maze[i][j] == 1) {
                int randomIndex = rand() % 4;
                if (randomIndex == 1)
                {
                    if ((maze[i][j + 1] == 1 && maze[i][j - 1] == 1) ||
                        (maze[i + 1][j] == 1 && maze[i - 1][j] == 1))
                    {
                        if ((maze[i][j + 1] != 2 && maze[i][j - 1] != 2) &&
                            (maze[i + 1][j] != 2 && maze[i - 1][j] != 2))
                        {
                            maze[i][j] = 2;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < MAZE_HEIGHT; ++i) {
        for (int j = 0; j < MAZE_WIDTH; ++j) {
            if (maze[i][j] == 1) 
            {
                ObjManager::AddObj(new Stage(VGet(i * 40.0f-40.0f, 0, j * 40.0f-40.0f)));
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
    for (int i = -20; i < 20; i++)
    {
        DrawLine3D(VGet(-200, 0, i * 10), VGet(200, 0, i * 10), GetColor(255, 255, 255));
        DrawLine3D(VGet(i*10, 0, -200), VGet(i*10, 0, 200), GetColor(255, 255, 255));
    }
    DrawFormatString(0, 0, GetColor(255, 255, 255), "play");
}

void Play::InitializeMaze()
{
    for (int i = 0; i < MAZE_HEIGHT; ++i) {
        for (int j = 0; j < MAZE_WIDTH; ++j) {
            maze[i][j] = 1; // ���ׂẴZ����ǂŏ�����
        }
    }
}

void Play::GenerateMaze(int x, int y)
{
    maze[y][x] = 0; // ���݂̃Z����ʘH�ɂ���

    // �����_���Ɏ��̕�����I��
    int directions[4] = { 0, 1, 2, 3 };
    for (int i = 0; i < 4; ++i) {
        int randomIndex = rand() % 4;
        std::swap(directions[i], directions[randomIndex]);
    }

    // �I�����������ɐi�݁A�ׂ̃Z����ʘH�ɂ���
    for (int i = 0; i < 4; ++i) {
        int dx = 0, dy = 0;
        if (directions[i] == 0) dy = -1; // ��
        else if (directions[i] == 1) dx = 1; // �E
        else if (directions[i] == 2) dy = 1; // ��
        else if (directions[i] == 3) dx = -1; // ��

        int nx = x + dx * 2;
        int ny = y + dy * 2;

        if (nx > 0 && nx < MAZE_WIDTH && ny > 0 && ny < MAZE_HEIGHT && maze[ny][nx] == 1) {
            maze[y + dy][x + dx] = 0;
            GenerateMaze(nx, ny);
        }
    }
}

void Play::DrawMaze()
{
    for (int i = 0; i < MAZE_HEIGHT; ++i) {
        for (int j = 0; j < MAZE_WIDTH; ++j) {
            if (maze[i][j] == 1) {
                DrawBox(j * CELL_SIZE, i * CELL_SIZE, (j + 1) * CELL_SIZE, (i + 1) * CELL_SIZE, GetColor(255, 255, 0), TRUE);
            }
            if (maze[i][j] == 2)
            {
                DrawBox(j * CELL_SIZE, i * CELL_SIZE, (j + 1) * CELL_SIZE, (i + 1) * CELL_SIZE, GetColor(255, 0, 255), TRUE);
            }
        }
    }
}