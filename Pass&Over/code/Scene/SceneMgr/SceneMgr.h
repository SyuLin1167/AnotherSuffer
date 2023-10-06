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
    void UpdateScene();

    /// <summary>
    /// �V�[���`�揈��
    /// </summary>
    void DrawScene();

    /// <summary>
    /// �V�[���؂�ւ�����
    /// </summary>
    void ChangeScene();

private:
    std::shared_ptr<class TimeManager> timeManager;                 //�^�C���}�l�[�W���[

    std::stack<std::shared_ptr<class SceneBase>> nowScene;      //���݂̃V�[��
    class SceneBase* tmpScene;                                  //�ꎞ�I�ȃV�[��
};

