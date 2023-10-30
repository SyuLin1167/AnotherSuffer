#include"../Model/Model.h"
#include"../Motion/Motion.h"
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
    , motion(nullptr)
    , sound(new Sound)
{
    //�����Ȃ�
}

AssetManager::~AssetManager()
{
    //�����Ȃ�
}

Motion* AssetManager::MotoinInstance()
{
    if (!assetManager->motion)
    {
        assetManager->motion.reset(new Motion);
    }
    return assetManager->motion.get();
}