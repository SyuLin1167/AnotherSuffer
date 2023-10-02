#include"../Model/Model.h"
#include "AssetMgr.h"

std::unique_ptr<AssetMgr> AssetMgr::assetMgr;

// アセットマネージャー初期化処理 //

void AssetMgr::InitAssetMgr()
{
    //自身の中身が空だったらインスタンス生成
    if (!assetMgr)
    {
        assetMgr.reset(new AssetMgr);
    }
}

// コンストラクタ //

AssetMgr::AssetMgr()
{
    model.reset(new Model);
}

// デストラクタ //

AssetMgr::~AssetMgr()
{

}