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
    /// �V�[���X�V
    /// </summary>
    /// <param name="deltaTime">:�t���[�����[�g</param>
    /// <returns>���t���[���̃V�[��</returns>
    SceneBase* UpdateScene(const float deltaTime) override;

    /// <summary>
    /// �V�[���`��
    /// </summary>
    void DrawScene() override;

    //class Astar* a;
    std::vector<std::pair<int, int>> path;
};

