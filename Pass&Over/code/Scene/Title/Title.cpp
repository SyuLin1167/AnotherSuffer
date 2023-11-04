#include<DxLib.h>

#include"../../KeyStatus/KeyStatus.h"
#include"../SceneBase/SceneBase.h"
#include"../Play/Play.h"
#include"../../Object/ObjManager/ObjManager.h"
#include "Title.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Title::Title()
    :SceneBase()
{
    //�����Ȃ�
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Title::~Title()
{
    //�����Ȃ�
}

/// <summary>
/// �V�[���X�V����
/// </summary>
/// <param name="deltaTime">:�t���[�����[�g</param>
/// <returns>���t���[���̃V�[��</returns>
SceneBase* Title::UpdateScene(const float deltaTime)
{
    //�I�u�W�F�N�g�X�V
    ObjManager::UpdateObj(deltaTime);

    //�V�[���؂�ւ�
    if (KeyStatus::KeyStateDecision(KEY_INPUT_RETURN, ONINPUT))
    {
        ObjManager::DeleteAllObj();
        return new Play;
    }

    return this;
}

/// <summary>
/// �V�[���`�揈��
/// </summary>
void Title::DrawScene()
{
    //�I�u�W�F�N�g�`��
    ObjManager::DrawObj();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
}
