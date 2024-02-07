#pragma once

/// <summary>
/// �N���A���
/// </summary>
class Clear:public SceneBase
{
public :
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Clear();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Clear();

private:
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

    const std::vector<std::vector<int>> stage
    {
        {1,1,1,1,1,1,1},
        {1,0,0,0,0,0,1},
        {1,0,0,0,0,0,1},
        {1,0,0,0,0,0,1},
        {1,0,0,0,0,0,1},
        {1,0,0,0,0,0,1},
        {1,1,1,1,1,1,1},
    };

    int backGraph;
};

