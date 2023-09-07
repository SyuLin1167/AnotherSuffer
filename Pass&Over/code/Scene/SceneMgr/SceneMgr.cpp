#include<DxLib.h>
#include<assert.h>

#include"../SceneBase/SceneBase.h"
#include"../../TimeMgr/TimeMgr.h"
#include"../Title/Title.h"
#include "SceneMgr.h"

// �R���X�g���N�^ //

SceneMgr::SceneMgr()
    :tmpScene(nullptr)
{
    timeMgr.reset(new TimeMgr);
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
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //�V�[���̃t���[
        SceneUpdate();
        SceneDraw();
        SceneChange();
    }
}

// �V�[���X�V���� //

void SceneMgr::SceneUpdate()
{
    //���݂̃V�[�����X�V����tmpScene�ɑ��
    tmpScene = nowScene.top()->SceneUpdate(timeMgr->DeltaTime());
}

// �V�[���`�揈�� //

void SceneMgr::SceneDraw()
{
    //���݂̃V�[����`��
    ClearDrawScreen();
    nowScene.top()->SceneDraw();
    ScreenFlip();
}

// �V�[���؂�ւ����� //

void SceneMgr::SceneChange()
{
    //nowScene��tmpScene�ƈقȂ��Ă����������đ��
    if (nowScene.top().get() != tmpScene)
    {
        nowScene.pop();
        nowScene.emplace(tmpScene);

        assert(!nowScene.empty());
    }
}