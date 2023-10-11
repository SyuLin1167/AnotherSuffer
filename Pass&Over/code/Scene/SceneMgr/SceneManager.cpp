#include<DxLib.h>
#include<assert.h>

#include"../SceneBase/SceneBase.h"
#include"../../Object/ObjManager/ObjManager.h"
#include"../../Asset/AssetManager/AssetManager.h"
#include"../../FPS/FPS.h"
#include"../Title/Title.h"
#include "SceneManager.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
SceneManager::SceneManager()
    :holdScene(nullptr)
    , fps(new FPS)
{
    ObjManager::InitObjManager();
    AssetManager::InitAssetManager();

    nowScene.emplace(new Title);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
SceneManager::~SceneManager()
{
}

/// <summary>
/// �Q�[�����[�v
/// </summary>
void SceneManager::GameLoop()
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

/// <summary>
/// �V�[���X�V����
/// </summary>
void SceneManager::UpdateScene()
{
    //���݂̃V�[�����X�V����tmpScene�ɑ��
    fps->Update();
    holdScene=nowScene.top()->UpdateScene(fps->GetDeltaTime());
}

/// <summary>
/// �V�[���`�揈��
/// </summary>
void SceneManager::DrawScene()
{
    //���݂̃V�[����`��
    ClearDrawScreen();
    nowScene.top()->DrawScene();
    DrawFormatString(0, 100, GetColor(255, 255, 255), "�񓯊��ǂݍ��݂̐� %d", GetASyncLoadNum());
    ScreenFlip();
}

/// <summary>
/// �V�[���؂�ւ�����
/// </summary>
void SceneManager::ChangeScene()
{
    //nowScene��tmpScene�ƈقȂ��Ă����������đ��
    if (nowScene.top().get() != holdScene)
    {
        nowScene.pop();
        nowScene.emplace(holdScene);

        assert(!nowScene.empty());
    }
}