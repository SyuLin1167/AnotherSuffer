#include"../Model/Model.h"
#include "AssetManager.h"

std::unique_ptr<AssetManager> AssetManager::assetManager=nullptr;

/// <summary>
/// アセットマネージャー初期化処理
/// </summary>
void AssetManager::InitAssetManager()
{
    //自身の中身が空だったらインスタンス生成
    if (!assetManager)
    {
        assetManager.reset(new AssetManager);
    }
}

/// <summary>
/// コンストラクタ
/// </summary>
AssetManager::AssetManager()
    :model(new Model)
{
    //処理なし
}

/// <summary>
/// デストラクタ
/// </summary>
AssetManager::~AssetManager()
{
    //処理なし
}