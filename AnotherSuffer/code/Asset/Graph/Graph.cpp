#include<DxLib.h>
#include<future>

#include "Graph.h"

Graph::Graph()
    :AssetBase()
{
    //jsonファイル読み込み
    jsonFile = "../json/GraphData.json";
    LoadJsonFile(jsonFile);

    //オブジェクト分ハンドル追加
    for (rapidjson::Value::ConstMemberIterator objType = GetJsonData().MemberBegin();
        objType != GetJsonData().MemberEnd(); objType++)
    {
        for (rapidjson::Value::ConstMemberIterator graphType = objType->value.MemberBegin();
            graphType != objType->value.MemberEnd(); graphType++)
        {
            AddHandle(graphType->value.GetString());
        }
    }
}

Graph::~Graph()
{
    DeleteHandle();
}

void Graph::AddHandle(const std::string fileName)
{
    //仮ハンドル初期化
    holdHandle = -1;

    //ファイルが見つからなかったらハンドルを複製して追加
    auto iter = handle.find(fileName);
    if (iter == handle.end())
    {
        holdHandle = LoadGraph(fileName.c_str());
        handle.emplace(fileName, holdHandle);
    }
}

void Graph::DeleteHandle()
{
    //ハンドルとデータ解放
    for (auto& iter : handle)
    {
        DeleteGraph(iter.second);
    }
    handle.clear();
}
