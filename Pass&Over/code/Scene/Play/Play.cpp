#include<DxLib.h>

#include"../SceneBase/SceneBase.h"
#include "Play.h"

// �R���X�g���N�^ //

Play::Play()
{

}

// �f�X�g���N�^ //

Play::~Play()
{

}

// �V�[���X�V���� //

SceneBase* Play::UpdateScene(const float deltaTime)
{
    return this;
}

// �V�[���`�揈�� //

void Play::DrawScene()
{
    DrawFormatString(0, 0, GetColor(255, 255, 255), "play");
}