#include<DxLib.h>

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
        SetUseASyncLoadFlag(true);
        assetManager.reset(new AssetManager);
        SetUseASyncLoadFlag(false);
    }
}

AssetManager::AssetManager()
    :model(new Model)
    , motion(new Motion(model.get()))
    , sound(new Sound)
{
    //処理なし
}

AssetManager::~AssetManager()
{
    //ハンドル削除
    model->DeleteHandle();
    motion->DeleteHandle();
    sound->DeleteHandle();
}