#include<DxLib.h>

#include "Model.h"

// コンストラクタ //

Model::Model()
    :AssetBase()
    , tmpHandle(-1)
    , dupHandle(-1)
    , dataFile("../code/Asset/Model/ModelData.json")
{
    data = LoadJsonFile(dataFile)["model"];
    AddHandle(data["player"].GetString());
}

// デストラクタ //

Model::~Model()
{
}

// ハンドル追加処理 //

void Model::AddHandle(std::string fileName)
{
    //ハンドル初期化
    tmpHandle = -1;
    dupHandle = -1;

    //ファイルが見つからなかったらハンドルを複製して追加
    auto iter = handle.find(fileName);
    if (iter == handle.end())
    {
        tmpHandle = MV1LoadModel(fileName.c_str());
        dupHandle = MV1DuplicateModel(tmpHandle);
        MV1DeleteModel(tmpHandle);
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