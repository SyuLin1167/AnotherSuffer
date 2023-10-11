#include"../Model/Model.h"
#include "AssetManager.h"

std::unique_ptr<AssetManager> AssetManager::assetManager=nullptr;

/// <summary>
/// �A�Z�b�g�}�l�[�W���[����������
/// </summary>
void AssetManager::InitAssetManager()
{
    //���g�̒��g���󂾂�����C���X�^���X����
    if (!assetManager)
    {
        assetManager.reset(new AssetManager);
    }
}

/// <summary>
/// �R���X�g���N�^
/// </summary>
AssetManager::AssetManager()
    :model(new Model)
{
    //�����Ȃ�
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
AssetManager::~AssetManager()
{
    //�����Ȃ�
}