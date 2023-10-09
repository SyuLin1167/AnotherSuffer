#include"../Model/Model.h"
#include "AssetManager.h"

std::unique_ptr<AssetManager> AssetManager::assetManager=nullptr;

// アセットマネージャー初期化処理 //

void AssetManager::InitAssetManager()
{
    //自身の中身が空だったらインスタンス生成
    if (!assetManager)
    {
        assetManager.reset(new AssetManager);
    }
}

// コンストラクタ //

AssetManager::AssetManager()
    :model(new Model)
{
    //処理なし
}

// デストラクタ //

AssetManager::~AssetManager()
{
    //処理なし
}