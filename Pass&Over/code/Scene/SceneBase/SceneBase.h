#pragma once

/*SceneBase�N���X*/
class SceneBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    SceneBase();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~SceneBase();

    /// <summary>
    /// �V�[���X�V����
    /// </summary>
    virtual void SceneUpdate() = 0;

    /// <summary>
    /// �V�[���`�揈��
    /// </summary>
    virtual void SceneDraw() = 0;


};

