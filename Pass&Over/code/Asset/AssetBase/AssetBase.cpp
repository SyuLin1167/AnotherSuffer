#include<DxLib.h>

#include "AssetBase.h"

/// <summary>
/// コンストラクタ
/// </summary>
AssetBase::AssetBase()
    :holdHandle(-1)
    , dupHandle(-1)
    , assetType("")
    , jsonFile("")
{
    //処理なし
}

/// <summary>
/// デストラクタ
/// </summary>
AssetBase::~AssetBase()
{
    //処理なし
}

/// <summary>
/// Jsonファイル読み込み処理
/// </summary>
/// <param name="fileName"></param>
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

/// <summary>
/// ハンドル取得処理
/// </summary>
/// <param name="handleName">:ハンドル名</param>
/// <returns>ハンドル</returns>
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