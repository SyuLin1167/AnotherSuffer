#include<DxLib.h>

#include "AssetBase.h"

// コンストラクタ //

AssetBase::AssetBase()
    :assetType("")
    , jsonFile("")
{
}

// デストラクタ //

AssetBase::~AssetBase()
{

}

// Jsonファイル読み込み処理 //

void AssetBase::LoadJsonFile(std::string fileName)
{
    //ファイル読み込み
    std::ifstream ifs(fileName.c_str());

    //ファイル解析
    if (ifs.good())
    {
        rapidjson::IStreamWrapper isw(ifs);

        doc.ParseStream(isw);
    }
    ifs.close();
}

// ハンドル取得処理 //

const int AssetBase::GetHandle(std::string handleName)
{
    //取得したいハンドルが見つかったら返す
    auto iter = handle.find(handleName);
    if (iter != handle.end())
    {
        if (!CheckHandleASyncLoad(handle[handleName]))
        {
            return handle[handleName];
        }
    }

    //返せなかったら-1を返す
    return -1;
}