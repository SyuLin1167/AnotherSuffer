#include<DxLib.h>

#include"../SceneBase/SceneBase.h"
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

SceneBase* Title::SceneUpdate(const float& deltaTime)
{
    return this;
}

void Title::SceneDraw()
{
    DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
}
