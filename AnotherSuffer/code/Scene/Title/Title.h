#pragma once
#include <DxLib.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <random>
#include <ctime>


/// <summary>
/// �^�C�g���V�[��
/// </summary>
class Title final: public SceneBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Title();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Title();

    /// <summary>
    /// �V�[���X�V����
    /// </summary>
    /// <param name="deltaTime">:�t���[�����[�g</param>
    /// <returns>���t���[���̃V�[��</returns>
    SceneBase* UpdateScene(const float deltaTime) override;

    /// <summary>
    /// �V�[���`�揈��
    /// </summary>
    void DrawScene() override;

    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    const int CELL_SIZE = 40; // �Z���̃T�C�Y
    const int MAZE_WIDTH = 30;
    const int MAZE_HEIGHT = 30;

    int maze[640 / 20][480 / 20];

    void InitializeMaze();

    void GenerateMaze(int x, int y);

    void DrawMaze();
};

