#pragma once

#include<unordered_map>
#include<vector>

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
    /// �V�[���X�V
    /// </summary>
    /// <param name="deltaTime">:�f���^�^�C��</param>
    /// <returns>���t���[���̃V�[��</returns>
    SceneBase* UpdateScene(const float deltaTime) override;

    /// <summary>
    /// �V�[���`��
    /// </summary>
    void DrawScene() override;

    const int CELL_SIZE = 20; // �Z���̃T�C�Y
    const int STAGE_SIZE = 17;

    const int UP = 0x0001;     //��
    const int DOWN = 0x0002;  //��
    const int LEFT = 0x0004;     //��
    const int RIGHT = 0x0008;  //�E
    std::vector<int> directions = { UP, DOWN, LEFT, RIGHT };

    const int WALL = 0x0001;    //��
    const int AISLE = 0x0002;   //�ʘH
    const int BARRICADE = 0x0004;    //���
    std::unordered_map<int, std::vector<int>> stageData;


    void InitializeMaze();

    void GenerateMaze(int x, int y);

    void DrawMaze();
};

