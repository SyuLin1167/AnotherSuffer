#include<DxLib.h>

#include "Model.h"

// �R���X�g���N�^ //

Model::Model()
    :AssetBase()
    , tmpHandle(-1)
    , dupHandle(-1)
    , dataFile("../code/Asset/Model/ModelData.json")
{
    data = LoadJsonFile(dataFile)["model"];
    AddHandle(data["player"].GetString());
}

// �f�X�g���N�^ //

Model::~Model()
{
}

// �n���h���ǉ����� //

void Model::AddHandle(std::string fileName)
{
    //�n���h��������
    tmpHandle = -1;
    dupHandle = -1;

    //�t�@�C����������Ȃ�������n���h���𕡐����Ēǉ�
    auto iter = handle.find(fileName);
    if (iter == handle.end())
    {
        tmpHandle = MV1LoadModel(fileName.c_str());
        dupHandle = MV1DuplicateModel(tmpHandle);
        MV1DeleteModel(tmpHandle);
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