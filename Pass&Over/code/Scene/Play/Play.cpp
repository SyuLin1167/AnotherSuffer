#include<DxLib.h>

#include"../../Object/ObjManager/ObjManager.h"
#include"../../Object/Camera/Camera.h"
#include"../../Object/CharaObj/Player/Player.h"
#include"../SceneBase/SceneBase.h"
#include "Play.h"

// �R���X�g���N�^ //

Play::Play()
{
    ObjManager::AddObj(new Camera);
    ObjManager::AddObj(new Player);
}

// �f�X�g���N�^ //

Play::~Play()
{

}

// �V�[���X�V���� //

SceneBase* Play::UpdateScene(const float deltaTime)
{
    ObjManager::UpdateObj(deltaTime);
    return this;
}

// �V�[���`�揈�� //

void Play::DrawScene()
{
    ObjManager::DrawObj();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "play");
}