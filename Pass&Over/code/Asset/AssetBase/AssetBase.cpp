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
    auto iter = handle.find(handleName);
    if (iter != handle.end())
    {
        return *handle[handleName];
    }

    //見つからなかったら-1を返す
    return -1;
}