#pragma once


/*Title�N���X*/
class Title: public SceneBase
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
    SceneBase* SceneUpdate(const float& deltaTime)override;

    /// <summary>
    /// �V�[���`�揈��
    /// </summary>
    void SceneDraw()override;
};

