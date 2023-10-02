#include<DxLib.h>

#include"../SceneBase/SceneBase.h"
#include"../Play/Play.h"
#include"../../Object/ObjMgr/ObjMgr.h"
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
    ObjMgr::UpdateObj(deltaTime);

    if (CheckHitKey(KEY_INPUT_RETURN))
    {
        ObjMgr::DeleteAllObj();
        return new Play;
    }

    return this;
}

void Title::DrawScene()
{
    ObjMgr::DrawObj();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
}
