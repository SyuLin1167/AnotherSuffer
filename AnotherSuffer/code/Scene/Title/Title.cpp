#include<DxLib.h>
#include<stack>

#include"../../KeyStatus/KeyStatus.h"
#include"../SceneBase/SceneBase.h"
#include"../Play/Play.h"
#include"../../Object/ObjManager/ObjManager.h"
#include "Title.h"

Title::Title()
    :SceneBase()
{
    //�����Ȃ�
    std::srand(time(NULL));
    InitializeMaze();
    GenerateMaze(1, 1);
}

Title::~Title()
{
    //�����Ȃ�
}

SceneBase* Title::UpdateScene(const float deltaTime)
{
    //�I�u�W�F�N�g�X�V
    ObjManager::UpdateObj(deltaTime);

    //�V�[���؂�ւ�
    if (KeyStatus::KeyStateDecision(KEY_INPUT_RETURN, ONINPUT))
    {
        ObjManager::DeleteAllObj();
        return new Play;
    }

    return this;
}

void Title::DrawScene()
{
    //�I�u�W�F�N�g�`��
    ObjManager::DrawObj();
    DrawMaze();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
}

void Title::InitializeMaze()
{
    for (int i = 0; i < MAZE_HEIGHT; ++i) {
        for (int j = 0; j < MAZE_WIDTH; ++j) {
            maze[i][j] = 1; // ���ׂẴZ����ǂŏ�����
        }
    }
}

void Title::GenerateMaze(int x, int y)
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

void Title::DrawMaze()
{
    for (int i = 0; i < MAZE_HEIGHT; ++i) {
        for (int j = 0; j < MAZE_WIDTH; ++j) {
            if (maze[i][j] == 1) {
                DrawBox(j * CELL_SIZE, i * CELL_SIZE, (j + 1) * CELL_SIZE, (i + 1) * CELL_SIZE, GetColor(255, 255, 0), TRUE);
            }
        }
    }
}
