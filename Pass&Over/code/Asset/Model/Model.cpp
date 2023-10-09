#include<DxLib.h>
#include<assert.h>

#include "Model.h"
// �R���X�g���N�^ //

Model::Model()
    :AssetBase()
    , holdHandle(-1)
    , dupHandle(-1)
{
    assetType = "model";

    //json�t�@�C���ǂݍ���
    jsonFile = "../code/Asset/Model/ModelData.json";
    LoadJsonFile(jsonFile);

    //�n���h���ǉ�
    auto& data = GetJsonData();
    AddHandle(data["player"].GetString());

}

// �f�X�g���N�^ //

Model::~Model()
{
    //�����Ȃ�
}

// �n���h���ǉ����� //

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

// �n���h���폜���� //

void Model::DeleteHandle()
{
    for (auto& iter : handle)
    {
        MV1DeleteModel(iter.second);
    }
    handle.clear();
}