#include<DxLib.h>

#include "AssetBase.h"

AssetBase::AssetBase()
    :holdHandle(-1)
    , dupHandle(-1)
    , assetType("")
    , jsonFile("")
{
    //処理なし
}

AssetBase::~AssetBase()
{
    //処理なし
}

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