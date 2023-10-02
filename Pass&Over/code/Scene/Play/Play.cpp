#include<DxLib.h>

#include"../../Object/ObjMgr/ObjMgr.h"
#include"../../Object/Camera/Camera.h"
#include"../../Object/CharaObj/Player/Player.h"
#include"../SceneBase/SceneBase.h"
#include "Play.h"

// �R���X�g���N�^ //

Play::Play()
{
    ObjMgr::AddObj(new Camera);
    ObjMgr::AddObj(new Player);
}

// �f�X�g���N�^ //

Play::~Play()
{

}

// �V�[���X�V���� //

SceneBase* Play::UpdateScene(const float deltaTime)
{
    ObjMgr::UpdateObj(deltaTime);
    return this;
}

// �V�[���`�揈�� //

void Play::DrawScene()
{
    ObjMgr::DrawObj();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "play");
}