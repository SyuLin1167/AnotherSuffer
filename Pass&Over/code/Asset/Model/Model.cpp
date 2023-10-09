#include<DxLib.h>
#include<assert.h>

#include "Model.h"
// コンストラクタ //

Model::Model()
    :AssetBase()
    , holdHandle(-1)
    , dupHandle(-1)
{
    assetType = "model";

    //jsonファイル読み込み
    jsonFile = "../code/Asset/Model/ModelData.json";
    LoadJsonFile(jsonFile);

    //ハンドル追加
    auto& data = GetJsonData();
    AddHandle(data["player"].GetString());

}

// デストラクタ //

Model::~Model()
{
    //処理なし
}

// ハンドル追加処理 //

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

// ハンドル削除処理 //

void Model::DeleteHandle()
{
    for (auto& iter : handle)
    {
        MV1DeleteModel(iter.second);
    }
    handle.clear();
}