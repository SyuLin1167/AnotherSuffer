#pragma once

/*Play�N���X*/
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

    /// <summary>
    /// �V�[���X�V����
    /// </summary>
    /// <param name="deltaTime">:�t���[�����[�g</param>
    /// <returns>���t���[���̃V�[��</returns>
    SceneBase* UpdateScene(const float deltaTime)override;

    /// <summary>
    /// �V�[���`��
    /// </summary>
    void DrawScene()override;
};

