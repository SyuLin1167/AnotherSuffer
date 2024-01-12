#include<DxLib.h>
#include<future>

#include "Graph.h"

Graph::Graph()
    :AssetBase()
{
    //json�t�@�C���ǂݍ���
    jsonFile = "../json/ModelData.json";
    LoadJsonFile(jsonFile);

    //�I�u�W�F�N�g���n���h���ǉ�
    for (rapidjson::Value::ConstMemberIterator objType = GetJsonData().MemberBegin();
        objType != GetJsonData().MemberEnd(); objType++)
    {
        AddHandle(objType->value.GetString());
    }
}

Graph::~Graph()
{
    //�����Ȃ�
}

void Graph::AddHandle(const std::string fileName)
{
    //���n���h��������
    holdHandle = -1;

    //�t�@�C����������Ȃ�������n���h���𕡐����Ēǉ�
    auto iter = handle.find(fileName);
    if (iter == handle.end())
    {
        holdHandle = LoadGraph(fileName.c_str());
        handle.emplace(fileName, holdHandle);
    }
}

void Graph::DeleteHandle()
{
    //�n���h���ƃf�[�^���
    for (auto& iter : handle)
    {
        DeleteGraph(iter.second);
    }
    handle.clear();
}
