#include "AssetBase.h"

// コンストラクタ //

AssetBase::AssetBase()
{

}

// デストラクタ //

AssetBase::~AssetBase()
{

}

// ハンドル取得処理 //

int AssetBase::GetHandle(std::string handleName)
{
    //取得したいハンドルが見つかったら返す
    auto iter = std::find(handle.begin(), handle.end(), handleName);
    if (iter != handle.end())
    {
        return handle[handleName];
    }

    //見つからなかったら-1を返す
    return -1;
}

// ハンドル削除処理 //

void AssetBase::DeleteHandle()
{
        handle.clear();
}