#include"../Model/Model.h"
#include "AssetMgr.h"

// コンストラクタ //

AssetMgr::AssetMgr()
{
    model.reset(new Model);
}

// デストラクタ //

AssetMgr::~AssetMgr()
{

}