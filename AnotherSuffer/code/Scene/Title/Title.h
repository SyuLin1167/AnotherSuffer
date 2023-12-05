#pragma once

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

    const int rows = 5;
    const int cols = 5;

    struct Cell {
        bool visited, top, bottom, left, right;
        Cell() : visited(false), top(true), bottom(true), left(true), right(true) {}
    };
    std::vector<std::vector<Cell>> maze;

    void generateMaze(std::vector<std::vector<Cell>>& maze, int startRow, int startCol, int goalRow, int goalCol);
    void drawMaze(const std::vector<std::vector<Cell>>& maze);
};

