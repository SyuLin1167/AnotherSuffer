#include<DxLib.h>

#include "Model.h"

// �R���X�g���N�^ //

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