#include<DxLib.h>

#include "Model.h"

// コンストラクタ //

Model::Model()
    :AssetBase()
    , tmpHandle(-1)
    , dupHandle(-1)
    , dataFile("../assets/Chara/Player/Player.mv1")
{
    std::ifstream ifs(dataFile.c_str());
    rapidjson::Document doc;
    if (ifs.good())
    {
        rapidjson::IStreamWrapper isw(ifs);

        doc.ParseStream(isw);
    }
    ifs.close();
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