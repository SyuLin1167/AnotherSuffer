#include"../Model/Model.h"
#include "AssetManager.h"

std::unique_ptr<AssetManager> AssetManager::assetManager=nullptr;

// �A�Z�b�g�}�l�[�W���[���������� //

void AssetManager::InitAssetManager()
{
    //���g�̒��g���󂾂�����C���X�^���X����
    if (!assetManager)
    {
        assetManager.reset(new AssetManager);
    }
}

// �R���X�g���N�^ //

AssetManager::AssetManager()
    :model(new Model)
{
    //�����Ȃ�
}

// �f�X�g���N�^ //

AssetManager::~AssetManager()
{
    //�����Ȃ�
}