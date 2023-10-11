#include<DxLib.h>

#include"../../Object/ObjManager/ObjManager.h"
#include"../../Object/Camera/Camera.h"
#include"../../Object/CharaObj/Player/Player.h"
#include"../SceneBase/SceneBase.h"
#include "Play.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Play::Play()
{
    ObjManager::AddObj(new Camera);
    ObjManager::AddObj(new Player);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Play::~Play()
{

}

/// <summary>
/// �V�[���X�V����
/// </summary>
/// <param name="deltaTime">:�t���[�����[�g</param>
/// <returns>���t���[���̃V�[��</returns>
SceneBase* Play::UpdateScene(const float deltaTime)
{
    ObjManager::UpdateObj(deltaTime);
    return this;
}

/// <summary>
/// �V�[���`�揈��
/// </summary>
void Play::DrawScene()
{
    ObjManager::DrawObj();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "play");
}