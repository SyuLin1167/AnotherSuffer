#include<DxLib.h>

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
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Title::~Title()
{
}

/// <summary>
/// �V�[���X�V����
/// </summary>
/// <param name="deltaTime">:�t���[�����[�g</param>
/// <returns>���t���[���̃V�[��</returns>
SceneBase* Title::UpdateScene(const float deltaTime)
{
    ObjManager::UpdateObj(deltaTime);

    if (CheckHitKey(KEY_INPUT_RETURN))
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
    ObjManager::DrawObj();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
}
