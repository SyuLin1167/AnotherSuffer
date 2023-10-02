#include "AssetBase.h"

// コンストラクタ //

AssetBase::AssetBase()
    :jsonFile("")
{
}

// デストラクタ //

AssetBase::~AssetBase()
{

}

// Jsonファイル読み込み処理 //

rapidjson::Value& AssetBase::LoadJsonFile(std::string fileName)
{
    //ファイル読み込み
    std::ifstream ifs(fileName.c_str());
    rapidjson::Document doc;

    //ファイル解析
    if (ifs.good())
    {
        rapidjson::IStreamWrapper isw(ifs);

        doc.ParseStream(isw);
    }
    ifs.close();

    auto& value = doc;
    return value;
}

// ハンドル取得処理 //

const int AssetBase::GetHandle(std::string handleName)
{
    //取得したいハンドルが見つかったら返す
    auto iter = handle.find(handleName);
    if (iter != handle.end())
    {
        return handle[handleName];
    }

    //見つからなかったら-1を返す
    return -1;
}