#pragma once

/// <summary>
/// �v���C�V�[��
/// </summary>
class Play:public SceneBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Play();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Play();

private:
    /// <summary>
    /// �V�[���X�V����
    /// </summary>
    /// <param name="deltaTime">:�f���^�^�C��</param>
    /// <returns>���t���[���̃V�[��</returns>
    SceneBase* UpdateScene(const float deltaTime) override;

    /// <summary>
    /// �V�[���`�揈��
    /// </summary>
    void DrawScene() override;

    const int CELL_SIZE = 20; // �Z���̃T�C�Y
    const int MAZE_WIDTH = 16;
    const int MAZE_HEIGHT = 16;

    int maze[16][16];

    void InitializeMaze();

    void GenerateMaze(int x, int y);

    void DrawMaze();
};

