#include<DxLib.h>

#include"../SceneBase/SceneBase.h"
#include"../Play/Play.h"
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

SceneBase* Title::UpdateScene(const float& deltaTime)
{
    if (CheckHitKey(KEY_INPUT_RETURN))
    {
        return new Play;
    }

    return this;
}

void Title::DrawScene()
{
    DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
}
