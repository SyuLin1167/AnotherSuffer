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

    int box[5][5] = {
        {0,1,1,1,0},
        {1,0,1,0,1},
        {0,0,1,0,0},
        {0,1,0,1,0},
        {1,1,1,1,1},
    };
};

