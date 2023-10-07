#include<DxLib.h>

#include"../SceneBase/SceneBase.h"
#include"../Play/Play.h"
#include"../../Object/ObjManager/ObjManager.h"
#include "Title.h"

// �R���X�g���N�^ //

Title::Title()
    :SceneBase()
{
}

// �f�X�g���N�^ //

Title::~Title()
{
}

// �V�[���X�V���� //

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

// �V�[���`�揈�� //

void Title::DrawScene()
{
    ObjManager::DrawObj();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
}
