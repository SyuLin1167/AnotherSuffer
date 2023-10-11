#include<DxLib.h>
#include<assert.h>
#include<future>

#include "Model.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Model::Model()
    :AssetBase()
{
    assetType = "model";

    //json�t�@�C���ǂݍ���
    jsonFile = "../code/Asset/Model/ModelData.json";
    LoadJsonFile(jsonFile);

    //�n���h���ǉ�
    auto& data = GetJsonData();
    AddHandle(data["player"].GetString());
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Model::~Model()
{
    //�����Ȃ�
}

/// <summary>
/// �n���h���ǉ�����
/// </summary>
/// <param name="fileName">:�t�@�C����</param>
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

/// <summary>
/// �n���h���폜����
/// </summary>
void Model::DeleteHandle()
{
    for (auto& iter : handle)
    {
        MV1DeleteModel(iter.second);
    }
    handle.clear();
}