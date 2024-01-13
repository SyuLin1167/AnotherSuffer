#include<DxLib.h>

#include "AssetManager.h"

std::unique_ptr<AssetManager> AssetManager::singleton;

void AssetManager::InitAssetManager()
{
    //自身の中身が空だったらインスタンス生成
    if (!singleton)
    {
        SetUseASyncLoadFlag(true);
        singleton.reset(new AssetManager);
        SetUseASyncLoadFlag(false);
    }
}

AssetManager::AssetManager()
    :graph(new Graph)
    , model(new Model)
    , motion(new Motion(model.get()))
    , sound(new Sound)
{
    //処理なし
}

AssetManager::~AssetManager()
{
    //処理なし
}