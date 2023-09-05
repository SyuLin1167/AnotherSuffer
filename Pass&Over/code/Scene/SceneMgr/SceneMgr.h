#pragma once
#include<memory>
#include<stack>

/*SceneMgr�N���X*/
class SceneMgr final
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    SceneMgr();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~SceneMgr();

    /// <summary>
    /// �Q�[�����[�v
    /// </summary>
    void GameLoop();

    /// <summary>
    /// �V�[���X�V����
    /// </summary>
    void SceneUpdate();

    /// <summary>
    /// �V�[���`�揈��
    /// </summary>
    void SceneDraw();

private:
    std::stack<std::shared_ptr<class SceneBase>> nowScene;      //���݂̃V�[��
    class SceneBase* tmpScene;                                  //�ꎞ�I�ȃV�[��
};

