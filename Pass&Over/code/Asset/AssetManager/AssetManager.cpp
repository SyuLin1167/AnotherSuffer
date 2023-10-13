#include"../Model/Model.h"
#include "AssetManager.h"

std::unique_ptr<AssetManager> AssetManager::assetManager=nullptr;

void AssetManager::InitAssetManager()
{
    //���g�̒��g���󂾂�����C���X�^���X����
    if (!assetManager)
    {
        assetManager.reset(new AssetManager);
    }
}

AssetManager::AssetManager()
    :model(new Model)
{
    //�����Ȃ�
}

AssetManager::~AssetManager()
{
    //�����Ȃ�
}