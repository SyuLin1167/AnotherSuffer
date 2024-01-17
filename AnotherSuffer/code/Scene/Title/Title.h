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

    std::vector<std::vector<int>> stage
    {
        {1,1,1,1,1},
        {1,0,0,1,1},
        {1,0,1,1,1},
        {1,0,0,1,1},
        {1,1,1,1,1},
    };
};

