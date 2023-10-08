#include<DxLib.h>
#include<assert.h>

#include"../SceneBase/SceneBase.h"
#include"../../Object/ObjManager/ObjManager.h"
#include"../../Asset/AssetMgr/AssetMgr.h"
#include"../../FPS/FPS.h"
#include"../Title/Title.h"
#include "SceneMgr.h"

// �R���X�g���N�^ //

SceneMgr::SceneMgr()
    :holdScene(nullptr)
{
    ObjManager::InitObjManager();
    AssetMgr::InitAssetMgr();

    fps.reset(new FPS);
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
        ChangeScene();
        DrawScene();
    }
    ObjManager::DeleteAllObj();
}

// �V�[���X�V���� //

void SceneMgr::UpdateScene()
{
    //���݂̃V�[�����X�V����tmpScene�ɑ��
    fps->Update();
    holdScene=nowScene.top()->UpdateScene(fps->GetDeltaTime());
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
    if (nowScene.top().get() != holdScene)
    {
        nowScene.pop();
        nowScene.emplace(holdScene);

        assert(!nowScene.empty());
    }
}