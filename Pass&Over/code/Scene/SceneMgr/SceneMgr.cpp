#include<DxLib.h>

#include"../SceneBase/SceneBase.h"
#include"../Title/Title.h"
#include "SceneMgr.h"

// �R���X�g���N�^ //

SceneMgr::SceneMgr()
    :tmpScene(nullptr)
{
    nowScene.emplace(new Title);
}

// �f�X�g���N�^ //

SceneMgr::~SceneMgr()
{
}

// �Q�[�����[�v //

void SceneMgr::GameLoop()
{
    //�E�B���h�E��������܂Ń��[�v����
    while (ProcessMessage() == 0)
    {

    }
}

// �V�[���X�V���� //

void SceneMgr::SceneUpdate()
{

}

// �V�[���`�揈�� //

void SceneMgr::SceneDraw()
{

}