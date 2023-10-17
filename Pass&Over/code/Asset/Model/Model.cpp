#include<DxLib.h>
#include<assert.h>
#include<future>

#include "Model.h"

Model::Model()
    :AssetBase()
{
    assetType = "model";

    //json�t�@�C���ǂݍ���
    jsonFile = "../code/Asset/Model/ModelData.json";
    LoadJsonFile(jsonFile);

    //�n���h���ǉ�
    for (rapidjson::Value::ConstMemberIterator objType = GetJsonData().MemberBegin();
        objType != GetJsonData().MemberEnd(); objType++)
    {
        AddHandle(objType->value.GetString());
    }
}

Model::~Model()
{
    DeleteHandle();
}

void Model::AddHandle(const std::string fileName)
{
    //���n���h��������
    holdHandle = -1;
    dupHandle = -1;

    //�t�@�C����������Ȃ�������n���h���𕡐����Ēǉ�
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
    //�n���h���ƃn���h�����m�ۂ����f�[�^���
    for (auto& iter : handle)
    {
        MV1DeleteModel(iter.second);
    }
    handle.clear();
}