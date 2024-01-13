#include<DxLib.h>

#include"../SceneBase/SceneBase.h"
#include"../../Object/ObjManager/ObjManager.h"
#include"../../Asset/AssetManager/AssetManager.h"
#include"../../Collision/CollisionManager/CollisionManager.h"
#include"../../FPS/FPS.h"
#include"../../KeyStatus/KeyStatus.h"
#include"../Title/Title.h"
#include "SceneManager.h"

std::unique_ptr<SceneManager> SceneManager::singleton = nullptr;

void SceneManager::InitSceneManager()
{
    //�C���X�^���X������
    if (!singleton)
    {
        singleton.reset(new SceneManager);
    }
}

SceneManager::SceneManager()
    :holdScene(nullptr)
{
    //�Ǘ��N���X�ޏ�����
    FPS::InitFPS();
    KeyStatus::InitKeyStatus();
    ObjManager::InitObjManager();
    AssetManager::InitAssetManager();
    CollisionManager::InitColManager();

    //�����V�[���ݒ�
    nowScene.emplace(new Title);
}

SceneManager::~SceneManager()
{
    //�����Ȃ�
}

void SceneManager::GameLoop()
{
    //�E�B���h�E��������܂Ń��[�v����
    while (!ProcessMessage() && !KeyStatus::KeyStateDecision(KEY_INPUT_ESCAPE, ONINPUT))
    {
        //�V�[���̃t���[
        UpdateScene();
        ChangeScene();
        DrawScene();
    }
    ObjManager::DeleteAllObj();
}

void SceneManager::UpdateScene()
{
    //���݂̃V�[�����X�V����tmpScene�ɑ��
    FPS::Update();
    singleton->holdScene = singleton->nowScene.top()->UpdateScene(FPS::GetDeltaTime());
}

void SceneManager::DrawScene()
{
    //���݂̃V�[����`��
    ClearDrawScreen();
    singleton->nowScene.top()->DrawScene();
    ScreenFlip();
}

void SceneManager::ChangeScene()
{
    //nowScene��tmpScene�ƈقȂ��Ă����������đ��
    if (singleton->nowScene.top().get() != singleton->holdScene)
    {
        singleton->nowScene.pop();
        singleton->nowScene.emplace(singleton->holdScene);
    }
}