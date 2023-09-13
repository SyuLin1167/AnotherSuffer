#include<DxLib.h>

#include"../SceneBase/SceneBase.h"
#include"../Play/Play.h"
#include"../../Object/ObjMgr/ObjMgr.h"
#include"../../Object/CharaObj/Player/Player.h"
#include "Title.h"

// コンストラクタ //

Title::Title()
    :SceneBase()
{
    ObjMgr::AddObj(new Player);
}

// デストラクタ //

Title::~Title()
{
}

// シーン更新処理 //

SceneBase* Title::UpdateScene(const float& deltaTime)
{
    ObjMgr::UpdateObj(deltaTime);

    if (CheckHitKey(KEY_INPUT_RETURN))
    {
        ObjMgr::Finalize();
        return new Play;
    }

    return this;
}

void Title::DrawScene()
{
    ObjMgr::DrawObj();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
}
