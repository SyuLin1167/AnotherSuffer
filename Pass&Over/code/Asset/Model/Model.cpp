#include<DxLib.h>
#include<assert.h>
#include<future>

#include "Model.h"

Model::Model()
    :AssetBase()
{
    assetType = "model";

    //jsonファイル読み込み
    jsonFile = "../code/Asset/Model/ModelData.json";
    LoadJsonFile(jsonFile);

    //ハンドル追加
    auto& data = GetJsonData();
    AddHandle(data["player"].GetString());
}

Model::~Model()
{
    //処理なし
}

void Model::AddHandle(const std::string fileName)
{
    //仮ハンドル初期化
    holdHandle = -1;
    dupHandle = -1;

    //ファイルが見つからなかったらハンドルを複製して追加
    auto iter = handle.find(fileName);
    if (iter == handle.end())
    {
            holdHandle = MV1LoadModel(fileName.c_str());
            dupHandle = MV1DuplicateModel(holdHandle);
            handle.emplace(fileName, dupHandle);
    }
}

void Model::DeleteHandle()
{
    for (auto& iter : handle)
    {
        MV1DeleteModel(iter.second);
    }
    handle.clear();
}