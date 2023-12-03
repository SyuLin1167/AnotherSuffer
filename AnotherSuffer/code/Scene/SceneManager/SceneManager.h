#pragma once
#include<memory>
#include<stack>

/// <summary>
/// �V�[���Ǘ�
/// </summary>
class SceneManager final
{
public:
    /// <summary>
    /// �V�[���Ǘ�����������
    /// </summary>
    static void InitSceneManager();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~SceneManager();

    /// <summary>
    /// �Q�[�����[�v
    /// </summary>
    static void GameLoop();

private:
    /// <summary>
    /// �R���X�g���N�^(�V���O���g��)
    /// </summary>
    SceneManager();

    /// �V�[���X�V����
    /// </summary>
    static void UpdateScene();

    /// <summary>
    /// �V�[���`�揈��
    /// </summary>
    static void DrawScene();

    /// <summary>
    /// �V�[���؂�ւ�����
    /// </summary>
    static void ChangeScene();


    static std::unique_ptr<SceneManager> singleton;           //���g�̎���

    std::stack<std::unique_ptr<class SceneBase>> nowScene;      //���݂̃V�[��
    class SceneBase* holdScene;                       //�ێ��V�[��
};

