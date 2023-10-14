#include"../Model/Model.h"
#include"../Sound/Sound.h"
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
    , sound(new Sound)
{
    //�����Ȃ�
}

AssetManager::~AssetManager()
{
    //�����Ȃ�
}