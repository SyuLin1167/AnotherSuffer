#include"../Model/Model.h"
#include"../Motion/Motion.h"
#include"../Sound/Sound.h"
#include "AssetManager.h"

std::unique_ptr<AssetManager> AssetManager::assetManager=nullptr;

void AssetManager::InitAssetManager()
{
    //自身の中身が空だったらインスタンス生成
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
    //処理なし
}

AssetManager::~AssetManager()
{
    //処理なし
}

Motion* AssetManager::MotoinInstance()
{
    if (!assetManager->motion)
    {
        assetManager->motion.reset(new Motion);
    }
    return assetManager->motion.get();
}