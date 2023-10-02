#include<DxLib.h>
#include<assert.h>

#include"../SceneBase/SceneBase.h"
#include"../../Object/ObjMgr/ObjMgr.h"
#include"../../Asset/AssetMgr/AssetMgr.h"
#include"../../TimeMgr/TimeMgr.h"
#include"../Title/Title.h"
#include "SceneMgr.h"

// �R���X�g���N�^ //

SceneMgr::SceneMgr()
    :tmpScene(nullptr)
{
    ObjMgr::InitObjMgr();
    AssetMgr::InitAssetMgr();

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
        UpdateScene();
        DrawScene();
        ChangeScene();
    }
    ObjMgr::DeleteAllObj();
}

// �V�[���X�V���� //

void SceneMgr::UpdateScene()
{
    //���݂̃V�[�����X�V����tmpScene�ɑ��
    tmpScene = nowScene.top()->UpdateScene(timeMgr->DeltaTime());
}

// �V�[���`�揈�� //

void SceneMgr::DrawScene()
{
    //���݂̃V�[����`��
    ClearDrawScreen();
    nowScene.top()->DrawScene();
    ScreenFlip();
}

// �V�[���؂�ւ����� //

void SceneMgr::ChangeScene()
{
    //nowScene��tmpScene�ƈقȂ��Ă����������đ��
    if (nowScene.top().get() != tmpScene)
    {
        nowScene.pop();
        nowScene.emplace(tmpScene);

        assert(!nowScene.empty());
    }
}